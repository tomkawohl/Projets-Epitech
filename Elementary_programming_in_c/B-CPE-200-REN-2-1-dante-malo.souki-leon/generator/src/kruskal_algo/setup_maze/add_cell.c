/*
** EPITECH PROJECT, 2022
** src
** File description:
** rand_case
*/
#include "src.h"

int add_cell(void)
{
    static int res = -1;
    res++;
    return (res);
}

/*
int res = 0;
res = (rand() % maze_size);
if (res <= 0)
res = 1;
*/
