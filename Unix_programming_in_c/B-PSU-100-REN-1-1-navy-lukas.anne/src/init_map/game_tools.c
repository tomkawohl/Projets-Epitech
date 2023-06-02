/*
** EPITECH PROJECT, 2022
** src
** File description:
** game_tools
*/
#include "src.h"

int is_horizontal(char **map_info_2d, int i)
{
    if (map_info_2d[i][2] == map_info_2d[i][5])
        return (FALSE);
    return (TRUE);
}

int to_left(char **map_info_2d, int i)
{
    int nb1 = letter_into_int(map_info_2d[i][2]);
    int nb2 = letter_into_int(map_info_2d[i][5]);
    if (nb1 < nb2)
        return (FALSE);
    return (TRUE);
}

int letter_into_int(char c)
{
    int i = 0;
    char *letters = "ABCDEFGH";
    while (letters[i] != '\0' && c != letters[i]) {
        i++;
    }
    i++;
    return (i);
}
