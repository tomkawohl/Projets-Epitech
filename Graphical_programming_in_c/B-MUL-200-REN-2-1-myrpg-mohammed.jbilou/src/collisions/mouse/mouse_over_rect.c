/*
** EPITECH PROJECT, 2023
** mouse_rect.c
** File description:
** checks if mouse is on rect
*/

#include "src.h"

bool mouse_over_rect(sfRectangleShape *rect, sfVector2i mouse,
    sfRenderWindow *wd)
{
    sfVector2f rect_pos = sfRectangleShape_getPosition(rect);
    sfVector2f size = sfRectangleShape_getSize(rect);
    sfVector2u win_size = sfRenderWindow_getSize(wd);

    rect_pos.x = rect_pos.x * win_size.x / 1920;
    size.x = size.x * win_size.x / 1920;
    rect_pos.y = rect_pos.y * win_size.y / 1080;
    size.y = size.y * win_size.y / 1080;
    if (mouse.x >= rect_pos.x && mouse.x <= (rect_pos.x + size.x)
        && mouse.y >= rect_pos.y && mouse.y <= (rect_pos.y + size.y))
            return true;
    return false;
}
