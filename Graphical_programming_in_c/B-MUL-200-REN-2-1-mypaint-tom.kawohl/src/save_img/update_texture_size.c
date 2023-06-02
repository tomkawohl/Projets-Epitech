/*
** EPITECH PROJECT, 2023
** src/gui/gui_top_init
** File description:
** update the texture size
*/

#include "my_paint.h"

void update_screenshot(paint_t *info)
{
    sfTexture_destroy(info->save.texture);
    info->save.texture = sfTexture_create((unsigned int) info->canvas->perim->
        width, (unsigned int) info->canvas->perim->height);
}
