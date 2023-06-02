/*
** EPITECH PROJECT, 2022
** print_tab2d
** File description:
** print_tab2d
*/

#include "../include/my_all.h"
#include "../include/my.h"
#include "../include/src.h"
#include <curses.h>
#include <stdlib.h>
int print_tab2d(char **tab2d, char *str, int colone_max)
{
    int j = 0;
    int row = 0;
    int col = 0;
    getmaxyx(stdscr, row, col);
    int line_size = get_line_size(str);
    row = row / 2;
    col = col / 2;
    if (line_size > (row * 2) || colone_max > (col * 2)) {
        mvwprintw(stdscr, row, col - (my_strlen("enlarge the terminal") / 2)
        , "enlarge the terminal");
        return (0);
    }
    for (int i = 0; i != line_size ; i++) {
        while (str[j] != '\n' && str[j] != '\0') {
            j++;
        }
        mvwprintw(stdscr, row - (line_size / 2), col - (j / 2), tab2d[i]);
        row += 1;
    }
        return (0);
}
