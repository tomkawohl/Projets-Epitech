/*
** EPITECH PROJECT, 2022
** game
** File description:
** game_handle
*/
#include "src.h"

void display(game_info_t *game_info, int flag)
{
    if (flag == 1) {
        if (game_info->state == ENEMY)
            w_printf("waiting for enemy's attack...\n");
    } else {
        if (game_info->state == HOST)
            w_printf("\nwaiting for enemy's attack...\n");
    }
}

int game_handle(map_t *map, game_info_t *game_info)
{
    int is_end = FALSE;
    while (is_end == FALSE) {
        map_display(map, game_info);
        display(game_info, 1);
        game_host(game_info, map);
        display(game_info, 2);
        game_enemy(game_info, map);
    }
    return (0);
}
