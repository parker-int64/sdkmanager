<!-- Host Configuration Component -->

<script setup>
import { ref, onMounted } from 'vue';
import { FwbCard, FwbSelect, FwbA } from 'flowbite-vue'

const selectedWSLDistro = ref('')
const wslDistros = [
  { value: '0', name: 'Ubuntu-18.04' },
  { value: '1', name: 'Ubuntu-20.04' },
  { value: '2', name: 'Ubuntu-22.04' },
]

/**
 * Qt Related
 */

const resMesg = ref("Waiting for Qt Transmission")

let wslcontroller = null

onMounted(() => {

})

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


        <fwb-select v-model="selectedWSLDistro" :options="wslDistros" label="WSL2 Distribution">
          <template #helper>
            Learn how we utilize WSL2. Read our
            <fwb-a href="#" color="text-blue-600 dark:text-blue-500">
              Wiki
            </fwb-a>
          </template>
        </fwb-select>
      </div>
      <img class="object-scale-down w-full mx-auto h-96 md:h-auto md:w-48" src="https://placehold.co/128x128" alt="">
    </div>
  </fwb-card>
</template>

<style scoped></style>