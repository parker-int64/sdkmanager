<script setup>
import { useRouter } from 'vue-router';
import { FwbCard, FwbInput, FwbRadio, FwbSelect, FwbButton } from 'flowbite-vue';
import { ref } from 'vue';
const router = useRouter()


/**
 * Attributes in Settings
 */
const user_proxy_picked = ref("no_proxy")
const user_proxy_address = ref("")
const user_proxy_port = ref("")
const user_proxy_username = ref("")
const user_proxy_password = ref("")

const user_proxy_type = ref(0)

const user_proxy_options = [
  { value: 0, name: 'http(s)' },
  { value: 1, name: 'socks5' },
]


/**
 * Handle component actions
 * 
 */

const onCancelBtnClicked = () => {
  router.push('/')
}

</script>
<template>
  <div class="flex flex-col">
    <div class="self-center px-8 w-full max-w-xl md:space-y-8 lg:space-y-16">
      <fwb-card class="!max-w-full">
        <div class="p-5">
          <h5 class="mb-2 text-2xl font-bold tracking-tight text-gray-900 dark:text-white">
            Settings
          </h5>
          <p class="font-normal text-gray-700 dark:text-gray-400">
            Change your configurations
          </p>
          <fwb-radio v-model="user_proxy_picked" name="no_proxy_radio" label="No Proxy" value="no_proxy" />
          <fwb-radio v-model="user_proxy_picked" name="user_proxy_radio" label="Use Custom Proxy" value="user_proxy" />

          <fwb-select v-model="user_proxy_type" :options="user_proxy_options" label="Select Proxy Type"
            :disabled="user_proxy_picked === 'no_proxy'" size="sm" />

          <div class="grid grid-cols-2 gap-4 mt-2">
            <fwb-input v-model="user_proxy_address" placeholder="enter IP or hostname" label="Address"
              :disabled="user_proxy_picked === 'no_proxy'" size="sm" />
            <fwb-input v-model="user_proxy_port" placeholder="enter port number" label="Port"
              :disabled="user_proxy_picked === 'no_proxy'" size="sm" />
            <fwb-input v-model="user_proxy_username" placeholder="username (if)" label="Username"
              :disabled="user_proxy_picked === 'no_proxy'" size="sm" />
            <fwb-input v-model="user_proxy_password" placeholder="password (if)" label="Password"
              :disabled="user_proxy_picked === 'no_proxy'" size="sm" />
          </div>


        </div>
      </fwb-card>
      <div class="flex ml-auto space-x-10">
        <fwb-button color="dark">Apply</fwb-button>
        <fwb-button color="dark" outline @click="onCancelBtnClicked">Cancel</fwb-button>
      </div>
    </div>
  </div>
</template>