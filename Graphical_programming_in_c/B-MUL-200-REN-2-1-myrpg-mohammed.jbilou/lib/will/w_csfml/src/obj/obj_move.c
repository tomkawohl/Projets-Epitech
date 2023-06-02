/*
** EPITECH PROJECT, 2022
** obj
** File description:
** obj_move
*/
#include "../../include/w_csfml.h"

void obj_move(object_t *obj, sfVector2f move)
{
    sfSprite_move(obj->sprite, move);
    if (obj->hitbox_r)
        sfRectangleShape_move(obj->hitbox_r, move);
    if (obj->hitbox_c)
        sfCircleShape_move(obj->hitbox_c, move);
}

/* origin = origin's position of obj */
void obj_move_to(object_t *obj, w_clock_t *w_clock,
                sfVector2f origin, sfVector2f dest)
{
    sfVector2f actual_pos = sfSprite_getPosition(obj->sprite);
    if (fabs(actual_pos.x - obj->dep.x) >= fabs(obj->arr.x - obj->dep.x) &&
    fabs(actual_pos.y - obj->dep.y) >= fabs(obj->arr.y - obj->dep.y)) {
        obj->has_landed = TRUE;
        return;
    }
    if (obj->has_took_off == TRUE) {
        obj_move(obj, obj->direction);
    }
}
