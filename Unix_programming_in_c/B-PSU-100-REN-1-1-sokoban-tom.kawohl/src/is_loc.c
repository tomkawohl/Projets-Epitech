/*
** EPITECH PROJECT, 2022
** is_loc
** File description:
** is_loc
*/
#include "../include/my_all.h"
#include "../include/my.h"
#include "../include/src.h"
#include "../include/struct.h"
#include <curses.h>
#include <stdlib.h>

void is_loc(char **tab, int i, int j, int *loc)
{
    if (tab[i][j] == LOC) {
                (*loc)++;
            }
}
