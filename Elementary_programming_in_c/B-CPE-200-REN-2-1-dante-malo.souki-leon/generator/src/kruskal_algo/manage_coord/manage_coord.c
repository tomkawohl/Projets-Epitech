/*
** EPITECH PROJECT, 2022
** manage_coord
** File description:
** manage_coord
*/
#include "src.h"

void manage_coord(int *x, int *y)
{
    (*y) += 2;
    (*x) += 2;
    if ((*x) % 2 == 0) {
        is_x_impair(TRUE, FALSE);
        (*x)--;
    }
    if ((*y) % 2 == 0) {
        is_y_impair(TRUE, FALSE);
        (*y)--;
    }
    return;
}
