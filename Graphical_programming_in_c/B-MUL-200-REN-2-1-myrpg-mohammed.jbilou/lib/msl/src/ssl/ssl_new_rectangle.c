/*
** EPITECH PROJECT, 2022
** new_sprite.c
** File description:
** desc
*/

#include "msl.h"
#include "../../../includes/src_struct.h"

sfRectangleShape *ssl_new_rect(Vect2f size, sfColor color, Vect2f pos)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, color);
    sfRectangleShape_setPosition(rect, pos);
    return rect;
}
