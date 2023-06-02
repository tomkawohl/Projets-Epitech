/*
** EPITECH PROJECT, 2022
** generate_maze
** File description:
** pick_wall
*/
#include "src.h"

int verify_x(coord_t coord)
{
    if (coord.y % 2 == 0) {
        if (coord.x % 2 == 0)
            return (coord.x - 1);
    }
    return (coord.x);
}

coord_t pick_wall(maze_data_t *maze_data)
{
    coord_t coord = {0};
    do {
        coord.x = (rand() % maze_data->m_x);
        coord.y = (rand() % maze_data->m_y);
        if (coord.x == 0)
            coord.x++;
        if (coord.x == (maze_data->m_x - 1))
            coord.x--;
        if (coord.y == 0)
            coord.y++;
        if (coord.y == (maze_data->m_y - 1))
            coord.y--;
        coord.x = verify_x(coord);
    } while (maze_data->maze[coord.y][coord.x] != WALL_I);
    return (coord);
}
