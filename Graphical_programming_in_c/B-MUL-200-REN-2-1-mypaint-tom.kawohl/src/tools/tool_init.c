/*
** EPITECH PROJECT, 2022
** tools/pencil
** File description:
** tool_init
*/
#include "my_paint.h"

void tool_init(paint_t *info)
{
    info->tools = malloc(sizeof(*info->tools));

    if (!info->tools)
        return;
    info->tools->pencil = pencil_init(WIDTH, HEIGHT, info->layer);
}
