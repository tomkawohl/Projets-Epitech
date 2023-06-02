/*
** EPITECH PROJECT, 2022
** src
** File description:
** fill_line_way_wall
*/
#include "src.h"

void fill_line_way_wall(int **maze, int i, int x)
{
    maze[i] = NULL;
    maze[i] = malloc(sizeof(int) * x);
    if (maze[i] == NULL)
        exit (84);
    maze[i][0] = WALL_I;
    for (int j = 1; j < x; j++) {
        if (j % 2 == 0)
            maze[i][j] = WALL_I;
        else
            maze[i][j] = add_cell();
    }
}
