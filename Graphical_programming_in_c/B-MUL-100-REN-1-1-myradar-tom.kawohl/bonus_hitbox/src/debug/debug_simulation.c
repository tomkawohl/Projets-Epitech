/*
** EPITECH PROJECT, 2022
** src
** File description:
** debug_simulation
*/
#include "../src.h"

void debug_collision(object_t **planes, object_t **towers)
{
    if (detect_collision_r(planes[0], planes[1])) {
        sfRectangleShape_setFillColor(planes[0]->hitbox_r, sfRed);
        sfRectangleShape_setFillColor(planes[1]->hitbox_r, sfRed);
    } else {
        sfRectangleShape_setFillColor(planes[0]->hitbox_r, sfTransparent);
        sfRectangleShape_setFillColor(planes[1]->hitbox_r, sfTransparent);
    }
    if (detect_collision_c_r(towers[0], planes[0])) {
        sfRectangleShape_setFillColor(planes[0]->hitbox_r, sfRed);
        sfCircleShape_setFillColor(towers[0]->hitbox_c, sfRed);
    } else {
        sfRectangleShape_setFillColor(planes[0]->hitbox_r, sfTransparent);
        sfCircleShape_setFillColor(towers[0]->hitbox_c, sfTransparent);
    }
}

void debug_simulation(object_t **planes, object_t **towers)
{
    sfRenderWindow *win = init_window(1920, 1080, 32);
    sfEvent event;
    while (sfRenderWindow_isOpen(win)) {
        debug_event(win, &event, planes);
        sfRenderWindow_clear(win, sfBlack);
        debug_collision(planes, towers);
        debug_display(win, planes, towers);
        sfRenderWindow_display(win);
    }
    sfRenderWindow_destroy(win);
}
