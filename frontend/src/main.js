import { createApp } from 'vue'
import router from './router/router'
import './style.css'
import '../node_modules/flowbite-vue/dist/index.css'
import "inter-ui/inter.css";
import { QWebChannel } from './qwebchannel/qwebchannel';
// Components
import App from './App.vue'


export let wslManager = null;
export let appController = null;

let qWebChannelReady = null;
export const waitForQWebChannel = () => {
    // if initialized, return the current Promise.
    if (qWebChannelReady) {
        return qWebChannelReady;
    }

    // Initialize
    qWebChannelReady = new Promise((resolve, reject) => {
        const initialize = () => {
            if (window.qt === undefined || !window.qt.webChannelTransport) {
                console.error("Qt WebChannel not available.");
                reject("Qt WebChannel not available");
                return;
            }

            new QWebChannel(window.qt.webChannelTransport, (channel) => {
                window.qWebChannel = channel;
                wslManager = channel.objects.wslManager;
                appController = channel.objects.appController;
                console.log("QWebChannel initialized.");
                resolve({ appController, wslManager });
            });
        };

        if (document.readyState === "complete" || document.readyState === "interactive") {
            initialize();
        } else {
            window.addEventListener("load", initialize);
        }
    });

    return qWebChannelReady;
}


const app = createApp(App)

// Disable the default context menu
window.addEventListener('contextmenu', (event) => event.preventDefault())

app.use(router)

app.mount("#app")