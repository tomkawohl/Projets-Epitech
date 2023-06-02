/*
** EPITECH PROJECT, 2022
** src
** File description:
** setup_maze
*/
#include "src.h"

int **setup_maze(int x, int y)
{
    int **maze = (malloc(sizeof(int *) * (y + 1)));

    if (maze == NULL)
        exit(84);
    fill_line_wall(maze, 0, x);
    for (int i = 1; i < (y - 1); i++) {
        if (i % 2 == 0)
            fill_line_wall(maze, i, x);
        else
            fill_line_way_wall(maze, i, x);
    }
    fill_line_wall(maze, (y - 1), x);
    maze[y] = NULL;
    return (maze);
}
