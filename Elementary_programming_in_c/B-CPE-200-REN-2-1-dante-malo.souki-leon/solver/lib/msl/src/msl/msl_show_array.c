/*
** EPITECH PROJECT, 2023
** msl_show_array.c
** File description:
** msl_show_array.c
*/

#include "msl.h"

void msl_show_array(char **tab)
{
    for (int i = 0; tab[i]; i++){
        msl_putstr(tab[i]);
        write(1, "\n", 2);
    }
}
