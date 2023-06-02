/*
** EPITECH PROJECT, 2022
** eller_algorithm
** File description:
** set_first_row
*/
#include "src.h"

int *set_first_row(int x)
{
    int *first_row = NULL;
    int state = 0;
    int j = 1;
    int was_way = TRUE;
    first_row = malloc(sizeof(int) * x);
    if (!first_row)
        return (NULL);
    first_row[0] = 1;
    for (U_INT i = 1; i < (U_INT)(x); i++) {
        state = (rand() % 2);
        if (state == 0 || i == (U_INT)(x - 1))
            put_number_first_row(first_row, i, j, &was_way);
        else
            put_wall_first_row(first_row, i, &j, &was_way);
    }
    return (first_row);
}
