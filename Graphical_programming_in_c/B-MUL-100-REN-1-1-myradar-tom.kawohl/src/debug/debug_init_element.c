/*
** EPITECH PROJECT, 2022
** src
** File description:
** debug_init_element
*/
#include "src.h"

void debug_init_planes(object_t **planes, int nb_planes)
{
    for (int i = 0; i < nb_planes; i++) {
        planes[i] = obj_sprite_create("assets/sprites/plane.png");
        planes[i]->hitbox = (sfIntRect){0, 0, 20, 20};
        if (i == 1)
            sfSprite_setPosition(planes[i]->sprite, (sfVector2f){100.0, 100.0});
        obj_hitbox_t plane_hitbox = obj_get_hitbox(planes[i]);
        planes[i]->hitbox_r = hitbox_rect(plane_hitbox);
    }
    planes[nb_planes] = NULL;
    return;
}

void debug_init_towers(object_t **towers)
{
    towers[0] = obj_sprite_create("assets/sprites/tower.png");
    sfSprite_setPosition(towers[0]->sprite, (sfVector2f) {200, 200});
    towers[0]->hitbox = (sfIntRect){0, 0, 35, 35};
    towers[0]->radius = 50.0;
    towers[0]->hitbox_c = hitbox_circle(towers[0], towers[0]->radius);
    towers[1] = NULL;
}
