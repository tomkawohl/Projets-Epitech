/*
** EPITECH PROJECT, 2022
** button_press_left
** File description:
** pencil_size_press_left
*/
#include "my_paint.h"

void click_size1(paint_t *info)
{
    info->tools->pencil->size = 10.0;
    return;
}

void click_size2(paint_t *info)
{
    info->tools->pencil->size = 15.0;
    return;
}

void click_size3(paint_t *info)
{
    info->tools->pencil->size = 20.0;
    return;
}

void click_circle_form(paint_t *info)
{
    info->tools->pencil->form = CIRCLE;
}

void click_square_form(paint_t *info)
{
    info->tools->pencil->form = SQUARE;
}
