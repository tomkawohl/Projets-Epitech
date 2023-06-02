/*
** EPITECH PROJECT, 2022
** tab1d_to_tab2d
** File description:
** tab1d_to_tab2d
*/

#include "../include/my_all.h"
#include "../include/my.h"
#include "../include/src.h"
#include <curses.h>
#include <stdlib.h>

char **tab1d_to_2d(char *str)
{
    int nbr = 0;
    int line = 0;
    int line_size = get_line_size(str);
    char **tab2d = malloc(sizeof(char *) * line_size + 1);
    int i = 0;
    int colone_size = 0;
    while (line < line_size) {
        nbr = 0;
        colone_size = get_colone_size(str, i);
        tab2d[line] = malloc(sizeof(char) * (colone_size + 1));
        while (nbr <= colone_size) {
            tab2d[line][nbr] = str[i];
            nbr++;
            i++;
        }
        tab2d[line][nbr] = '\0';
        line ++;
    }
    tab2d[line] = NULL;
    return (tab2d);
}
