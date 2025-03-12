<script setup>
import { RouterView, RouterLink } from 'vue-router';
//font
import "@fontsource/montserrat"
</script>

<template>
  <div id="container" class="h-full">
    <div id="content" class="h-screen flex flex-col pt-10 px-10 space-y-10">
      <router-view />
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

._app {
  background-color: #fafaee;
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
