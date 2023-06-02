/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include "../include/my_all.h"
#include "../include/my.h"
#include "../include/src.h"
#include <curses.h>
#include <stdlib.h>

void delete_ressources(char **tab2d, char *buffer, l_pos_t *coord_loc)
{
    endwin();
    free_tab2d(tab2d, buffer);
    free(coord_loc);
}

int main(int ac, char **av)
{
    int res = 2;
    if (ac != 2) return (84);
    int size = stat_file(av[1]);
    char *buffer = handle_file(av[1], size);
    if (!buffer) return (84);
    while (res == 2) {
        char **tab2d = tab1d_to_2d(buffer);
        if (!tab2d) return (84);
        int loc = get_many_loc(tab2d);
        l_pos_t *coord_loc = get_coord_loc(tab2d, loc);
        coord_loc->loc = loc;
        if (handling_errors(buffer, tab2d) == -1) return (84);
        res = game_loop(buffer, tab2d, coord_loc) ;
        delete_ressources(tab2d, buffer, coord_loc);
    }
    delwin(stdscr);
    free(buffer);
    return (res);
}
