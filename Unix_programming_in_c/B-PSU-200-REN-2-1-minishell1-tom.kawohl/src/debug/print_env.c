/*
** EPITECH PROJECT, 2022
** src
** File description:
** print_env
*/
#include "src.h"

void print_env(char **env)
{
    int i = 0;
    while (env[i]) {
        z_printf("%s\n", env[i]);
        i++;
    }
}
