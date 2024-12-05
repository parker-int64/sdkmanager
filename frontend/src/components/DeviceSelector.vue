<script setup>
import { ref, onMounted } from 'vue';

const panel = ref('product')

const productOptions = [
  'reComputer J1020 V2',
  'reComputer J1030 V3',
  'reComputer J1040 V4',
  'reComputer Industrial J4011 with Orin NX 16GB'
]

const carrierOptions = [
  'A203 with Jetson Nano Module',
  'A203 with Jetson Xavier Module',
  'A203 with Jetson Xavier NX Module',
]

const prodOptions = ref(productOptions)
const carrOptions = ref(carrierOptions)

const model = ref(null)

const filterFn = (val, update) => {
  if (val === '') {
    update(() => {
      options.value = productOptions
    })
    return
  }
}

const update = (() => {
  const needle = val.toLowerCase()
  options.value = productOptions.filter(v => v.toLowerCase().indexOf(needle) > -1)
})

</script>
<template>
  <q-tabs v-model="panel" dense class="text-black" active-color="primary" indicator-color="primary" align="justify"
    narrow-indicator>
    <q-tab name="product" label="Product" />
    <q-tab name="carrier" label="Carrier Board with Modules" />
  </q-tabs>

  <q-separator />

  <q-tab-panels class="tab-panel" v-model="panel" animated>
    <q-tab-panel name="product" style="background-color: #eeefe3;">
      <q-select filled v-model="model" label="Product Name" :options="prodOptions" style="width: 500px"
        behavior="dialog" />
    </q-tab-panel>

    <q-tab-panel name="carrier" style="background-color: #eeefe3;">
      <q-select filled v-model="model" label="Carrier Board with Module" :options="carrOptions" style="width: 500px"
        behavior="dialog" />
    </q-tab-panel>
  </q-tab-panels>

</template>

<style scoped>
.tab-panel {
  overflow: hidden;
}
</style>