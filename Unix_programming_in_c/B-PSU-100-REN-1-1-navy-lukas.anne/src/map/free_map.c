/*
** EPITECH PROJECT, 2022
** src
** File description:
** free_map
*/
#include "src.h"

void free_map(char **map_host, char **map_enemy, game_info_t *game_info)
{
    if (game_info->state == HOST) {
        if (map_host != NULL)
            free_array_str2d(map_host);
    }
    if (game_info->state == ENEMY) {
        if (map_enemy != NULL)
            free_array_str2d(map_enemy);
    }
}
