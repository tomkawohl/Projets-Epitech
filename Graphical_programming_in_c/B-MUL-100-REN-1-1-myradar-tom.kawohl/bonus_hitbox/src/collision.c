/*
** EPITECH PROJECT, 2022
** src
** File description:
** collision
*/
#include "src.h"

void is_collision(object_t **planes, int i, int j)
{
    if (detect_collision_r(planes[i], planes[j]) && i != j) {
        planes[i]->is_crashed = TRUE;
        planes[j]->is_crashed = TRUE;
    }
    return;
}

void is_in_tower_area(object_t **planes, object_t **towers, int i, int j)
{
    for (int k = 0; towers[k] != NULL; k++) {
        if (detect_collision_c_r(towers[k], planes[i])
        && detect_collision_c_r(towers[k], planes[j]))
            return;
    }
    if (planes[i]->is_crashed == TRUE ||
    planes[i]->has_took_off == FALSE || planes[i]->has_landed == TRUE)
        return;
    if (planes[j]->is_crashed == TRUE ||
    planes[j]->has_took_off == FALSE || planes[j]->has_landed == TRUE)
        return;
    is_collision(planes, i, j);
}

void collision(object_t **planes, object_t **towers)
{
    for (int i = 0; planes[i] != NULL; i++) {
        for (int j = 0; planes[j] != NULL; j++) {
            is_in_tower_area(planes, towers, i, j);
        }
    }
}
