<script setup>
import { ref, onMounted } from 'vue';
import DeviceSelector from "../components/DeviceSelector.vue"
import OSSelector from '../components/OSSelector.vue';
import USBSelector from '../components/USBSelector.vue';
const step = ref(1)
</script>

<template>
    <div class="column" style="height: 100dvh;">
        <div class="row q-pa-sm" style="height: 20dvh">
            <q-img src="/logo.webp" style="max-width: 200px; height: 100px;" fit="contain" />
            <q-space />
            <div class="q-pa-sm q-gutter-lg">
                <q-btn round color="primary" class="icon-btn" @click="" icon="settings" />
                <q-btn round color="primary" class="icon-btn" icon="mdi-help" />
            </div>
        </div>

        <div class="q-pa-md op-area">
            <!-- <q-btn label="Reset" push color="white" text-color="green" @click="step = 1" class="q-mb-md" /> -->

            <q-stepper v-model="step" header-nav ref="stepper" done-color="green" active-color="accent" class="stepper"
                animated>
                <q-step :name="1" title="CHOOSE DEVICE" icon="monitor" :done="step > 1" :header-nav="step > 1"
                    text-weight-regular class="column stepper">

                    <div class="q-gutter-y-md column justify-between flex-center stepper">
                        <p style="align-self: flex-start;">Select your device.</p>
                        <DeviceSelector />
                        <q-separator />

                        <q-stepper-navigation class="row justify-end" style="width: 100%;">
                            <q-btn @click="() => { done1 = true; step = 2 }" color="primary" label="NEXT" />
                        </q-stepper-navigation>
                    </div>

                </q-step>

                <q-step :name="2" title="CHOOSE JETPACK" icon="create_new_folder" :done="step > 2"
                    :header-nav="step > 2" class="stepper">
                    <p>Select a JetPack.</p>
                    <OSSelector />
                    <q-stepper-navigation class="row justify-between">
                        <q-btn flat @click="step = 1" color="black" label="BACK" class="q-ml-sm" />
                        <q-btn @click="() => { done2 = true; step = 3 }" color="primary" label="NEXT" />
                    </q-stepper-navigation>
                </q-step>

                <q-step :name="3" title="USB TARGET" icon="usb" :header-nav="step > 3">
                    <p>Select a USB target.</p>
                    <USBSelector />

                    <q-stepper-navigation class="row justify-between">
                        <q-btn flat @click="step = 2" color="black" label="BACK" class="q-ml-sm" />
                        <q-btn color="primary" @click="done3 = true" label="FLASH" />
                    </q-stepper-navigation>
                </q-step>
            </q-stepper>
        </div>
    </div>
</template>

<style scoped>
.op-area {
    max-width: 800px;
    height: 80dvh;
    align-self: center;
}

.stepper {
    background-color: #eeefe3;
    overflow: hidden;
}
</style>