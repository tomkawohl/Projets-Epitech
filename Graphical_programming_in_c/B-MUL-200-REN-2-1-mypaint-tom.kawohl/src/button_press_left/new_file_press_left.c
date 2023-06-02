/*
** EPITECH PROJECT, 2022
** button_press_left
** File description:
** new_file_press_left
*/
#include "my_paint.h"

void new_file_press_left(paint_t *info)
{
    layer_remove_all(info->layer);
    layer_add(info->layer, WIDTH, HEIGHT);
    info->tools->pencil->current_layer = info->layer->first;
    return;
}
