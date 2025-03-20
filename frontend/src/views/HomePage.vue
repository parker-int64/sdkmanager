<script setup>
import { ref, onMounted } from 'vue';
import DeviceConfig from "../components/DeviceConfig.vue"
import USBSelector from '../components/USBSelector.vue';
import HostConfig from '../components/HostConfig.vue';


import Stepper from '../components/Stepper.vue'
import OperationButtons from '../components/OperationButtons.vue'

import { FwbButton } from 'flowbite-vue';

// Mainly we have 3 big steps to flash a device
// Set current flash step to one by default
// Q: How to we prevent press 'CRTL' + 'R'?
const curFlashStep = ref(1)


// Handle the button event.
// On "PREV" button clicked
const onPrevBtnClicked = () => {
  curFlashStep.value = Math.max(1, curFlashStep.value - 1)
}

// Handle the button event
// On "NEXT" button clicked
const onNextBtnClicked = () => {
  curFlashStep.value = Math.min(3, curFlashStep.value + 1)
}

/* Handle Flash Button Event
 * @param
 * @ret
*/
const onFlashBtnClicked = () => {

}


</script>

<template>
  <div class="flex flex-col">
    <div class="self-center px-8 py-4 w-full max-w-xl md:space-y-8 lg:space-y-16">
      <Stepper v-model:curFlashStep="curFlashStep" />

      <HostConfig v-if="curFlashStep === 1" class="!max-w-full" />
      <DeviceConfig v-else-if="curFlashStep === 2" class="!max-w-full" />
      <USBSelector v-else class="!max-w-full" />



      <!-- <OperationButtons :onPrevBtnClicked="onPrevBtnClicked" :onNextBtnClicked="onNextBtnClicked"
        :onFlashBtnClicked="onFlashBtnClicked" v-model:curFlashStep="curFlashStep" /> -->
    </div>
  </div>

  <div class="relative w-full h-12 px-8">
    <div class="absolute right-0 bottom-0 space-x-10">
      <fwb-button color="dark" outline v-if="curFlashStep !== 1" @click="onPrevBtnClicked">PREV</fwb-button>
      <fwb-button color="dark" v-if="curFlashStep === 1 || curFlashStep === 2" class="ml-auto"
        @click="onNextBtnClicked">NEXT
        <template #suffix>
          <svg class="w-5 h-5" fill="currentColor" viewBox="0 0 20 20" xmlns="http://www.w3.org/2000/svg">
            <path clip-rule="evenodd"
              d="M10.293 3.293a1 1 0 011.414 0l6 6a1 1 0 010 1.414l-6 6a1 1 0 01-1.414-1.414L14.586 11H3a1 1 0 110-2h11.586l-4.293-4.293a1 1 0 010-1.414z"
              fill-rule="evenodd" />
          </svg>
        </template>
      </fwb-button>
      <fwb-button color="dark" v-else-if="curFlashStep === 3" class="ml-auto" @click="onFlashBtnClicked">FLASH
        <template #suffix>
          <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="currentColor" class="w-5 h-5">
            <path fill-rule="evenodd"
              d="M14.615 1.595a.75.75 0 0 1 .359.852L12.982 9.75h7.268a.75.75 0 0 1 .548 1.262l-10.5 11.25a.75.75 0 0 1-1.272-.71l1.992-7.302H3.75a.75.75 0 0 1-.548-1.262l10.5-11.25a.75.75 0 0 1 .913-.143Z"
              clip-rule="evenodd" />
          </svg>
        </template>
      </fwb-button>
    </div>
  </div>
</template>

<style scoped></style>