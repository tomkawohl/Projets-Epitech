/*
** EPITECH PROJECT, 2022
** get_loc
** File description:
** get_loc
*/
#include "../include/my_all.h"
#include "../include/my.h"
#include "../include/src.h"
#include "../include/struct.h"
#include <curses.h>
#include <stdlib.h>

int get_many_loc(char **tab)
{
    int loc = 0;
    int i = 0;
    int j = 0;
    while (tab[i] != 0) {
        j = 0;
        while (tab[i][j] != '\0') {
            is_loc(tab, i, j, &loc);
            j++;
        }
        i++;
    }
    return (loc);
}

void put_coord_loc(char c, l_pos_t *coord, p_pos_t tmp, int *k)
{
    if (c == LOC) {
        coord[*k].x = tmp.x;
        coord[*k].y = tmp.y;
        (*k)++;
    }
}

l_pos_t *get_coord_loc(char **tab, int loc)
{
    l_pos_t *coord = malloc(sizeof(l_pos_t) * (loc));
    p_pos_t tmp = {0};
    if (!coord)
        return (NULL);
    int i = 0;
    int j = 0;
    int k = 0;
    while (tab[i] != 0){
        j = 0;
        while (tab[i][j] != '\0'){
            tmp.x = j;
            tmp.y = i;
            put_coord_loc(tab[i][j], coord, tmp, &k);
            j++;
        }
        i++;
    }
    return (coord);
}

void display_loc(char **tab, l_pos_t *coord_loc, int i , int j)
{
    for (int k = 0; k < coord_loc->loc; k++) {
            if ((tab[i][j] != PLAYER) && (tab[i][j] != BOXE)
            && (coord_loc[k].x == j && coord_loc[k].y == i)) {
                    tab[i][j] = LOC;
        }
    }
}

void check_coord_loc(char **tab, l_pos_t *coord_loc)
{
    int i = 0;
    int j = 0;
    while (tab[i] != 0) {
        j = 0;
        while (tab[i][j] != '\0') {
            display_loc(tab, coord_loc, i, j);
            j++;
        }
        i++;
    }
}
