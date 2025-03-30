<script setup>
import { RouterView, RouterLink } from 'vue-router';

import { ref, onMounted, watch } from 'vue';
import AppHeader from './components/AppHeader.vue'

// For some vue component, you might need this ref to control dark mode.
const getPreferredTheme = () => {
  return window.matchMedia('(prefers-color-scheme: dark)').matches ? 'dark' : 'light';
};
const storedTheme = localStorage.getItem('color-theme') ?? getPreferredTheme();
const isDarkMode = ref(storedTheme)

const toggleDarkMode = () => {

  // if set via local storage previously
  if (localStorage.getItem('color-theme')) {
    if (localStorage.getItem('color-theme') === 'light') {
      document.documentElement.classList.add('dark')
      localStorage.setItem('color-theme', 'dark')
      isDarkMode.value = 'dark'
    } else {
      document.documentElement.classList.remove('dark')
      localStorage.setItem('color-theme', 'light')
      isDarkMode.value = 'light'
    }

    // if NOT set via local storage previously
  } else {
    if (document.documentElement.classList.contains('dark')) {
      document.documentElement.classList.remove('dark')
      localStorage.setItem('color-theme', 'light')
      isDarkMode.value = 'light'
    } else {
      document.documentElement.classList.add('dark')
      localStorage.setItem('color-theme', 'dark')
      isDarkMode.value = 'dark'
    }
  }
}

onMounted(() => {
  const theme = localStorage.getItem('color-theme');
  if (theme) {
    isDarkMode.value = theme;
  }
});

watch(isDarkMode, (newTheme) => {
  localStorage.setItem('color-theme', newTheme);
});
</script>

<template>
  <div id="container" class="h-screen flex flex-col dark:bg-black overflow-auto
                  [&::-webkit-scrollbar]:w-2
                  [&::-webkit-scrollbar-track]:rounded-full
                  [&::-webkit-scrollbar-track]:bg-gray-100
                  [&::-webkit-scrollbar-thumb]:rounded-full
                  [&::-webkit-scrollbar-thumb]:bg-gray-300
                  dark:[&::-webkit-scrollbar-track]:bg-neutral-700
                  dark:[&::-webkit-scrollbar-thumb]:bg-neutral-500">
    <AppHeader :toggleDarkMode="toggleDarkMode" v-model:isDarkMode="isDarkMode" />
    <div class="h-full px-20">
      <router-view class="mx-auto mt-2" />
    </div>
  </div>
</template>


<style>
html,
body,
#app {
  margin: 0;
  padding: 0;
}

body {
  font-family: "Inter", "system-ui";
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
