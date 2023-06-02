/*
** EPITECH PROJECT, 2022
** src
** File description:
** bt_init_visit
*/
#include "src.h"

int **bt_init_visit(int x, int y)
{
    int **visit = NULL;

    visit = malloc(sizeof(int *) * (y+ 1));
    for (U_INT i = 0; i < (U_INT)y; i++) {
        visit[i] = malloc(sizeof(int) * x);
        for (U_INT j = 0; j < (U_INT)x; j++) {
            visit[i][j] = false;
        }
    }
    visit[y] = NULL;
    return (visit);
}

/*
int **bt_init_maze(int x, int y)
{
    int **maze = NULL;

    maze = malloc(sizeof(int *) * y + 1);
    for (U_INT i = 0; i < (U_INT)y; i++) {
        maze[i] = malloc(sizeof(int) * x);
        for (U_INT j = 0; j < (U_INT)x; j++)
            maze[i][j] = 1;
    }
    maze[y] = NULL;
    return (maze);
}
*/
