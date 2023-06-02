/*
** EPITECH PROJECT, 2022
** move
** File description:
** move
*/
#include "../include/my_all.h"
#include "../include/my.h"
#include "../include/src.h"
#include "../include/struct.h"
#include <curses.h>
#include <stdlib.h>

void move_down(char **tab)
{
    p_pos_t pos = get_player(tab);
    if (tab[pos.y + 1][pos.x] != WALL){
        if (can_move_down(tab, pos) == 1) {
            move_boxe_down(tab, pos);
            tab[pos.y][pos.x] = GROUND;
            tab[pos.y + 1][pos.x] = PLAYER;
        }
    }
    return;
}

void move_up(char **tab)
{
    p_pos_t pos = get_player(tab);
    if (tab[pos.y - 1][pos.x] != WALL) {
        if (can_move_up(tab, pos) == 1) {
            move_boxe_up(tab, pos);
            tab[pos.y][pos.x] = GROUND;
            tab[pos.y - 1][pos.x] = PLAYER;
        }
    }
    return;
}

void move_left(char **tab)
{
    p_pos_t pos = get_player(tab);
    if (tab[pos.y][pos.x - 1] != WALL) {
        if (can_move_left(tab, pos) == 1) {
            move_boxe_left(tab, pos);
            tab[pos.y][pos.x] = GROUND;
            tab[pos.y][pos.x - 1] = PLAYER;
        }
    }
    return;
}

void move_right(char **tab)
{
    p_pos_t pos = get_player(tab);
    if (tab[pos.y][pos.x + 1] != WALL) {
        if (can_move_right(tab, pos) == 1) {
            move_boxe_right(tab, pos);
            tab[pos.y][pos.x] = GROUND;
            tab[pos.y][pos.x + 1] = PLAYER;
        }
    }
    return;
}
