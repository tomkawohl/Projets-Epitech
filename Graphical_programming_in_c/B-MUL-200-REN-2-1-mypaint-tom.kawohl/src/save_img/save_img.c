/*
** EPITECH PROJECT, 2023
** src/gui/gui_top_init
** File description:
** saves the canvas as image
*/
#include "my_paint.h"

perimiter_t *reset(paint_t *info)
{
    perimiter_t *perimiter = malloc(sizeof(*perimiter));
    perimiter->height = info->canvas->perim->height;
    perimiter->width = info->canvas->perim->width;
    perimiter->left = info->canvas->perim->left;
    perimiter->top = info->canvas->perim->top;
    info->canvas->perim->height = CANVAS_H;
    info->canvas->perim->width = CANVAS_W;
    info->canvas->perim->left = CANVAS_START_X;
    info->canvas->perim->top = CANVAS_START_Y;
    return (perimiter);
}

void capture_image(paint_t *info)
{
    sfImage *image = sfImage_create(info->canvas->perim->width,
        info->canvas->perim->height);
    sfIntRect canva_rect = (sfIntRect){info->canvas->perim->left,
        info->canvas->perim->top, info->canvas->perim->width,
        info->canvas->perim->height};

    sfRenderWindow_setSize(info->window, (sfVector2u){WIDTH, HEIGHT});
    sfTexture_updateFromRenderWindow(info->save.texture, info->window, 0, 0);
    info->save.image = sfTexture_copyToImage(info->save.texture);
    sfImage_copyImage(image, info->save.image, 0, 0, canva_rect, sfFalse);
    sfImage_saveToFile(image, info->save.filename);
    sfImage_destroy(image);
}

void revert_size(paint_t *info, perimiter_t *perimeter,
    sfVector2u original_size, float prev_zoom)
{
    info->canvas->perim->height = perimeter->height;
    info->canvas->perim->width = perimeter->width;
    info->canvas->perim->left = perimeter->left;
    info->canvas->perim->top = perimeter->top;
    info->window_zoom = prev_zoom;
    sfRenderWindow_setSize(info->window, original_size);
    free(perimeter);
}

void save_file(paint_t *info)
{
    sfVector2u original_size;
    float prev_zoom;
    perimiter_t *perimiter;

    if (my_strlen(info->save.filename) == 0)
        if (get_input(info) == false)
            return;
    original_size = sfRenderWindow_getSize(info->window);
    prev_zoom = info->window_zoom;
    info->window_zoom = 1.0f;
    perimiter = reset(info);
    sfRenderWindow_clear(info->window, sfWhite);
    run_window_draw(info);
    capture_image(info);
    revert_size(info, perimiter, original_size, prev_zoom);
}
