/*
** EPITECH PROJECT, 2022
** src
** File description:
** init_vertical
*/
#include "src.h"

int to_down(char **map_info_2d, int i)
{
    int nb1 = (map_info_2d[i][3] - 48);
    int nb2 = (map_info_2d[i][6] - 48);
    if (nb1 < nb2)
        return (TRUE);
    return (FALSE);
}

void init_vertical(char **map, char **map_info_2d, int i, int j)
{
    int down = to_down(map_info_2d, i);
    int n = ((map_info_2d[i][3] - 48) + 1);
    int placed = 0;
    while (placed != (i + 1)) {
        if (down == TRUE)
            n++;
        else
            n--;
        map[n][j] = ((i + 2) + '0');
        placed++;
    }
}
