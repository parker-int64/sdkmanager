<script setup>
import { ref, onMounted } from 'vue';

const jetPackVer = [
    '4.6.5',
    '4.6.1',
    '4.6.0',
]

const defaultStorageDevice = [
    'M.2 Key M NVMe SSD',
    'eMMC',
    'Micro SD' // unlikely, but it is supported using CLI flash
]


const fixedDialog = ref(false)

const enableRootfsAB = ref(false)

</script>
<template>
    <div class="column q-pa-md q-gutter-lg">
        <q-select filled v-model="model" label="JetPack Version" :options="jetPackVer" style="width: 500px" />

        <q-btn flat color="accent" label="Advanced" @click="fixedDialog = true" style="width: 100px" />
    </div>

    <q-dialog v-model="fixedDialog">
        <q-card>
            <q-card-section>
                <div class="text-h6">Advanced Flash Options</div>
            </q-card-section>

            <q-separator />

            <q-card-section style="max-height: 50vh" class="scroll q-gutter-md">
                <p class="text-body">Unless you know how to use these settings, leave them as defaults.
                </p>

                <q-checkbox v-model="enableRootfsAB" label="Enable RootfsA/B">

                    <q-tooltip class="text-body2">
                        Enable RootfsA/B Redundancy. NVIDIA® Jetson™ Linux supports Bootloader update and redundancy on
                        all Jetson platforms.

                        The Bootloader update process performs a safe Bootloader update and ensures that a workable
                        Bootloader partition remains available during an update. It accomplishes this using A/B update,
                        a feature that maintains two sets of Bootloader partitions, Slot A and Slot B, each of which is
                        a complete set of the partitions that contain boot images.

                        Bootloader redundancy is enabled by default.
                    </q-tooltip>
                </q-checkbox>
                <q-select filled v-model="model" label="Flash to" :options="defaultStorageDevice"
                    style="width: 500px" />
            </q-card-section>

            <q-separator />

            <q-card-actions align="right">
                <q-btn flat label="CANCEL" color="primary" v-close-popup />
                <q-btn flat label="SAVE" color="primary" v-close-popup />
            </q-card-actions>
        </q-card>
    </q-dialog>
</template>

<style scoped></style>