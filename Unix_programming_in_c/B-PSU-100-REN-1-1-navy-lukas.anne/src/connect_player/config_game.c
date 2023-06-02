/*
** EPITECH PROJECT, 2023
** player.c
** File description:
** create host and enemy player
*/

#include "src.h"

int config_game(char **av, game_info_t *game_info)
{
    if (game_info->state == HOST) {
        game_info->pid_host = getpid();
        w_printf("my_pid: %d\n", game_info->pid_host);
        w_printf("waiting for enemy connection...\n");
        connect_protocol();
        while (is_connected(FALSE) == FALSE);
        w_printf("\nenemy connected\n\n");
    }
    if (game_info->state == ENEMY) {
        game_info->pid_host = my_getnbr_int(av[1]);
        game_info->pid_ennemy = getpid();
        w_printf("my_pid: %d\n", game_info->pid_ennemy);
        if (kill (game_info->pid_host, SIGUSR2) == -1)
            return (-1);
        connect_protocol();
        while (is_connected(FALSE) == FALSE);
        w_printf("successfully connected\n\n");
    }
    return (0);
}
