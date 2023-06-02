/*
** EPITECH PROJECT, 2022
** src
** File description:
** init_map
*/
#include "src.h"

void init_boats(char **map, char **map_info_2d, int i)
{
    int letter = 0;
    int n = 0;
    int j = 0;
    int k = 0;
    letter = letter_into_int(map_info_2d[i][2]);
    n = ((map_info_2d[i][3] - 48) + 1);
    while (map[n][j] != '\0') {
        if (map[n][j] != 32 && j > 1)
            k++;
        if (k == letter)
            break;
        j++;
    }
    map[n][j] = ((i + 2) + '0');
    if (is_horizontal(map_info_2d, i)) {
        init_horizontal(map, map_info_2d, i, j);
    } else {
        init_vertical(map, map_info_2d, i, j);
    }
}

int fill_map(char **map, char *map_info)
{
    char **map_info_2d = str1d_to_str2d(map_info);
    if (check_map_info(map_info_2d) == FALSE) {
        free_array_str2d(map_info_2d);
        return (FALSE);
    }
    for (int i = 0; i < 4; i++) {
        init_boats(map, map_info_2d, i);
    }
    free_array_str2d(map_info_2d);
    return (TRUE);
}

char **map_init(char *arg)
{
    char *map_info = file_to_str_getline(arg);
    char *basic_map = NULL;
    char **map = NULL;
    int is_map_info_valid = FALSE;
    if (!map_info) return (NULL);
    if (is_file_valid(map_info) == FALSE) return (NULL);
    basic_map = file_to_str_getline("src/init_map/map.txt");
    if (!basic_map) {
        free(map_info);
        return (NULL);
    }
    map = str1d_to_str2d(basic_map);
    is_map_info_valid = fill_map(map, map_info);
    free(map_info);
    free(basic_map);
    if (is_map_info_valid == FALSE) {
        free_array_str2d(map);
        return (NULL);
    }
    return (map);
}
