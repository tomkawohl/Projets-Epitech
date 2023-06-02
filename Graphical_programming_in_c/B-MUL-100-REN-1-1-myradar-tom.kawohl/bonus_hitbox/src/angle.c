/*
** EPITECH PROJECT, 2022
** src
** File description:
** angle
*/
#include "src.h"

void calcul_angle(object_t **planes, int i)
{
    double dx = (double)(planes[i]->arr.x - planes[i]->dep.x);
    double dy = (double)(planes[i]->arr.y - planes[i]->dep.y);
    double angle = atan2(dy ,dx);
    double angle_deg = angle * 180 / 3.14;
    sfSprite_setRotation(planes[i]->sprite, (float)angle_deg);
    sfRectangleShape_setRotation(planes[i]->hitbox_r, angle_deg);
    planes[i]->angle = angle_deg;
    return;
}
