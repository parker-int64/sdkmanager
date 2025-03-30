import { createRouter, createWebHistory } from "vue-router";
import HomePage from '@/views/HomePage.vue'

const router = createRouter({
    history: createWebHistory(import.meta.env.BASE_URL),
    routes: [
        {
            path: "/",
            name: "home",
            component: HomePage,
        },

        {
            path: '/settings',
            name: 'settings',
            component: () => import('../views/SettingsPage.vue')
        },
        {
            path: '/error/:errStr',
            name: 'error',
            component: () => import('../views/ErrorPage.vue')
        }


    ],
});

export default router;