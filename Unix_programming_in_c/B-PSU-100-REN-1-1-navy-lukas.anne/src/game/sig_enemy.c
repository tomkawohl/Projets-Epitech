/*
** EPITECH PROJECT, 2022
** game
** File description:
** sig_enemy
*/
#include "src.h"

int get_nb_sig_enemy(int incrementation, int reset)
{
    static int nb = 0;
    if (reset == TRUE)
        nb = 0;
    if (incrementation == TRUE) {
        nb++;
        return (nb);
    }
    return (nb);

}

int get_letter_enemy(int incrementation, int reset)
{
    static int nb = 0;
    if (reset == TRUE)
        nb = 0;
    if (incrementation == TRUE) {
        nb++;
        return (nb);
    }
    return (nb);
}

int get_number_enemy(int incrementation, int reset)
{
    static int nb = 0;
    if (reset == TRUE)
        nb = 0;
    if (incrementation == TRUE) {
        nb++;
        return (nb);
    }
    return (nb);
}

void handler_enemy(UNUSED int signo, siginfo_t *info, UNUSED void *context)
{
    if (info->si_signo == SIGUSR2)
        get_nb_sig_enemy(TRUE, FALSE);
    if (info->si_signo == SIGUSR1) {
        if (get_nb_sig_enemy(FALSE, FALSE) == 0)
            get_letter_enemy(TRUE, FALSE);
        else
            get_number_enemy(TRUE, FALSE);
    }
}

void get_sig_enemy(void)
{
    struct sigaction act_enemy = {0};
    act_enemy.sa_flags = SA_SIGINFO;
    act_enemy.sa_sigaction = &handler_enemy;
    if (sigaction(SIGUSR2, &act_enemy, NULL) == -1)
        return;
    if (sigaction(SIGUSR1, &act_enemy, NULL) == -1)
        return;
}
