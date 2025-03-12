<script setup>
import { ref, onMounted } from 'vue';
import { FwbCard } from 'flowbite-vue'
import DeviceSelector from "../components/DeviceSelector.vue"
import OSSelector from '../components/OSSelector.vue';
import USBSelector from '../components/USBSelector.vue';
const step = ref(1)
</script>

<template>
    <fwb-card>
      <div class="p-5 h-80 w-80">
        <h5 class="mb-2 text-2xl font-bold tracking-tight text-gray-900 dark:text-white">
          Seeed SDK Manager
        </h5>
        <p class="font-normal text-gray-700 dark:text-gray-400">
          Select your device to begin.
        </p>
      </div>
    </fwb-card>
</template>

<style scoped>

</style>