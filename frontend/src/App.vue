<script setup>
import { RouterView, RouterLink } from 'vue-router';
//font
import "@fontsource/montserrat"

</script>

<template>
  <div id="app" class="_app">
    <q-layout view="lhr lpR lfr">
      <q-page-container>
        <router-view />
      </q-page-container>
    </q-layout>
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
