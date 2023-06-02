/*
** EPITECH PROJECT, 2022
** array
** File description:
** print_array1d
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

/* print_int1d */
void write_space(int j, int column_size)
{
    if (j != (column_size -1))
        write(1, " ", 1);
}

void print_int1d(int *int1d, int column_size)
{
    if (!int1d)
        return;
    for (int j = 0; j < column_size; j++) {
        my_putnbr(int1d[j]);
        write_space(j, column_size);
    }
    write(1, "\n", 1);
}
