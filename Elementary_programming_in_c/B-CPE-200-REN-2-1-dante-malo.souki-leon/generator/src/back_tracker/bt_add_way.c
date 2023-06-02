/*
** EPITECH PROJECT, 2022
** src
** File description:
** bt_add_way
*/
#include "src.h"

void bt_add_way(maze_data_t *maze_data, int *x, int *y, stack_t *stack)
{
    int current_dir = get_dir(false, true);
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    maze_data->maze[*y][*x] = 0;
    maze_data->visit[*y][*x] = true;
    stack_add(stack, *x, *y);
    (*y) -= dir[current_dir][0];
    (*x) -= dir[current_dir][1];
    if ((*x) < 0)
        (*x) += dir[current_dir][1];
    if ((*y) < 0)
        (*y) += dir[current_dir][0];
    if ((*x) > (maze_data->m_x - 1))
        (*x) += dir[current_dir][1];
    if ((*y) > (maze_data->m_y - 1))
        (*y) += dir[current_dir][0];
    maze_data->maze[*y][*x] = 0;
    maze_data->visit[*y][*x] = true;
}
