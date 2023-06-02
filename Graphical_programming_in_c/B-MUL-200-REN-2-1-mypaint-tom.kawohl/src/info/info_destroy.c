/*
** EPITECH PROJECT, 2023
** info
** File description:
** info_destroy
*/

#include "my_paint.h"

void info_destroy(paint_t *info)
{
    pencil_destroy(info->tools->pencil);
    free(info->tools);
    layer_destroy(info->layer);
    gui_info_destroy(info->gui);
    free(info);
}
