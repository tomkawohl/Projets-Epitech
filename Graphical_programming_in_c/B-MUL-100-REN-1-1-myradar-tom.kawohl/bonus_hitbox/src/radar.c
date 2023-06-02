/*
** EPITECH PROJECT, 2022
** src
** File description:
** radar
*/
#include "src.h"

int radar(char **map_info)
{
    int nb_plane = count_airplane(map_info);
    int nb_tower = count_tower(map_info);
    if (nb_plane == 0)
        return (-1);
    object_t **planes = malloc(sizeof(object_t *) * (nb_plane + 1));
    object_t **towers = NULL;
    init_planes(map_info, planes, nb_plane);
    if (nb_tower > 0) {
        towers = malloc(sizeof(object_t *) * (nb_tower + 1));
        init_towers(map_info, towers, nb_tower);
    }
    simulation(planes, towers);
    obj_destroy_all(planes);
    obj_destroy_all(towers);
    return (0);
}
