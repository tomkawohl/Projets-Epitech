/*
** EPITECH PROJECT, 2022
** generate_maze
** File description:
** is_maze_done
*/
#include "src.h"

int is_line_done(int *maze_line, int x, int nb)
{
    for (int i = 0; i < x; i++) {
        if (maze_line[i] != WALL_I && maze_line[i] != nb)
            return (FALSE);
    }
    return (TRUE);
}

int is_maze_done(maze_data_t *maze_data)
{
    if (maze_data->maze[1][1] !=
    maze_data->maze[maze_data->m_y - 2][maze_data->m_x - 2])
        return (FALSE);
    return (TRUE);
}

/*
int is_maze_done(int **maze, int x)
{
    int nb = maze[1][1];
    for (int i = 0; maze[i] != NULL; i++) {
        if (is_line_done(maze[i], x, nb) == FALSE)
            return (FALSE);
    }
    return (TRUE);
}
*/
