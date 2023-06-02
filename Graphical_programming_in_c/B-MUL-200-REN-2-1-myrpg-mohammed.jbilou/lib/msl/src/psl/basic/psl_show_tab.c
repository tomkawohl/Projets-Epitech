/*
** EPITECH PROJECT, 2022
** show_tab
** File description:
** show_tab
*/

#include "msl.h"

void psl_show_tab(char **tab)
{
    for (int i = 0; tab[i]; i++){
        msl_putstr(tab[i]);
        msl_putchar('\n');
    }
}
