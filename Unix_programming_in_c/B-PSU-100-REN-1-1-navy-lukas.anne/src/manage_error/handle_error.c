/*
** EPITECH PROJECT, 2022
** src
** File description:
** main
*/
#include "src.h"

int handle_error_host(char **av)
{
    char **map_test = NULL;
    if (av[1] == NULL)
        return (-1);
    map_test = map_init(av[1]);
    if (map_test == NULL)
        return (-1);
    free_array_str2d(map_test);
    return (0);
}

int handle_error_enemy(char **av)
{
    char **map_test = NULL;
    if (av[1] == NULL || av[2] == NULL)
        return (-1);
    map_test = map_init(av[2]);
    if (map_test == NULL)
        return (-1);
    free_array_str2d(map_test);
    return (0);
}
