/*
** EPITECH PROJECT, 2022
** game_loop
** File description:
** game_loop
*/
#include "../include/my_all.h"
#include "../include/my.h"
#include "../include/src.h"
#include "../include/struct.h"
#include <curses.h>
#include <stdlib.h>

void gameplay(int input, char **tab2d, l_pos_t *coord_loc)
{
    if (input == KEY_DOWN) {
        move_down(tab2d);
    }
    if (input == KEY_UP) {
        move_up(tab2d);
    }
    if (input == KEY_LEFT) {
        move_left(tab2d);
    }
    if (input == KEY_RIGHT) {
        move_right(tab2d);
    }
    check_coord_loc(tab2d, coord_loc);
    return;
}

int game_loop(char *buffer, char **tab2d, l_pos_t *coord_loc)
{
    int input = 0;
    int has_end = 0;
    int colone_max = get_colone_max(buffer);
    initscr();
    while (has_end == 0) {
        clear();
        print_tab2d(tab2d, buffer, colone_max);
        refresh();
        keypad(stdscr, TRUE);
        input = getch();
        if (input == 32)
            return (2);
        gameplay(input, tab2d, coord_loc);
        if (check_win(tab2d, coord_loc) == 1)
            return (0);
        if (check_win(tab2d, coord_loc) == -1)
            return (1);
    }
    return (1);
}
