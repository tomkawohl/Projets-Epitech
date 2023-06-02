/*
** EPITECH PROJECT, 2022
** button_press_left
** File description:
** pencil_btn_press_left
*/
#include "my_paint.h"

void pencil_btn_press_left(paint_t *info)
{
    info->tools->pencil->is_activ = true;
    info->tools->pencil->is_eraser = false;
    set_rightbar(info, 1);
    return;
}
