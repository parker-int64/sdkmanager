import { createApp } from 'vue'
import router from './router/router'


// Components
import App from './App.vue'


const app = createApp(App)

// Disable the default context menu
window.addEventListener('contextmenu', (event) => event.preventDefault())


app.use(router)

app.mount("#app")