/*
** EPITECH PROJECT, 2022
** src
** File description:
** handler_sig
*/
#include "src.h"

void handler_sig(UNUSED int signal, siginfo_t *info, UNUSED void *data)
{
    game_info_t game_info = get_player(NULL);
    if (is_connected(FALSE) == FALSE) {
        if (game_info.state == HOST) {
            int pid_enemy = info->si_pid;
            host_get_pid_enemy(pid_enemy, FALSE);
            kill(pid_enemy, SIGUSR2);
            is_connected(TRUE);
        } else {
            is_connected(TRUE);
        }
    }
}
