/*
** EPITECH PROJECT, 2022
** button_press_left
** File description:
** eraser_btn_press_left
*/
#include "my_paint.h"

void eraser_btn_press_left(paint_t *info)
{
    info->tools->pencil->is_activ = false;
    info->tools->pencil->is_eraser = true;
    set_rightbar(info, 2);
}
