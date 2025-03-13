import { createApp } from 'vue'
import router from './router/router'
import './style.css'
import '../node_modules/flowbite-vue/dist/index.css'
import "inter-ui/inter.css";

// Components
import App from './App.vue'


const app = createApp(App)

// Disable the default context menu
window.addEventListener('contextmenu', (event) => event.preventDefault())


app.use(router)

app.mount("#app")