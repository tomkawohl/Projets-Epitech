/*
** EPITECH PROJECT, 2023
** protocol_connection.c
** File description:
** redirect signal of player for connection
*/

#include "src.h"

int host_get_pid_enemy(int pid_enemy, int get)
{
    static int pid = 0;
    if (get == FALSE) {
        pid = pid_enemy;
    }
    return (pid);
}

void connect_protocol(void)
{
    struct sigaction connect;
    connect.sa_flags = SA_SIGINFO;
    connect.sa_sigaction = &handler_sig;
    if (sigaction(SIGUSR2, &connect, NULL) == -1)
        return;
    return;
}
