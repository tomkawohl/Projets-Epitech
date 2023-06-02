/*
** EPITECH PROJECT, 2022
** src
** File description:
** collision_rect
*/
#include "src.h"

int detect_collision_r(object_t *obj_1, object_t *obj_2)
{
    if (obj_1 == NULL || obj_2 == NULL)
        return (FALSE);
    sfVector2f h_1 = sfRectangleShape_getPosition(obj_1->hitbox_r);
    sfVector2f h_2 = sfRectangleShape_getPosition(obj_2->hitbox_r);
    if ((h_2.x >= h_1.x + (float)obj_1->hitbox.width)
    || (h_2.x + (float)obj_2->hitbox.width <= h_1.x)
    || (h_2.y >= h_1.y + (float)obj_1->hitbox.height)
    || (h_2.y + (float)obj_2->hitbox.height <= h_1.y)) {
        return (FALSE);
    }
    return (TRUE);
}
