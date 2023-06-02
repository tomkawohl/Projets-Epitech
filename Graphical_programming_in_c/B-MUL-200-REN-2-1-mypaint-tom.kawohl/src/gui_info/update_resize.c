/*
** EPITECH PROJECT, 2022
** gui_info/
** File description:
** update_resize
*/
#include "my_paint.h"

void update_resize_text(sfText *text, sfFloatRect original_rect,
    paint_t *info)
{
    sfText_setPosition(text, (sfVector2f)
        {original_rect.left * get_scale((float) original_rect.left,
        (float) info->window_size.x, (float) WIDTH),
        original_rect.top * get_scale((float) original_rect.top, (float)
        info->window_size.y, (float) HEIGHT)});
    sfText_setScale(text, (sfVector2f)
        {get_scale((float) original_rect.width, (float) info->window_size.x,
        (float) WIDTH), get_scale((float) original_rect.height, (float)
        info->window_size.y, (float) HEIGHT)});
    return;
}

void update_resize_rect(sfRectangleShape *rect, sfFloatRect original_rect,
    paint_t *info)
{
    sfRectangleShape_setPosition(rect, (sfVector2f)
        {original_rect.left * get_scale((float) original_rect.left,
        (float) info->window_size.x, (float) WIDTH)
        , original_rect.top * get_scale((float) original_rect.top, (float)
        info->window_size.y, (float) HEIGHT)});
    sfRectangleShape_setScale(rect, (sfVector2f)
        {get_scale((float) original_rect.width, (float) info->window_size.x,
        (float) WIDTH), get_scale((float) original_rect.height, (float)
        info->window_size.y, (float) HEIGHT)});
}

void update_resize_rect_right(sfRectangleShape *rect, sfFloatRect original_rect,
    paint_t *info)
{
    sfRectangleShape_setPosition(rect, (sfVector2f)
        {(float)WIDTH - (float)original_rect.width *
        get_scale((float) original_rect.width,
        (float) info->window_size.x, (float) WIDTH)
        , original_rect.top * get_scale((float) original_rect.top, (float)
        info->window_size.y, (float) HEIGHT)});
    sfRectangleShape_setScale(rect, (sfVector2f)
        {get_scale((float) original_rect.width, (float) info->window_size.x,
        (float) WIDTH), get_scale((float) original_rect.height, (float)
        info->window_size.y, (float) HEIGHT)});
}

void update_resize_text_right(sfText *rect, sfFloatRect original_rect,
    paint_t *info)
{
    sfText_setPosition(rect, (sfVector2f)
        {(float)WIDTH - (float)original_rect.width *
        get_scale((float) original_rect.width,
        (float) info->window_size.x, (float) WIDTH)
        , original_rect.top * get_scale((float) original_rect.top, (float)
        info->window_size.y, (float) HEIGHT)});
    sfText_setScale(rect, (sfVector2f)
        {get_scale((float) original_rect.width, (float) info->window_size.x,
        (float) WIDTH), get_scale((float) original_rect.height, (float)
        info->window_size.y, (float) HEIGHT)});
}

void update_resize_rect_right_middle(sfRectangleShape *rect,
    sfFloatRect original_rect, paint_t *info)
{
    sfRectangleShape_setPosition(rect, (sfVector2f)
        {(float)WIDTH - (float)original_rect.width *
        get_scale((float) original_rect.width,
        (float) info->window_size.x, (float) WIDTH) - (float)RIGHT_WIDTH / 2.0 +
        original_rect.width / 2.0
        , original_rect.top * get_scale((float) original_rect.top, (float)
        info->window_size.y, (float) HEIGHT)});
    sfRectangleShape_setScale(rect, (sfVector2f)
        {get_scale((float) original_rect.width, (float) info->window_size.x,
        (float) WIDTH), get_scale((float) original_rect.height, (float)
        info->window_size.y, (float) HEIGHT)});
}
