/*
** EPITECH PROJECT, 2022
** can_move
** File description:
** can_move
*/
#include "../include/my_all.h"
#include "../include/my.h"
#include "../include/src.h"
#include "../include/struct.h"
#include <curses.h>
#include <stdlib.h>

int can_move_right(char **tab, p_pos_t pos)
{
    if (tab[pos.y][pos.x + 1] == BOXE) {
        if (tab[pos.y][pos.x + 2] == WALL ||
        tab[pos.y][pos.x + 2] == BOXE) {
            return (0);
        }
    }
    return (1);
}

int can_move_left(char **tab, p_pos_t pos)
{
    if (tab[pos.y][pos.x - 1] == BOXE) {
        if (tab[pos.y][pos.x - 2] == WALL ||
        tab[pos.y][pos.x - 2] == BOXE) {
            return (0);
        }
    }
    return (1);
}

int can_move_up(char **tab, p_pos_t pos)
{
    if (tab[pos.y - 1][pos.x] == BOXE) {
        if (tab[pos.y - 2][pos.x] == WALL ||
        tab[pos.y - 2][pos.x] == BOXE) {
            return (0);
        }
    }
    return (1);
}

int can_move_down(char **tab, p_pos_t pos)
{
    if (tab[pos.y + 1][pos.x] == BOXE) {
        if (tab[pos.y + 2][pos.x] == WALL ||
        tab[pos.y + 2][pos.x] == BOXE) {
            return (0);
        }
    }
    return (1);
}
