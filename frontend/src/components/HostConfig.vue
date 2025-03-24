<!-- Host Configuration Component -->

<script setup>
import { ref, onMounted } from 'vue';
import { FwbCard, FwbSelect, FwbA, FwbButton } from 'flowbite-vue'
import { qwebchannel } from "../main"
const selectedWSLDistro = ref('')
const wslDistros = [
  { value: '0', name: 'Ubuntu-18.04' },
  { value: '1', name: 'Ubuntu-20.04' },
  { value: '2', name: 'Ubuntu-22.04' },
]

/**
 * Qt Related
 */
const checkWSLInstall = () => {
  console.log(`Calling Qt Backend, emitting wslStarted.`)
  console.log(window.qwebchannel.objects.wslmanager)
  window.qwebchannel.objects.wslmanager.checkWSLVer()
}


</script>

<template>
  <fwb-card class="mx-auto my-10">
    <div class="flex">
      <div class="p-5 space-y-5">
        <h5 class="mb-2 text-2xl font-bold tracking-tight text-gray-900 dark:text-white">
          Setup Your Host Environment
        </h5>
        <p class="font-normal text-gray-700 dark:text-gray-400">
          Using WSL2 to flash the device.
        </p>

        <div class="flex space-x-2">
          <fwb-select v-model="selectedWSLDistro" :options="wslDistros" label="WSL2 Distribution">
            <template #helper>
              Learn how we utilize WSL2. Read our
              <fwb-a href="#" color="text-blue-600 dark:text-blue-500">
                Wiki
              </fwb-a>
            </template>
          </fwb-select>
          <fwb-button class="self-center" size="xs" color="dark" outline pill square @click="checkWSLInstall">
            <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" stroke-width="1.5"
              stroke="currentColor" class="size-3">
              <path stroke-linecap="round" stroke-linejoin="round"
                d="M16.023 9.348h4.992v-.001M2.985 19.644v-4.992m0 0h4.992m-4.993 0 3.181 3.183a8.25 8.25 0 0 0 13.803-3.7M4.031 9.865a8.25 8.25 0 0 1 13.803-3.7l3.181 3.182m0-4.991v4.99" />
            </svg>
          </fwb-button>
        </div>
      </div>
      <img class="object-scale-down w-full mx-auto h-96 md:h-auto md:w-48" src="https://placehold.co/128x128" alt="">
    </div>
  </fwb-card>
</template>

<style scoped></style>