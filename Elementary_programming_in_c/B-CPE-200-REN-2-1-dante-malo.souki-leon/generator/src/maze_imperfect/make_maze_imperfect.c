/*
** EPITECH PROJECT, 2022
** maze_imperfect
** File description:
** make_maze_imperfect
*/
#include "src.h"

/*
coord_t pick_wall(int **maze, int x, int y)
{
    coord_t coord = {0};
    do {
        coord.x = (rand() % x);
        coord.y = (rand() % y);
        if (coord.x == 0)
            coord.x++;
        if (coord.x == (x - 1))
            coord.x--;
        if (coord.y == 0)
            coord.y++;
        if (coord.y == (y - 1))
            coord.y--;
        coord.x = verify_x(coord);
    } while (maze[coord.y][coord.x] != WALL_I);
    return (coord);
}
*/
coord_t pick_wall_flex(maze_data_t *maze_data)
{
    coord_t coord = {0};
    int i = 0;
    int max = 0;
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
        i++;
        if (i == max)
            return ((coord_t){0, 0});
    } while (maze_data->maze[coord.y][coord.x] != WALL_I);
    return (coord);
}

void make_maze_imperfect(maze_data_t *maze_data)
{
    unsigned int wall_to_break = maze_data->m_y * 0.20;
    unsigned int i = 0;
    coord_t coord = {0, 0};
    while (i < wall_to_break) {
        coord = pick_wall_flex(maze_data);
        if (coord.x == 0 || coord.y == 0)
            return;
        maze_data->maze[coord.y][coord.x] = 0;
        i++;
    }
    return;
}
