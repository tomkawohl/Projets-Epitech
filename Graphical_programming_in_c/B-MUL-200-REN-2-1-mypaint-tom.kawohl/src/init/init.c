/*
** EPITECH PROJECT, 2023
** src/init/init.c
** File description:
** main init function that will initialize the whole project
*/

#include "my_paint.h"

void init_window(paint_t *info)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};
    info->window = sfRenderWindow_create(mode, "my_paint",
        sfResize | sfClose, NULL);
}

void init_canvas(paint_t *info)
{
    info->canvas = malloc(sizeof(struct canvas_t));
    info->canvas->rect = sfRectangleShape_create();
    info->canvas->perim = malloc(sizeof(struct perimiter_t));
    info->canvas->perim->top = CANVAS_START_Y;
    info->canvas->perim->left = CANVAS_START_X;
    info->canvas->perim->width = CANVAS_W;
    info->canvas->perim->height = CANVAS_H;
    sfRectangleShape_setSize(info->canvas->rect, (sfVector2f) {(float)CANVAS_W,
        (float)CANVAS_H});
    sfRectangleShape_setFillColor(info->canvas->rect, sfWhite);
    info->window_zoom = 1.0;
    info->move = false;
}

void init(paint_t *info)
{
    init_window(info);
    info->layer = layer_init(WIDTH, HEIGHT);
    tool_init(info);
    info->running = RUN;
    info->gui = gui_info_init();
    init_canvas(info);
    init_screenshot(info);
    info->save.filename = my_strdup("");
}
