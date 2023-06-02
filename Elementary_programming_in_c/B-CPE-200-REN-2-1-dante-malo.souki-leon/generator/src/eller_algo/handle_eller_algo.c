/*
** EPITECH PROJECT, 2022
** eller_algorithm
** File description:
** handle_eller_algo
*/
#include "src.h"

void debug_print(int *row, int x)
{
    for (int i = 0; i < x; i++){
        if (row[i] == WALL_I)
            z_printf("X");
        else
            z_printf("*");
    }
    z_printf("\n");
}

void handle_eller_algo(int x)
{
    int *current_row = NULL;
    int *next_row = NULL;
    int *third_row = NULL;
    current_row = set_first_row(x);
    if (!current_row)
        return;
    print_int1d(current_row, x);
    next_row = set_second_row(current_row, x);
    print_int1d(next_row, x);
    third_row = set_unique_number(next_row, x);
    print_int1d(third_row, x);
    debug_print(current_row, x);
    debug_print(next_row, x);
    debug_print(third_row, x);
    free(current_row);
    free(next_row);
    free(third_row);
}
