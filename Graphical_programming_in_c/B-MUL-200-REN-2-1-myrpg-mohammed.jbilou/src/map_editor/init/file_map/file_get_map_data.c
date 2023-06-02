/*
** EPITECH PROJECT, 2023
** file_map
** File description:
** file_get_map_data
*/
/**
 * @file file_get_map_data.c
 *
 * @brief Get map data
 *
 * @date 08/04/2023
*/
#include "src.h"
#include "lib_will.h"

static char *get_map_data_1d(const char *file)
{
    char *map_data = NULL;

    if (!file)
        return (NULL);
    map_data = file_to_str_getline(file);
    if (!map_data)
        return (NULL);
    return (map_data);
}

char **get_map_data(const char *file)
{
    char *map_data_1d = get_map_data_1d(file);
    char **map_data = NULL;

    if (!map_data_1d)
        return (NULL);
    map_data = str1d_to_str2d(map_data_1d);
    free(map_data_1d);
    return (map_data);
}
