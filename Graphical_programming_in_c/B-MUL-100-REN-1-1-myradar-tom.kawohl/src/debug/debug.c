/*
** EPITECH PROJECT, 2022
** src
** File description:
** angle
*/
#include "src.h"

void debug(void)
{
    int nb_planes = 2;
    object_t **planes = malloc(sizeof(object_t *) * (nb_planes + 1));
    object_t **towers = malloc(sizeof(object_t *) * 2);
    debug_init_towers(towers);
    debug_init_planes(planes, nb_planes);
    debug_simulation(planes, towers);
    obj_destroy_all(planes);
    obj_destroy_all(towers);
}
