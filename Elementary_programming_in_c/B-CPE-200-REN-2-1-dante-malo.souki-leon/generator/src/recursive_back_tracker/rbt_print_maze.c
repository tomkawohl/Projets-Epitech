/*
** EPITECH PROJECT, 2022
** recursive_back_tracker
** File description:
** rbt_print_maze
*/
#include "src.h"

void rbt_print_cell(int cell)
{
    if (cell == 1)
        z_printf("X");
    else
        z_printf("*");
}

void rbt_print_maze(int **maze, int x, int y)
{
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            rbt_print_cell(maze[i][j]);
        }
        z_printf("\n");
    }
}
