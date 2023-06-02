/*
** EPITECH PROJECT, 2022
** src
** File description:
** print_final_maze_int
*/
#include "src.h"

void print_cell(int ceil)
{
    if (ceil != -1)
        z_printf("*");
    else
        z_printf("X");
}

void print_final_maze_int(int **maze, int x, int y)
{
    for (int i = 1; i < (y - 1); i++) {
        for (int j = 1; j < (x - 1); j++) {
            print_cell(maze[i][j]);
        }
        z_printf("\n");
    }
}
