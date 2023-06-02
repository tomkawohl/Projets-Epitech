/*
** EPITECH PROJECT, 2022
** maze_data
** File description:
** maze_data_free
*/
#include "src.h"

void maze_data_free(maze_data_t *maze_data)
{
    free_array_int2d(maze_data->maze);
    free_array_int2d(maze_data->visit);
    free(maze_data);
}
