<script setup>
import { ref, onMounted } from 'vue';
import DeviceConfig from "../components/DeviceConfig.vue"
import USBSelector from '../components/USBSelector.vue';
import HostConfig from '../components/HostConfig.vue';


import Stepper from '../components/Stepper.vue'
import OperationButtons from '../components/OperationButtons.vue'

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

      <OperationButtons :onPrevBtnClicked="onPrevBtnClicked" :onNextBtnClicked="onNextBtnClicked"
        :onFlashBtnClicked="onFlashBtnClicked" v-model:curFlashStep="curFlashStep" />
    </div>
  </div>
</template>

<style scoped></style>