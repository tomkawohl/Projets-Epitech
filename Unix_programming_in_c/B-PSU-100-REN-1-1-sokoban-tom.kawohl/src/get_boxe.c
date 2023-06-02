/*
** EPITECH PROJECT, 2022
** get_boxe
** File description:
** get_boxe
*/
#include "../include/my_all.h"
#include "../include/my.h"
#include "../include/src.h"
#include "../include/struct.h"
#include <curses.h>
#include <stdlib.h>

void is_boxe(char **tab, int i, int j, int *boxe)
{
    if (tab[i][j] == BOXE) {
                (*boxe)++;
            }
}

int get_many_boxe(char **tab)
{
    int boxe = 0;
    int i = 0;
    int j = 0;
    while (tab[i] != 0) {
        j = 0;
        while (tab[i][j] != '\0') {
            is_boxe(tab, i, j, &boxe);
            j++;
        }
        i++;
    }
    return (boxe);
}

void put_coord_boxe(char c, p_pos_t *coord, p_pos_t tmp, int *k)
{
    if (c == BOXE) {
        coord[*k].x = tmp.x;
        coord[*k].y = tmp.y;
        (*k)++;
    }
}

p_pos_t *get_coord_boxe(char **tab, int boxe)
{
    p_pos_t *coord = malloc(sizeof(p_pos_t) * (boxe));
    p_pos_t tmp = {0};
    if (!coord)
        return (NULL);
    int i = 0;
    int j = 0;
    int k = 0;
    while (tab[i] != 0) {
        j = 0;
        while (tab[i][j] != '\0') {
            tmp.x = j;
            tmp.y = i;
            put_coord_boxe(tab[i][j], coord, tmp, &k);
            j++;
        }
        i++;
    }
    return (coord);
}
