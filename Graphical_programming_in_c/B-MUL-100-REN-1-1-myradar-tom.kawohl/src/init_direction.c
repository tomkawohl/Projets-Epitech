/*
** EPITECH PROJECT, 2022
** src
** File description:
** init_direction
*/
#include "src.h"

/* vector direction */
void init_direction(object_t **planes, int i,
                    sfVector2f origin, sfVector2f dest)
{
    if (planes[i] == NULL)
        return;
    float dx = dest.x - origin.x;
    float dy = dest.y - origin.y;
    double steps = ceil(fmax(fabs(dx), fabs(dy)) / planes[i]->speed);
    sfVector2f displacement = (sfVector2f){dx / steps, dy / steps};
    planes[i]->direction = displacement;
    return;
}
