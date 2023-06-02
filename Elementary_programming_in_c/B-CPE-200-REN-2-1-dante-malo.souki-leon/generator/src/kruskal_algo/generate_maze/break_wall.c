/*
** EPITECH PROJECT, 2022
** generate_maze
** File description:
** break_wall
*/
#include "src.h"

void break_wall_ver(int **maze, coord_t coord)
{
    int rand_nb = rand() % 10;
    if (rand_nb % 2 != 0) {
        maze[coord.y - 1][coord.x] = maze[coord.y + 1][coord.x];
        maze[coord.y][coord.x] = maze[coord.y + 1][coord.x];
    } else {
        maze[coord.y + 1][coord.x] = maze[coord.y - 1][coord.x];
        maze[coord.y][coord.x] = maze[coord.y - 1][coord.x];
    }
}

void break_wall_hor(int **maze, coord_t coord)
{
    int rand_nb = rand() % 10;
    if (rand_nb % 2 != 0) {
        maze[coord.y][coord.x - 1] = maze[coord.y][coord.x + 1];
        maze[coord.y][coord.x] = maze[coord.y][coord.x + 1];
    } else {
        maze[coord.y][coord.x + 1] = maze[coord.y][coord.x - 1];
        maze[coord.y][coord.x] = maze[coord.y][coord.x - 1];
    }
}

void break_wall(maze_data_t *maze_data, int x, int y)
{
    if (y % 2 == 0) {
        if (maze_data->maze[y - 1][x] != maze_data->maze[y + 1][x]) {
            maze_data->maze[y][x] = 0;
            merge_way(maze_data, x, y, maze_data->maze[y + 1][x]);
            return;
        }
    } else {
        if (maze_data->maze[y][x - 1] != maze_data->maze[y][x + 1]) {
            maze_data->maze[y][x] = 0;
            merge_way(maze_data, x, y, maze_data->maze[y][x + 1]);
            return;
        }
    }
}
