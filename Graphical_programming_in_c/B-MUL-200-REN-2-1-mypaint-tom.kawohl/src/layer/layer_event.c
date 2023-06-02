/*
** EPITECH PROJECT, 2022
** tools/pencil
** File description:
** layer_event
*/
#include "my_paint.h"

void reset_if_released(sfEvent event, int *can_add, int *can_delete)
{
    if (event.type == sfEvtKeyReleased) {
        (*can_add) = true;
        (*can_delete) = true;
    }
}

void layer_event(paint_t *info, sfEvent event)
{
    static int can_add = true;
    static int can_delete = true;
    if (sfKeyboard_isKeyPressed(sfKeyLShift)
    && sfKeyboard_isKeyPressed(sfKeyLControl)
    && sfKeyboard_isKeyPressed(sfKeyN)
    && can_add == true) {
        layer_add(info->layer, WIDTH, HEIGHT);
        info->tools->pencil->current_layer = info->layer->first;
        can_add = false;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLShift)
    && sfKeyboard_isKeyPressed(sfKeyLControl)
    && sfKeyboard_isKeyPressed(sfKeyD) && can_delete == true) {
        has_layer_changed(true, false);
        info->tools->pencil->current_layer = NULL;
        layer_remove(info->layer, true);
        info->tools->pencil->current_layer = info->layer->first;
        can_delete = false;
    }
    reset_if_released(event, &can_add, &can_delete);
}
