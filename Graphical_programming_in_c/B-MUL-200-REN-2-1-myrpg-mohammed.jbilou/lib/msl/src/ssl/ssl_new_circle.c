/*
** EPITECH PROJECT, 2023
** ssl_new_circle
** File description:
** ssl_new_circle
*/

#include "msl.h"

sfCircleShape *ssl_new_cirle(sfVector2f pos, float rad, sfColor color)
{
    sfCircleShape *circ = sfCircleShape_create();

    sfCircleShape_setRadius(circ, rad);
    sfCircleShape_setFillColor(circ, color);
    sfCircleShape_setPosition(circ, pos);
    return circ;
}
