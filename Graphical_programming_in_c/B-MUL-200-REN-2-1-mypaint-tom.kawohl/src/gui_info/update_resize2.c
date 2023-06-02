/*
** EPITECH PROJECT, 2023
** update_resize2.c
** File description:
** update_resize2
*/

#include "my_paint.h"

void update_resize_text_right_middle(sfText *rect, sfFloatRect original_rect,
    paint_t *info)
{
    sfText_setPosition(rect, (sfVector2f)
        {(float)WIDTH - (float)original_rect.width *
        get_scale((float) original_rect.width,
        (float) info->window_size.x, (float) WIDTH) - (float)RIGHT_WIDTH / 2.0 +
        original_rect.width / 2.0
        , original_rect.top * get_scale((float) original_rect.top, (float)
        info->window_size.y, (float) HEIGHT)});
    sfText_setScale(rect, (sfVector2f)
        {get_scale((float) original_rect.width, (float) info->window_size.x,
        (float) WIDTH), get_scale((float) original_rect.height, (float)
        info->window_size.y, (float) HEIGHT)});
}
