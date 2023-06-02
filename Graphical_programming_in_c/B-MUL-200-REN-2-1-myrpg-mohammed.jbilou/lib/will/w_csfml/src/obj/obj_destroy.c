/*
** EPITECH PROJECT, 2022
** obj
** File description:
** obj_destroy
*/
#include "../../include/w_csfml.h"

void obj_destroy(object_t *obj)
{
    if (!obj)
        return;
    sfTexture_destroy(obj->texture);
    sfSprite_destroy(obj->sprite);
    if (obj->hitbox_c != NULL)
        sfCircleShape_destroy(obj->hitbox_c);
    if (obj->hitbox_r != NULL)
        sfRectangleShape_destroy(obj->hitbox_r);
    free(obj);
}
