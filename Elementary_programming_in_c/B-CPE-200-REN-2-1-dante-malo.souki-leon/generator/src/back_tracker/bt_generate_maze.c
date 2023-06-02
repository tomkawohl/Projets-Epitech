/*
** EPITECH PROJECT, 2022
** src
** File description:
** bt_generate_maze
*/
#include "src.h"

int get_dir(int set, int get)
{
    static int dir = 0;
    if (get)
        return (dir);
    dir = set;
    return (set);
}

coord_t choose_dir(maze_data_t *maze_data, int x, int y)
{
    int dir[4][2] = {{0, 2}, {2, 0}, {0, -2}, {-2, 0}};
    int rand_dir = 0;
    coord_t coord = {0, 0};

    do {
        rand_dir = (rand() % 4);
        coord.y = (dir[rand_dir][0] + y);
        coord.x = (dir[rand_dir][1] + x);
        if (x < 2 && coord.x < 0)
            coord.x -= dir[rand_dir][1];
        if (y < 2 && coord.y < 0)
            coord.y -= dir[rand_dir][0];
        if (x > (maze_data->m_x - 3) && coord.x > (maze_data->m_x - 1))
            coord.x -= dir[rand_dir][1];
        if (y > (maze_data->m_y - 3) && coord.y > (maze_data->m_y - 1))
            coord.y -= dir[rand_dir][0];
    } while (maze_data->visit[coord.y][coord.x] == true);
    get_dir(rand_dir, false);
    return (coord);
}

void bt_generate_maze(maze_data_t *maze_data, stack_t *stack, int x, int y)
{
    coord_t pos = {x, y};
    maze_data->maze[y][x] = 0;
    maze_data->visit[y][x] = true;
    maze_data->count--;
    stack_add(stack, pos.x, pos.y);
    get_dir(1, false);
    while (maze_data->count > 0) {
        pos = back_track(maze_data, pos, stack);
        if (bt_is_stack_empty(FALSE, TRUE)) break;
        pos = choose_dir(maze_data, pos.x, pos.y);
        x = pos.x;
        y = pos.y;
        bt_add_way(maze_data, &x, &y, stack);
        maze_data->count -= 2;
    }
    maze_data->maze[maze_data->m_y - 1][maze_data->m_x - 1] = 0;
    bt_updade_maze_if_pair(maze_data);
    if (flag_is_perfect(false, true) == false)
        bt_make_maze_imperfect(maze_data);
    return;
}
