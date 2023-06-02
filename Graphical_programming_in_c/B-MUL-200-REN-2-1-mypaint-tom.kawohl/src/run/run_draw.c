/*
** EPITECH PROJECT, 2023
** src/run/run_draw
** File description:
** main function that will draw everything
*/

#include "my_paint.h"

void draw_canvas_bg(paint_t *info)
{
    sfRectangleShape_setPosition(info->canvas->rect, (sfVector2f)
        {info->canvas->perim->left * get_scale((float) CANVAS_W,
        (float) info->window_size.x, (float) WIDTH)
        * info->window_zoom, info->canvas->perim->top *
        get_scale((float) CANVAS_H, (float)
        info->window_size.y, (float) HEIGHT) * info->window_zoom});
    sfRectangleShape_setScale(info->canvas->rect, (sfVector2f)
        {get_scale((float) CANVAS_W, (float) info->window_size.x, (float) WIDTH)
        * info->window_zoom, get_scale((float) CANVAS_H, (float)
        info->window_size.y, (float) HEIGHT) * info->window_zoom});
    sfRenderWindow_drawRectangleShape(info->window, info->canvas->rect, NULL);
}

void run_window_draw(paint_t *info)
{
    sfTexture_updateFromPixels(info->tools->pencil->current_layer->
        list_texture->first->texture, info->tools->pencil->pixels, WIDTH,
        HEIGHT, 0, 0);
    draw_canvas_bg(info);
    layer_draw(info);
    gui_info_draw(info);
    priority_button_draw(info->gui->prio, info);
    return;
}
