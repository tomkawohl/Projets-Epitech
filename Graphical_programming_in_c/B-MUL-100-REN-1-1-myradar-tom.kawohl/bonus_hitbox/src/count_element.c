/*
** EPITECH PROJECT, 2022
** src
** File description:
** count_element
*/
#include "src.h"

int count_airplane(char **map_info)
{
    int nb_airplane = 0;
    for (int i = 0; map_info[i] != NULL; i++) {
        if (map_info[i][0] == 'A')
            nb_airplane++;
    }
    return (nb_airplane);
}

int count_tower(char **map_info)
{
    int nb_tower = 0;
    for (int i = 0; map_info[i] != NULL; i++) {
        if (map_info[i][0] == 'T')
            nb_tower++;
    }
    return (nb_tower);
}
