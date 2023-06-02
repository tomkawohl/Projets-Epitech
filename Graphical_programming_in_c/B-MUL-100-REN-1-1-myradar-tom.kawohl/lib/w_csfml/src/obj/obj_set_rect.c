/*
** EPITECH PROJECT, 2022
** obj
** File description:
** obj_set_rect
*/
#include "../../include/w_csfml.h"

void obj_set_rect(object_t *obj, sfIntRect set_rect)
{
    obj->rect = set_rect;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    obj->hitbox = sfSprite_getTextureRect(obj->sprite);
}
