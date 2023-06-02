/*
** EPITECH PROJECT, 2022
** show_int
** File description:
** show_int
*/

#include "msl.h"

void psl_show_int(int **tab)
{
    for (int i = 0; tab[i]; i++){
        for (int j = 0; tab[i][j]; j++){
            msl_putchar(tab[i][j]);
        }
        msl_putchar('\n');
    }
}
