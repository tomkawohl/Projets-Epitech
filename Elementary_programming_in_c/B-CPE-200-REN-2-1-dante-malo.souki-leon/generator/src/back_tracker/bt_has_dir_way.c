/*
** EPITECH PROJECT, 2022
** src
** File description:
** bt_has_dir
*/
#include "src.h"

z_bool bt_has_dir_way(maze_data_t *maze_data, int x, int y)
{
    if (x < (maze_data->m_x - 2)) {
        if (maze_data->visit[y][x + 2] == false)
            return (true);
    }
    if (x > 1) {
        if (maze_data->visit[y][x - 2] == false)
            return (true);
    }
    if (y < (maze_data->m_y - 2)) {
        if (maze_data->visit[y + 2][x] == false)
            return (true);
    }
    if (y > 1) {
        if (maze_data->visit[y - 2][x] == false)
            return (true);
    }
    return (false);
}

coord_t back_track(maze_data_t *maze_data, coord_t pos, stack_t *stack)
{
    stack_coord_t *tmp = stack->first;
    coord_t pos_dir = pos;

    while (bt_has_dir_way(maze_data, tmp->x, tmp->y) != true) {
        stack_remove(stack);
        if (stack->first == NULL) {
            bt_is_stack_empty(TRUE, FALSE);
            break;
        }
        tmp = stack->first;
        pos_dir.x = tmp->x;
        pos_dir.y = tmp->y;
    }
    return (pos_dir);
}
