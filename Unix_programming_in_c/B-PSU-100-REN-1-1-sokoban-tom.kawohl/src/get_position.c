/*
** EPITECH PROJECT, 2022
** get_position
** File description:
** get_position
*/
#include "../include/my_all.h"
#include "../include/my.h"
#include "../include/src.h"
#include "../include/struct.h"
#include <curses.h>
#include <stdlib.h>

void give_coord_p(char c, int i, int j, p_pos_t *coord)
{
    if (c == PLAYER) {
        coord->x = j;
        coord->y = i;
    }
}

p_pos_t get_player(char **tab)
{
    p_pos_t coord = {0, 0};

    int i = 0;
    int j = 0;
    while (tab[i] != 0) {
        j = 0;
        while (tab[i][j] != '\0') {
            give_coord_p(tab[i][j], i, j, &coord);
            j++;
        }
        i++;
    }
    return (coord);
}
