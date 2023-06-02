/*
** EPITECH PROJECT, 2022
** src
** File description:
** all_map_init
*/
#include "src.h"

int all_map_init(char ***map_host, char ***map_enemy,
game_info_t *game_info, char **av)
{
    if (game_info->state == HOST) {
        if (av[1] == NULL)
            return (-1);
        map_host[0] = map_init(av[1]);
        if (!map_host)
            return (-1);
    }
    if (game_info->state == ENEMY) {
        if (av[2] == NULL)
            return (-1);
        map_enemy[0] = map_init(av[2]);
        if (!map_enemy)
            return (-1);
    }
    return (0);
}

int all_map_opponent_init(char ***host_opponent, char ***enemy_opponent)
{
    char *map_oponnent = file_to_str_getline("src/init_map/map_opponent.txt");
    if (!map_oponnent)
        return (-1);
    host_opponent[0] = str1d_to_str2d(map_oponnent);
    enemy_opponent[0] = str1d_to_str2d(map_oponnent);
    if (host_opponent == NULL || enemy_opponent == NULL)
        return (-1);
    free(map_oponnent);
    return (0);
}
