<script setup>
import { onMounted } from 'vue'
import { FwbButton } from 'flowbite-vue'
import { useRoute } from 'vue-router';

import { appController, waitForQWebChannel } from '../main';

const route = useRoute()

const restartApp = () => {
  appController.restartApp()
}

const closeApp = () => {
  appController.closeApp()
}

/**
 * Some Vue Lifecycle Functions
*/
onMounted(async () => {
  await waitForQWebChannel()
})

</script>

<template>
  <section class="bg-white dark:bg-gray-900">
    <div class="py-8 px-4 mx-auto max-w-screen-xl lg:py-16 lg:px-6">
      <div class="mx-auto max-w-screen-sm text-center spae-y-10">
        <h1 class="mb-4 text-7xl tracking-tight font-extrabold lg:text-9xl text-primary-600 dark:text-white">Error
        </h1>
        <p class="mb-4 text-3xl tracking-tight font-bold text-gray-900 md:text-4xl dark:text-white">Something's missing.
        </p>
        <p class="mb-4 text-lg font-light text-gray-500 dark:text-gray-400">Either the requirements were not met, or
          program crashed.</p>
        <p class="mb-4 text-lg font-light text-gray-500 dark:text-gray-400">{{ route.params.errStr }}</p>
        <div class="flex justify-between">
          <fwb-button color="dark" outline @click="restartApp">Restart Application</fwb-button>
          <fwb-button color="dark" @click="closeApp">Quit</fwb-button>
        </div>
      </div>
    </div>
  </section>
</template>



<style scoped></style>