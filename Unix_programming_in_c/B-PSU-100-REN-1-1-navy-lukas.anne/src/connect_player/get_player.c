/*
** EPITECH PROJECT, 2022
** src
** File description:
** get_player
*/
#include "src.h"

game_info_t get_player(game_info_t *game_info)
{
    static game_info_t info = {HOST, 0 , 0};
    if (game_info != NULL) {
        info.state = game_info->state;
        info.pid_ennemy = game_info->pid_ennemy;
        info.pid_host = game_info->pid_host;
    }
    return (info);
}
