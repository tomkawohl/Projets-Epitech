/*
** EPITECH PROJECT, 2022
** move_boxes
** File description:
** move_boxes
*/
#include "../include/my_all.h"
#include "../include/my.h"
#include "../include/src.h"
#include <curses.h>
#include <stdlib.h>

void move_boxe_left(char **tab, p_pos_t pos)
{
    if (tab[pos.y][pos.x - 1] == BOXE && tab[pos.y][pos.x - 2] != WALL) {
        tab[pos.y][pos.x - 2] = BOXE;
    }
}

void move_boxe_right(char **tab, p_pos_t pos)
{
    if (tab[pos.y][pos.x + 1] == BOXE && tab[pos.y][pos.x + 2] != WALL) {
        tab[pos.y][pos.x + 2] = BOXE;
    }
}

void move_boxe_up(char **tab, p_pos_t pos)
{
    if (tab[pos.y - 1][pos.x] == BOXE && tab[pos.y - 2][pos.x] != WALL) {
        tab[pos.y - 2][pos.x] = BOXE;
    }
}

void move_boxe_down(char **tab, p_pos_t pos)
{
    if (tab[pos.y + 1][pos.x] == BOXE && tab[pos.y + 2][pos.x] != WALL) {
        tab[pos.y + 2][pos.x] = BOXE;
    }
}
