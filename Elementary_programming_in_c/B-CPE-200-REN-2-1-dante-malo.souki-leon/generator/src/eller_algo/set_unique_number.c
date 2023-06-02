/*
** EPITECH PROJECT, 2022
** eller_algorithm
** File description:
** set_unique_number
*/
#include "src.h"

int get_unique_number(int *row, int x)
{
    int i = x - 1;
    while (i >= 0) {
        if (row[i] != WALL_I)
            return (row[i] + 1);
        i--;
    }
    return (0);
}

int *set_unique_number(int *row, int x)
{
    int *third_row = NULL;
    int unique_number = get_unique_number(row, x);
    int wall = 0;

    third_row = malloc(sizeof(int) * x);
    for (U_INT i = 0; i < (U_INT)(x); i++) {
        if (row[i] == WALL_I)
            wall++;
        else
            wall = 0;
        if (wall == 3) {
            third_row[i - 1] = unique_number;
            third_row[i] = WALL_I;
            unique_number++;
            wall = 1;
        } else {
            third_row[i] = row[i];
        }
    }
    return (third_row);
}
