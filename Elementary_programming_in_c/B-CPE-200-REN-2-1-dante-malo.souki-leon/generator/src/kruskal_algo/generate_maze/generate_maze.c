/*
** EPITECH PROJECT, 2022
** generate_maze
** File description:
** generate_maze
*/
#include "src.h"

void generate_maze(maze_data_t *maze_data)
{
    coord_t coord = {0};

    while (is_maze_done(maze_data) != TRUE) {
        coord = pick_wall(maze_data);
        break_wall(maze_data, coord.x, coord.y);
    }
    if (flag_is_perfect(FALSE, TRUE) == FALSE)
        make_maze_imperfect(maze_data);
    int2d_to_str(maze_data->maze, maze_data->m_x, maze_data->m_y);
}
