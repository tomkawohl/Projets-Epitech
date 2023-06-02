/*
** EPITECH PROJECT, 2022
** generate_maze
** File description:
** merge_way
*/
#include "src.h"
/*
long long int merge_ceil(int **maze, int ceil_1, int ceil_2, coord_t coord)
{
    if (maze[coord.y][coord.x] == ceil_2) {
        maze[coord.y][coord.x] = ceil_1;
        return (1);
    }
    return (0);
}

void merge_way(int **maze, int x, int ceil_1, int ceil_2)
{
    long long int merge = 0;
    long long int prev_merge = 0;
    int no_merge = 0;
    for (int i = 0; maze[i] != NULL; i++) {
        for (int j = 0; j < x; j++) {
            merge += merge_ceil(maze, ceil_1, ceil_2, (coord_t){i, j});
        }
        if (merge != 0 && prev_merge != 0 && merge == prev_merge)
            no_merge++;
        if (no_merge == 2)
            return;
        prev_merge = merge;
    }
}
*/

/*
void merge_way(int **maze, coord_t limit, coord_t coord, int number)
{
    if (coord.x <= 0 || coord.x > (limit.x - 1) || coord.y <= 0 ||
    coord.y > (limit.y - 1))
        return;
    if (maze[coord.y][coord.x] == WALL_I)
        return;
    if (maze[coord.y][coord.x] == number)
        return;
    maze[coord.y][coord.x] = number;
    merge_way(maze, limit, (coord_t){coord.x + 1, coord.y}, number);
    merge_way(maze, limit, (coord_t){coord.x - 1, coord.y}, number);
    merge_way(maze, limit, (coord_t){coord.x, coord.y + 1}, number);
    merge_way(maze, limit, (coord_t){coord.x, coord.y - 1}, number);
}
*/
/*
void merge_way(int **maze, coord_t limit, coord_t coord, int number)
{
    int x = 0;
    int y = 0;
    int axes_y[] = {coord.y + 1, coord.y - 1, coord.y, coord.y};
    int axes_x[] = {coord.x, coord.x, coord.x + 1, coord.x - 1};
    for (int index = 0; index < 4; index++) {
        y = axes_y[index];
        x = axes_x[index];
        if (x > 0 && x < (limit.x - 1) && y > 0 && y < (limit.y - 1)
        && maze[y][x] != WALL_I
        && (maze[y][x] != number)) {
            maze[y][x] = number;
            merge_way(maze, limit, (coord_t){x, y}, number);
        }
    }
}
*/

void merge_way(maze_data_t *maze_data, int x, int y, int number)
{
    int axes_y[] = {y + 1, y - 1, y, y};
    int axes_x[] = {x, x, x + 1, x - 1};
    for (int index = 0; index < 4; index++) {
        y = axes_y[index];
        x = axes_x[index];
        if (x > 0 && x < (maze_data->m_x - 1) && y > 0
        && y < (maze_data->m_y - 1)
        && maze_data->maze[y][x] != WALL_I
        && (maze_data->maze[y][x] != number)) {
            maze_data->maze[y][x] = number;
            merge_way(maze_data, x, y, number);
        }
    }
}
