<script setup>
import { ref, onMounted } from 'vue';
import ChartCard from '../components/ChartCard.vue';


</script>

<template>
    <v-layout class="d-flex flex-column ma-auto pa-10">
        <v-row>
            <v-col xs="12" sm="12" md="4" lg="4" xl="4" align="center">
                <ChartCard />
            </v-col>
        </v-row>

        <v-spacer style="height: 50px;"></v-spacer>

    </v-layout>
</template>

<style></style>