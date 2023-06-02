/*
** EPITECH PROJECT, 2022
** check_win
** File description:
** check_win
*/
#include "../include/my_all.h"
#include "../include/my.h"
#include "../include/src.h"
#include "../include/struct.h"
#include <curses.h>
#include <stdlib.h>
int check_loc(char **tab, l_pos_t *coord_loc, int i , int j)
{
    for (int k = 0; k != coord_loc->loc; k++) {
            if (tab[i][j] == BOXE && (i == coord_loc[k].y
            && j == coord_loc[k].x))
                return (1);
        }
    return (0);
}

int check_win(char **tab, l_pos_t *coord_loc)
{
    int boxe = get_many_boxe(tab);
    p_pos_t *coord_boxe = get_coord_boxe(tab, boxe);
    if (!coord_boxe)
        return (0);
    int is_lose = check_lose(tab, coord_boxe);
    int i = 0;
    int j = 0;
    int is_win = 0;
    while (tab[i] != 0) {
        j = 0;
        while (tab[i][j] != '\0') {
            is_win += check_loc(tab, coord_loc, i, j);
            j++;
        }
        i++;
    }
    free(coord_boxe);
    if (is_win == coord_loc->loc) return (1);
    if (is_lose == 1) return (-1);
    return (0);
}
