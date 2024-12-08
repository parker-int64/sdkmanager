<script setup>
import { ref, onMounted, computed } from 'vue';

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

const createAcc = ref(false)

const username = ref(null)

const passwd = ref(null)

const confirmPasswd = ref(null)

const isPasswd = ref(true)

// Consider using Vuelidate with extern rules
const isPasswdMatched = computed(() => {
    return passwd.value === confirmPasswd.value
})

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

            <q-card-section class="scroll q-gutter-md">
                <p class="text-body">Unless you know how to use these settings, leave them as defaults.
                </p>

                <q-select filled v-model="model" label="Flash to" :options="defaultStorageDevice"
                    style="width: 500px" />


                <q-checkbox v-model="createAcc" label="Create Account">
                    <q-tooltip class="text-body2">
                        Create an account when flashing.
                    </q-tooltip>
                </q-checkbox>
                <q-input outlined v-model="username" label="Username" :disable="!createAcc" />
                <q-input outlined v-model="passwd" label="Password" :type="isPasswd ? 'password' : 'text'"
                    :disable="!createAcc">
                    <template v-slot:append>
                        <q-icon :name="isPasswd ? 'visibility_off' : 'visibility'" class="cursor-pointer"
                            @click="isPasswd = !isPasswd" />
                    </template>
                </q-input>

                <q-input outlined v-model="confirmPasswd" label="Confirm Password"
                    :type="isPasswd ? 'password' : 'text'" :disable="!createAcc"
                    error-message="Passwords are not matched." bottom-slots :error="!isPasswdMatched">
                    <template v-slot:append>
                        <q-icon :name="isPasswd ? 'visibility_off' : 'visibility'" class="cursor-pointer"
                            @click="isPasswd = !isPasswd" />
                    </template>
                </q-input>

                <q-checkbox v-model="enableRootfsAB" label="Enable RootfsA/B">
                    <q-tooltip class="text-body2">
                        Enable RootfsA/B Redundancy.
                    </q-tooltip>
                </q-checkbox>

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