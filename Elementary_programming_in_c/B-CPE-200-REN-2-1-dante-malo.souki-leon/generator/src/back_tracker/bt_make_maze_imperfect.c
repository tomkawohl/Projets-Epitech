/*
** EPITECH PROJECT, 2022
** src
** File description:
** bt_make_maze_imperfect
*/
#include "src.h"

coord_t bt_pick_wall(maze_data_t *maze_data)
{
    coord_t coord = {0, 0};
    int i = 0;
    int max = 5000;

    do {
        coord.x = (rand() % (maze_data->m_x - 1));
        coord.y = (rand() % (maze_data->m_y - 1));
        if (coord.x < 0)
            coord.x = 0;
        if (coord.y < 0)
            coord.y = 0;
        if (i == max)
            return ((coord_t){-1, -1});
        i++;
    } while (maze_data->maze[coord.y][coord.x] != 1);
    return (coord);
}

void bt_make_maze_imperfect(maze_data_t *maze_data)
{
    unsigned int wall_to_break = (unsigned int)maze_data->count * 0.20;
    unsigned int i = 0;
    coord_t coord = {0, 0};

    if (wall_to_break == 0)
        return;
    while (i < wall_to_break) {
        coord = bt_pick_wall(maze_data);
        if (coord.x == -1)
            break;
        maze_data->maze[coord.y][coord.x] = 0;
        maze_data->count--;
        if (maze_data->count <= 0)
            break;
        i++;
    }
    return;
}
