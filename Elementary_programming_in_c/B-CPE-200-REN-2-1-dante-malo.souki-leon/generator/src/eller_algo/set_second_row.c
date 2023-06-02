/*
** EPITECH PROJECT, 2022
** eller_algorithm
** File description:
** set_second_row
*/
#include "src.h"

void update_second_row(int *second_row, int *row, int i, U_INT *serie_size)
{
    int state = 0;
    static int current_cell = 0;
    static int prev_cell = 0;
    static int has_add = FALSE;

    current_cell = row[i];
    state = (rand() % 2);
    if (current_cell != prev_cell)
        has_add = FALSE;
    if ((state == 0 && (*serie_size) > 1) || has_add == TRUE) {
        second_row[i] = WALL_I;
        (*serie_size)--;
        has_add = FALSE;
    } else {
        second_row[i] = row[i];
        has_add = TRUE;
    }
    prev_cell = row[i];

}

int *set_second_row(int *row, int x)
{
    int *second_row = NULL;
    U_INT serie_size = get_serie_size(row, 0, x);
    int current_cell = 0;
    int prev_cell = 0;

    second_row = malloc(sizeof(int) * x);
    for (U_INT i = 0; i < (U_INT)(x); i++) {
        current_cell = row[i];
        if (row[i] == WALL_I) {
            second_row[i] = WALL_I;
        }
        if (current_cell != prev_cell)
            serie_size = get_serie_size(row, i, x);
        update_second_row(second_row, row, i, &serie_size);
        prev_cell = row[i];
    }
    return (second_row);
}
