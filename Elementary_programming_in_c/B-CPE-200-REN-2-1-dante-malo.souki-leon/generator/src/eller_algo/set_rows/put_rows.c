/*
** EPITECH PROJECT, 2022
** eller_algorithm/set_rows
** File description:
** put_rows
*/
#include "src.h"

void put_number_first_row(int *first_row, int i, int j, int *was_way)
{
    first_row[i] = j;
    (*was_way) = TRUE;
}

void put_wall_first_row(int *first_row, int i, int *j, int *was_way)
{
    first_row[i] = WALL_I;
    if (*was_way)
        (*j)++;
    (*was_way) = FALSE;
}
