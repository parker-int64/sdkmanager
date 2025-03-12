<script setup>
import { RouterView, RouterLink } from 'vue-router';
//font
import "@fontsource/montserrat"
import { FwbImg, FwbButton } from 'flowbite-vue'
</script>

<template>
  <div id="container" class="h-full">
    <div id="content" class="h-screen flex flex-col">
      <div class="px-10 py-8 flex justify-between">
        <fwb-img
          alt="flowbite-vue"
          src="/logo.webp"
          size="max-w-xs"
        />
        <div class="justify-self-end space-x-10">
          <fwb-button pill square size="lg">
            <svg xmlns="http://www.w3.org/2000/svg" height="24px" viewBox="0 -960 960 960" fill="#FFFFFF">
              <path d="m370-80-16-128q-13-5-24.5-12T307-235l-119 50L78-375l103-78q-1-7-1-13.5v-27q0-6.5 1-13.5L78-585l110-190 119 50q11-8 23-15t24-12l16-128h220l16 128q13 5 24.5 12t22.5 15l119-50 110 190-103 78q1 7 1 13.5v27q0 6.5-2 13.5l103 78-110 190-118-50q-11 8-23 15t-24 12L590-80H370Zm70-80h79l14-106q31-8 57.5-23.5T639-327l99 41 39-68-86-65q5-14 7-29.5t2-31.5q0-16-2-31.5t-7-29.5l86-65-39-68-99 42q-22-23-48.5-38.5T533-694l-13-106h-79l-14 106q-31 8-57.5 23.5T321-633l-99-41-39 68 86 64q-5 15-7 30t-2 32q0 16 2 31t7 30l-86 65 39 68 99-42q22 23 48.5 38.5T427-266l13 106Zm42-180q58 0 99-41t41-99q0-58-41-99t-99-41q-59 0-99.5 41T342-480q0 58 40.5 99t99.5 41Zm-2-140Z"/>
            </svg>
          </fwb-button>
          <fwb-button pill square size="lg">
            <svg xmlns="http://www.w3.org/2000/svg" height="24px" viewBox="0 -960 960 960" fill="#FFFFFF">
              <path d="M424-320q0-81 14.5-116.5T500-514q41-36 62.5-62.5T584-637q0-41-27.5-68T480-732q-51 0-77.5 31T365-638l-103-44q21-64 77-111t141-47q105 0 161.5 58.5T698-641q0 50-21.5 85.5T609-475q-49 47-59.5 71.5T539-320H424Zm56 240q-33 0-56.5-23.5T400-160q0-33 23.5-56.5T480-240q33 0 56.5 23.5T560-160q0 33-23.5 56.5T480-80Z"/>
            </svg>
          </fwb-button>
        </div>
      </div>

      <div class="bg-[#8dc22b] h-full px-20">
        <router-view class="mx-auto mt-10" />
      </div>

    </div>
  </div>
</template>


<style>
html,
body {
  margin: 0;
  padding: 0;
}

body {
  font-family: "Montserrat";
}

html {
  height: 100%;
  overflow-y: auto;
}


/* cancel the default style of router */
.router-link-active {
  text-decoration: none;
  color: #474646;
}

a {
  text-decoration: none;
  color: #121212;
}
</style>
