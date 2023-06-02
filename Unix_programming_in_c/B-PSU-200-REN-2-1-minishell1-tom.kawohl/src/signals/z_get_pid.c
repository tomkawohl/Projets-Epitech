/*
** EPITECH PROJECT, 2022
** signals
** File description:
** z_get_pid
*/
#include "src.h"

void set_pid(void)
{
    int pid = getpid();
    z_get_pid(&pid);
}

int z_get_pid(int *pid)
{
    static int pid_res = 0;
    if (pid != NULL) {
        pid_res = (*pid);
    }
    return (pid_res);
}
