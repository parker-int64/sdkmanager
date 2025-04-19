<!-- Host Configuration Component -->

<script setup>
import { onMounted, ref, warn } from 'vue';
import {
  FwbCard, FwbSelect, FwbA, FwbButton, FwbModal, FwbTable,
  FwbTableBody,
  FwbTableCell,
  FwbTableHead,
  FwbTableHeadCell,
  FwbTableRow,
} from 'flowbite-vue'
import { wslManager, waitForQWebChannel } from '../main';
import router from '../router/router';
const selectedWSLDistro = ref('')

const wslDistros = ref([])

/**
 * Qt Related
 */

const wslInfoDisplay = ref(null)
const wslVersionMajor = ref(null)

const refreshWSLInfo = () => {
  wslManager.getWSLInfo()
  console.log("Refresh WSL info...")
}
const refreshWSLDistros = () => {
  wslManager.getWSLDistro()
  console.log("Refresh WSL info...")
}


const parseWSLInfo = (obj) => {
  if (Object.keys(obj).length !== 0) {
    wslInfoDisplay.value = obj
    const key = Object.keys(obj).find(k => /^WSL\s+[^gG]/.test(k))
    const value = key ? obj[key] : null
    if (value !== null) {
      wslVersionMajor.value = value.split(".")[0]
      console.log(`Get WSL Version ${value}, Major: ${wslVersionMajor.value}`)
      if (wslVersionMajor.value !== "2") {
        const errStr = `Getting WSL version ${value} with major version ${wslVersionMajor.value}, which is incompatible.`
        router.push(`/error/${errStr}`)
      }
    } else {
      console.warn("Warning: Unable to read WSL version")
    }

  } else {
    wslInfoDisplay.value = null
    console.warn("Can't read wsl information from backend")
  }


}

const parseWSLDistros = (obj) => {

  if (Object.keys(obj).length === 0) {
    console.warn("No WSL distro received");
    return;
  }

  let tmp = []

  for (const key in obj) {
    tmp.push({
      value: key,
      name: obj[key]
    })
  }

  wslDistros.value = tmp // assign

}

const parseWSLError = () => {

}

/**
 * Echo a 'hello' string with selected distro
 * Also this command will activate WSL2 (Running)
 */
const runDistroHello = (event) => {
  const value = event.target.value;
  const name = event.target.name;
  wslManager.runDistroHello();
  console.log(`WSL Distro Selected: ${value}. Calling distro...`)
}



const setupWSLSignals = () => {
  wslManager.wslInfoReceived.connect((obj) => {
    parseWSLInfo(obj);
    console.log("WSL Info received:", obj);
  })

  wslManager.wslDistroReceived.connect((obj) => {
    parseWSLDistros(obj);
    console.log("WSL Distro received:", obj);
  })

  wslManager.wslErrorReceived.connect((str) => {
    parseWSLError(str);
    console.error(`WSL Error Received: ${str}`);
  })

  wslManager.wslHelloReceived.connect((status) => {
    console.log(`WSL Hello Status: ${status}`)
  })
}

/**
 * WSL Modal Related
 */
const isShowModal = ref(false)

const closeModal = () => {
  isShowModal.value = false
}
const showModal = () => {
  isShowModal.value = true
}


/**
 * Some Vue Lifecycle Functions
*/
onMounted(async () => {
  await waitForQWebChannel();
  setupWSLSignals()
  wslManager.getWSLInfo()
  wslManager.getWSLDistro()

})

</script>

<template>
  <fwb-card class="mx-auto my-10 !max-w-full">
    <div class="flex">
      <div class="p-5 space-y-5">
        <h5 class="mb-2 text-2xl font-bold tracking-tight text-gray-900 dark:text-white">
          Setup Your Host Environment
        </h5>
        <p class="text-gray-700 dark:text-gray-400">
          Using WSL2 to flash the device.
        </p>

        <div class="flex space-x-2">
          <fwb-select v-model="selectedWSLDistro" :options="wslDistros" label="WSL2 Distribution"
            @change="runDistroHello">
            <template #helper>
              Learn how we utilize WSL2. Read our
              <fwb-a href="#" color="text-blue-600 dark:text-blue-500">
                Wiki
              </fwb-a>
            </template>
          </fwb-select>
        </div>
        <fwb-button size="xs" color="dark" outline pill square @click="refreshWSLDistros">
          <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="1.5"
            stroke="currentColor" class="size-3">
            <path stroke-linecap="round" stroke-linejoin="round"
              d="M16.023 9.348h4.992v-.001M2.985 19.644v-4.992m0 0h4.992m-4.993 0 3.181 3.183a8.25 8.25 0 0 0 13.803-3.7M4.031 9.865a8.25 8.25 0 0 1 13.803-3.7l3.181 3.182m0-4.991v4.99" />
          </svg>
        </fwb-button>
        <fwb-button class="ml-10" size="xs" color="dark" outline pill square @click="showModal">
          <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="1.5"
            stroke="currentColor" class="size-3">
            <path stroke-linecap="round" stroke-linejoin="round"
              d="m11.25 11.25.041-.02a.75.75 0 0 1 1.063.852l-.708 2.836a.75.75 0 0 0 1.063.853l.041-.021M21 12a9 9 0 1 1-18 0 9 9 0 0 1 18 0Zm-9-3.75h.008v.008H12V8.25Z" />
          </svg>
        </fwb-button>
      </div>
      <img class="object-scale-down w-full mx-auto h-96 md:h-auto md:w-48" src="https://placehold.co/128x128" alt="">
    </div>
  </fwb-card>

  <!-- Modal -->
  <fwb-modal v-if="isShowModal" @close="closeModal" class="overflow-y-hidden">
    <template #header>
      <div class="flex items-center text-lg text-gray-700 dark:text-white">
        WSL Information
      </div>
    </template>
    <template #body>
      <fwb-table>
        <fwb-table-head>
          <fwb-table-head-cell>Name</fwb-table-head-cell>
          <fwb-table-head-cell class="flex space-x-3 items-center justify-end">
            <p>Value</p>
            <fwb-button size="xs" color="dark" @click="refreshWSLInfo">Refresh</fwb-button>
          </fwb-table-head-cell>

        </fwb-table-head>
        <fwb-table-body>
          <fwb-table-row v-for="(value, key) in wslInfoDisplay" :key="key">
            <fwb-table-cell>{{ key }}</fwb-table-cell>
            <fwb-table-cell>{{ value }}</fwb-table-cell>
          </fwb-table-row>
        </fwb-table-body>
      </fwb-table>
    </template>
  </fwb-modal>
  <!-- End of Modal -->
</template>

<style scoped></style>