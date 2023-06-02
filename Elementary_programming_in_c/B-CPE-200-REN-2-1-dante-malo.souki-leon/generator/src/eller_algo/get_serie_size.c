/*
** EPITECH PROJECT, 2022
** eller_algorithm
** File description:
** get_series_size
*/
#include "src.h"

unsigned int get_serie_size(int *row, int i, int x)
{
    U_INT size = 1;
    int nb = row[i];
    i++;
    while (i < x) {
        if (row[i] == nb)
            size++;
        else
            break;
        i++;
    }
    return (size);
}
