<!-- Device Selector Component -->

<script setup>
import { ref, onMounted } from 'vue';
import { FwbCard, FwbSelect } from 'flowbite-vue'


const selectedDevice = ref('')
const jetsonDevices = [
  { value: '0', name: 'reComputer J1010' },
  { value: '1', name: 'reComputer J1020v2' },
]
</script>

<template>
  <fwb-card class="mx-auto my-10">
    <div class="p-5 space-y-5">
      <h5 class="mb-2 text-2xl font-bold tracking-tight text-gray-900 dark:text-white">
        Select your device
      </h5>
      <p class="font-normal text-gray-700 dark:text-gray-400">
        We have supported for many devices.
      </p>
      <fwb-select v-model="selectedDevice" :options="jetsonDevices" label="Device Full Name" />

      <fwb-select v-model="selected" :options="jetsonDevices" label="JetPack" />
    </div>
  </fwb-card>
</template>

<style scoped></style>