/*
** EPITECH PROJECT, 2023
** mouse_circle.c
** File description:
** checks if mouse is on circle
*/

#include "src.h"

bool mouse_over_circle(sfCircleShape *circle, sfVector2i mouse)
{
    float rad = sfCircleShape_getRadius(circle);
    sfVector2f pos_mouse = {mouse.x - rad, mouse.y - rad};
    sfVector2f pos = sfCircleShape_getPosition(circle);
    size_t dx = 0, dy = 0;
    size_t d1 = 0;
    size_t d2 = 0;
    size_t d3 = 0;
    size_t d = 0;

    dx = mouse.x - pos.x - rad;
    dy = mouse.y - (pos.y + rad);
    d1 = dx * dx;
    d2 = dy * dy;
    d3 = d1 + d2;
    d = sqrt(d3);
    if (d <= rad)
        return true;
    return false;
}
