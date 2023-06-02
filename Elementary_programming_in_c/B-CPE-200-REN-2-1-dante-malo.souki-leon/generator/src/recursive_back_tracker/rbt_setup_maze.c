/*
** EPITECH PROJECT, 2022
** recursive_back_tracker
** File description:
** rbt_setup_maze
*/
#include "src.h"

int **rbt_setup_maze(int x, int y)
{
    int **maze = NULL;
    maze = malloc(sizeof(int *) * (y + 1));
    if (!maze)
        return (NULL);
    for (int i = 0; i < y; i++) {
        maze[i] = malloc(sizeof(int) * x);
        for (int j = 0; j < x; j++) {
            maze[i][j] = 1;
        }
    }
    maze[y] = NULL;
    return (maze);
}
