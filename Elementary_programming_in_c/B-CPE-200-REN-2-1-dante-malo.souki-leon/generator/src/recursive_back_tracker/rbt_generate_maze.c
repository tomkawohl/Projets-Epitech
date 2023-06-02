/*
** EPITECH PROJECT, 2022
** recursive_back_tracker
** File description:
** rbt_generate_maze
*/
#include "src.h"

void check_cell(int **maze, int x, int y, coord_t limit)
{
    if (x == limit.x - 1 && y == limit.y - 1)
        maze[y][x] = 0;
}

void rbt_generate_maze(int **maze, int y, int x, coord_t lim)
{
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int go_dir = 0;
    int go_y = 0;
    int go_x = 0;
    int visit = 0;
    maze[y][x] = 0;
    for (int i = 0; i < 4; i++) {
        go_dir = (rand() % 4);
        go_y = y + dir[go_dir][0] + 1;
        go_x = x + dir[go_dir][1] + 1;
        if (go_y >= 0 && go_y < lim.y && go_x >= 0 && go_x < lim.x
        && maze[go_y][go_x] != 0 ) {
            visit++;
            maze[y + dir[go_dir][0] / 2][x + dir[go_dir][1] / 2] = 0;
            rbt_generate_maze(maze, go_y, go_x, lim);
        }
    }
    if (visit <= 1 && y != 0 && x != 0 && y != (lim.y - 1) && x != (lim.x- 1))
        maze[y][x] = 1;
    check_cell(maze, x, y, lim);
}
