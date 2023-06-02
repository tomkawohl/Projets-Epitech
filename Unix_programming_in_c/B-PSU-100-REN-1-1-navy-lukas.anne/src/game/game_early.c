/*
** EPITECH PROJECT, 2022
** game
** File description:
** game_early
*/
#include "src.h"

void game_early_host(siginfo_t *info)
{
    if (info->si_signo == SIGUSR2)
        get_nb_sig_host(TRUE, FALSE);
    if (info->si_signo == SIGUSR1) {
        if (get_nb_sig_host(FALSE, FALSE) == 0)
            get_letter_host(TRUE, FALSE);
        else
            get_number_host(TRUE, FALSE);
    }
}
