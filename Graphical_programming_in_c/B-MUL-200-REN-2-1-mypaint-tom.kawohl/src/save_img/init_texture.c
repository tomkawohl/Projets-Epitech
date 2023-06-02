/*
** EPITECH PROJECT, 2023
** src/gui/gui_top_init
** File description:
** initializes the texture used for screenshotting
*/

#include "my_paint.h"

void init_screenshot(paint_t *info)
{
    info->save.texture = sfTexture_create(WIDTH, HEIGHT);
    info->save.image = sfImage_create(WIDTH, HEIGHT);
}
