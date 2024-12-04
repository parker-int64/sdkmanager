<script setup>
import { ref, onMounted } from 'vue';

const panel = ref('product')
</script>
<template>
  <q-tabs
      v-model="panel"
      dense
      class="text-black"
      active-color="green"
      indicator-color="green"
      align="justify"
      narrow-indicator
    >
      <q-tab name="product" label="Product" />
      <q-tab name="carrier" label="Carrier Board with Modules" />
  </q-tabs>

  <q-separator />

  <q-tab-panels v-model="panel" animated>
    <q-tab-panel name="product">
      <div class="text-h6">Product</div>
    </q-tab-panel>

    <q-tab-panel name="carrier">
      <div class="text-h6">Carrier Board with Modules</div>
    </q-tab-panel>
  </q-tab-panels>

</template>