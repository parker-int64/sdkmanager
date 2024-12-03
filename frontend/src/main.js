import { createApp } from 'vue'
import router from './router/router'
import { Quasar } from 'quasar'

import '@quasar/extras/material-icons/material-icons.css'
import '@quasar/extras/material-icons-round/material-icons-round.css'
import '@quasar/extras/material-symbols-rounded/material-symbols-rounded.css'
import '@quasar/extras/mdi-v7/mdi-v7.css'

// Import Quasar css
import 'quasar/src/css/index.sass'


// Components
import App from './App.vue'


const app = createApp(App)

// Disable the default context menu
window.addEventListener('contextmenu', (event) => event.preventDefault())

app.use(Quasar, {
    plugins: {}, // import Quasar plugins and add here
})


app.use(router)

app.mount("#app")