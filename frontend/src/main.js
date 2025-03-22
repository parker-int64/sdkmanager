import { createApp } from 'vue'
import router from './router/router'
import './style.css'
import '../node_modules/flowbite-vue/dist/index.css'
import "inter-ui/inter.css";
import { QWebChannel } from './qwebchannel/qwebchannel';
// Components
import App from './App.vue'

export var qwebchannel = null


window.onload = () => {
    if (window.qt === undefined) {
        console.error("Failed to Inject QtWebChannel...");
        return;
    }
    new QWebChannel(window.qt.webChannelTransport, (channel) => {
        // all published objects are available in channel.objects under
        // the identifier set in their attached WebChannel.id property
        window.qwebchannel = channel;
        window.wslmanager = channel.objects.wslmanager
    })
    console.log("Info: Initialized QWebChannel.")
}


const app = createApp(App)

// Disable the default context menu
window.addEventListener('contextmenu', (event) => event.preventDefault())

app.use(router)

app.mount("#app")