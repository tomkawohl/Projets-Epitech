/*
** EPITECH PROJECT, 2022
** src
** File description:
** init_pid_enemy
*/
#include "src.h"

void init_pid_enemy(game_info_t *game_info)
{
    if (game_info->state != HOST)
        return;
    int pid_enemy = host_get_pid_enemy(0, TRUE);
    game_info->pid_ennemy = pid_enemy;
    return;
}
