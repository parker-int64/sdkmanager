<!-- Host Configuration Component -->

<script setup>
import { ref, onMounted } from 'vue';
import { FwbCard, FwbSelect } from 'flowbite-vue'


const selectedDevice = ref('')
const jetsonDevices = [
  { value: '0', name: 'reComputer J1010' },
  { value: '1', name: 'reComputer J1020v2' },
  { value: '2', name: 'reComputer J4012' },
]

const selectedJetPack = ref('')
const jetPackVers = [
  { value: '0', name: 'JetPack 4.6.6' },
  { value: '1', name: 'JetPack 4.6.5' },
]

</script>

<template>
  <fwb-card class="mx-auto my-10 !max-w-full">
    <div class="flex">
      <div class="p-5 space-y-5">
        <h5 class="mb-2 text-2xl font-bold tracking-tight text-gray-900 dark:text-white">
          Device Configuration
        </h5>
        <p class="font-normal text-gray-700 dark:text-gray-400">
          Select your device and preferred JetPack.
        </p>


        <fwb-select v-model="selectedDevice" :options="jetsonDevices" label="Device">
        </fwb-select>
        <fwb-select v-model="selectedJetPack" :options="jetPackVers" label="JetPack">
        </fwb-select>
      </div>
      <img class="object-scale-down w-full mx-auto h-96 md:h-auto md:w-48" src="https://placehold.co/128x128" alt="">
    </div>
  </fwb-card>
</template>

<style scoped></style>