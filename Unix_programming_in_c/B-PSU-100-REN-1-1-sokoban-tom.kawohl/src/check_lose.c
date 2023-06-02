/*
** EPITECH PROJECT, 2022
** check_lose
** File description:
** check_lose
*/
#include "../include/my_all.h"
#include "../include/my.h"
#include "../include/src.h"
#include "../include/struct.h"
#include <curses.h>
#include <stdlib.h>

int is_blocked(char **tab, p_pos_t coord_boxe)
{
    if (tab[coord_boxe.y - 1][coord_boxe.x] == WALL &&
    tab[coord_boxe.y][coord_boxe.x - 1] == WALL)
        return (1);
    if (tab[coord_boxe.y - 1][coord_boxe.x] == WALL &&
    tab[coord_boxe.y][coord_boxe.x + 1] == WALL)
        return (1);
    if (tab[coord_boxe.y + 1][coord_boxe.x] == WALL &&
    tab[coord_boxe.y][coord_boxe.x + 1] == WALL)
        return (1);
    if (tab[coord_boxe.y + 1][coord_boxe.x] == WALL &&
    tab[coord_boxe.y][coord_boxe.x - 1] == WALL)
        return (1);
    return (0);
}

int check_lose(char **tab, p_pos_t *coord_boxe)
{
    int boxe = get_many_boxe(tab);
    int blocked_boxe = 0;
    for (int i = 0; i != boxe; i++) {
        if (is_blocked(tab, coord_boxe[i]) == 1)
            blocked_boxe++;
    }
    if (blocked_boxe == boxe)
        return (1);
    return (0);
}
