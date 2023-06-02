/*
** EPITECH PROJECT, 2022
** obj
** File description:
** obj_move_rect
*/
#include "../../include/w_csfml.h"

void obj_move_rect_right(object_t *obj, int offset, int max_value)
{
    if (obj->rect.left + offset >= max_value) {
        obj->rect.left = 0;
    } else {
        obj->rect.left += offset;
    }
    sfSprite_setTextureRect(obj->sprite, obj->rect);
}
