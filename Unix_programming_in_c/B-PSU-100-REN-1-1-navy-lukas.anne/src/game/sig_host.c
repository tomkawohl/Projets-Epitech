/*
** EPITECH PROJECT, 2022
** game
** File description:
** sig_host
*/
#include "src.h"

int get_nb_sig_host(int incrementation, int reset)
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

int get_letter_host(int incrementation, int reset)
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

int get_number_host(int incrementation, int reset)
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

void handler_host(UNUSED int signo, siginfo_t *info, UNUSED void *context)
{
    if (game_state == EARLY)
        game_early_host(info);
}

void get_sig_host(void)
{
    struct sigaction act_host = {0};
    act_host.sa_flags = SA_SIGINFO;
    act_host.sa_sigaction = &handler_host;
    if (sigaction(SIGUSR2, &act_host, NULL) == -1)
        return;
    if (sigaction(SIGUSR1, &act_host, NULL) == -1)
        return;
}
