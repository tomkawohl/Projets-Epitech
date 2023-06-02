/*
** EPITECH PROJECT, 2022
** src
** File description:
** debug_rotate
*/
#include "../src.h"

void debug_obj_rotate(object_t *obj)
{
    (obj->angle) += 2;
    sfSprite_setRotation(obj->sprite, obj->angle);
    sfRectangleShape_setRotation(obj->hitbox_r, obj->angle);
}
