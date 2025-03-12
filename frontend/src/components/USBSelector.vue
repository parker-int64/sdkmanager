<!-- USB Selector Component -->

<script setup>
import { ref, onMounted } from 'vue';


const columns = [
    {
        name: 'BUSID',
        field: 'busid',
        align: 'left',
        label: 'BUSID'
    },
    { name: 'VID:PID', align: 'left', label: 'VID:PID', field: 'vid_pid' },
    { name: 'DEVICE', align: 'center', label: 'DEVICE', field: 'device' },
    { name: 'STATE', align: 'left', label: 'STATE', field: 'state' },
]

const rows = [
    {
        busid: "1-1",
        vid_pid: "1532:009c",
        device: "USB Input Device, Razer DeathAdder V2 X HyperSpeed",
        state: "Not shared"
    },
    {
        busid: "1-3",
        vid_pid: "2d99:0028",
        device: "HECATE GS03 GAMING SOUND CARD, USB 输入设备",
        state: "Not shared"
    },
    {
        busid: "1-5",
        vid_pid: "2b7e:b651",
        device: "HD Webcam",
        state: "Not shared"
    },
    {
        busid: "1-10",
        vid_pid: "8087:0026",
        device: "英特尔(R) 无线 Bluetooth(R)",
        state: "Not shared"
    },
]


const selectedUSB = ref([])  // v-bind to this value
// Methods


</script>
<template>
    <q-table card-class="bg-grey-3" :rows="rows" :columns="columns" dense row-key="busid" style="height: 180px"
        no-data-label="No available APX device found" selection="single" v-model:selected="selectedUSB" flat bordered />
    <p class="q-pt-sm">You selected: {{ selectedUSB }}</p>
</template>

<style scoped></style>