/*
** EPITECH PROJECT, 2022
** src
** File description:
** bt_is_cell_valid
*/
#include "src.h"

z_bool verify_cell(maze_data_t *maze_data, int x, int y, int dir)
{
    if (y < (maze_data->m_y - 1) && dir != BOT) {
        if (maze_data->visit[y + 1][x] == true)
            return (false);
    }
    if (y > 0 && (dir != 1) && dir != TOP) {
        if (maze_data->visit[y - 1][x] == true)
            return (false);
    }
    if (x < (maze_data->m_x - 1) && dir != LEFT) {
        if (maze_data->visit[y][x + 1] == true)
            return (false);
    }
    if (x > 0 && dir != RIGHT) {
        if (maze_data->visit[y][x - 1] == true && (dir != 0))
            return (false);
    }
    return (true);
}

z_bool bt_is_cell_valid(maze_data_t *maze_data, int x, int y)
{
    int dir = get_dir(false, true);

    if (x < (maze_data->m_x - 1) && (dir != LEFT))
        if (maze_data->visit[y][x + 1] == false
        && verify_cell(maze_data, x + 1, y, RIGHT))
            return (true);
    if (x > 0 && (dir != RIGHT))
        if (maze_data->visit[y][x - 1] == false
        && verify_cell(maze_data, x - 1, y, LEFT))
            return (true);
    if (y < (maze_data->m_y - 1) && (dir != TOP))
        if (maze_data->visit[y + 1][x] == false
        && verify_cell(maze_data, x, y + 1, BOT))
            return (true);
    if (y > 0 && (dir != BOT))
        if (maze_data->visit[y - 1][x] == false
        && verify_cell(maze_data, x, y - 1, TOP))
            return (true);
    return (false);
}
