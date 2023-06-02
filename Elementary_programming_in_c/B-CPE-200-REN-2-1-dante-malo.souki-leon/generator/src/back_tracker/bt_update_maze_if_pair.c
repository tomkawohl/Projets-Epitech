/*
** EPITECH PROJECT, 2022
** src
** File description:
** bt_update_maze_if_pair
*/
#include "src.h"

void bt_updade_maze_if_pair(maze_data_t *maze_data)
{
    if (maze_data->m_x % 2 != 0)
        return;
    if (maze_data->m_y % 2 != 0)
        return;
    if (maze_data->m_y - 2 < 0)
        return;
    maze_data->maze[maze_data->m_y - 2][maze_data->m_x - 1] = 0;
}
