/*
** EPITECH PROJECT, 2022
** src
** File description:
** map_struct_init
*/
#include "src.h"

map_t *map_struct_init(void)
{
    map_t *map = malloc(sizeof(map_t));
    if (!map)
        return (NULL);
    map->map_host = NULL;
    map->map_enemy = NULL;
    map->host_vs = NULL;
    map->enemy_vs = NULL;
    return (map);
}
