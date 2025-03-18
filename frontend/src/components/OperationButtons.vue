<script setup lang="ts">
defineProps<{
  onPrevBtnClicked: any;
  onNextBtnClicked: any;
  onFlashBtnClicked: any;
}>()
const curFlashStep = defineModel<any>('curFlashStep', { required: true })
import { FwbButton } from 'flowbite-vue'
</script>

<template>
  <div class="flex justify-between w-full">
    <fwb-button color="dark" v-if="curFlashStep !== 1" @click="onPrevBtnClicked">PREV</fwb-button>
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
</template>
