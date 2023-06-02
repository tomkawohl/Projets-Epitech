/*
** EPITECH PROJECT, 2022
** src
** File description:
** init_horizontal
*/
#include "src.h"

void put_direcion_horizontal(int left, int *j)
{
    if (left == TRUE)
        (*j)--;
    else
        (*j)++;
    return;
}

void init_horizontal(char **map, char **map_info_2d, int i, int j)
{
    int left = to_left(map_info_2d, i);
    int n = ((map_info_2d[i][3] - 48) + 1);
    int placed = 0;
    while (placed != (i + 1)) {
        while (map[n][j] != '.' && map[n][j] != '\0') {
            put_direcion_horizontal(left, &j);
        }
        map[n][j] = ((i + 2) + '0');
        placed++;
    }
}
