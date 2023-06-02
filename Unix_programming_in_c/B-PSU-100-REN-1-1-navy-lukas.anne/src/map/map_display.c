/*
** EPITECH PROJECT, 2022
** src
** File description:
** map_display
*/
#include "src.h"

void map_display(map_t *map, game_info_t *game_info)
{
    w_printf("my_positions:\n");
    if (game_info->state == HOST) {
        if (map->map_host != NULL)
            print_str2d(map->map_host);
    }
    if (game_info->state == ENEMY) {
        if (map->map_enemy != NULL)
            print_str2d(map->map_enemy);
    }
    w_printf("\nenemy's positions:\n");
    if (game_info->state == HOST)
        print_str2d(map->host_vs);
    if (game_info->state == ENEMY)
        print_str2d(map->enemy_vs);
    w_printf("\n\n");
}
