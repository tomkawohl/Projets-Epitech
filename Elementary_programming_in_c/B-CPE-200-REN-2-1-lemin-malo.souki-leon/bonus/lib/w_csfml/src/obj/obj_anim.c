/*
** EPITECH PROJECT, 2022
** obj
** File description:
** obj_anim
*/
#include "../../include/w_csfml.h"

void obj_anim(object_t *obj, w_clock_t *w_clock, int offset, int max_value)
{
    int deca_second = (w_clock->microsecond / 10000);
    if (deca_second != 0) {
        if (deca_second % obj->anim_speed == 0 && obj->anim == TRUE) {
            obj->anim = FALSE;
            obj_move_rect_right(obj, offset, max_value);
        }
        if (deca_second % obj->anim_speed != 0) {
            obj->anim = TRUE;
        }
    }
}
