/*
** EPITECH PROJECT, 2022
** maze_data
** File description:
** maze_data_init
*/
#include "src.h"

maze_data_t *maze_data_init(int x, int y)
{
    maze_data_t *maze_data = NULL;
    maze_data = malloc(sizeof(maze_data_t));
    if (!maze_data)
        return (NULL);
    maze_data->maze = setup_maze(x, y);
    maze_data->m_x = x;
    maze_data->m_y = y;
    return (maze_data);
}
