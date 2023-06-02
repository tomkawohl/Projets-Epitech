/*
** EPITECH PROJECT, 2022
** src
** File description:
** fill_line_wall
*/
#include "src.h"

/* fill a line with WALL */
void fill_line_wall(int **maze, int i, int x)
{
    maze[i] = NULL;
    maze[i] = malloc(sizeof(int) * x);
    if (maze[i] == NULL)
        exit(84);
    for (int j = 0; j < x; j++) {
        maze[i][j] = WALL_I;
    }
}
