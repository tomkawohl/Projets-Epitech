/*
** EPITECH PROJECT, 2022
** src
** File description:
** init_collision
*/
#include "src.h"

int is_collision(char *boat_pos, char *boat_tmp, int k)
{
    for (int l = 0; boat_pos[l] != '\0'; l += 2) {
        char c = boat_pos[l];
        char c2 = boat_pos[l + 1];
        char c_tmp = boat_tmp[k];
        char c_tmp2 = boat_tmp[k + 1];
        if (c == c_tmp && c2 == c_tmp2)
            return (FALSE);
    }
    return (TRUE);
}

int check_collision(char *boat_tmp, char *boat_pos)
{
    for (int k = 0; boat_tmp[k] != '\0'; k += 2) {
        if (is_collision(boat_pos, boat_tmp, k) == FALSE)
            return (FALSE);
    }
    return (TRUE);
}

int init_collisions(char *boat_pos, char **map_info_2d, int i)
{
    char *dep = NULL;
    char *arr = NULL;
    char *boat_tmp = NULL;
    int collision = FALSE;
    for (int j = 0; j < 4; j++) {
        dep = my_strncpy(dep, &(map_info_2d[j][2]), 2);
        arr = my_strncpy(arr, &(map_info_2d[j][5]), 2);
        if (i != j)
            boat_tmp = str_recat(boat_tmp, dep);
        if (is_horizontal(map_info_2d, j) && i != j)
            fill_boat_pos_horizontal(&boat_tmp, map_info_2d, j);
        if (is_horizontal(map_info_2d, j) == FALSE && i != j)
            fill_boat_pos_vertical(&boat_tmp, map_info_2d, j);
        if (i != j) boat_tmp = str_recat(boat_tmp, arr);
    }
    collision = check_collision(boat_tmp, boat_pos);
    free(dep);
    free(arr);
    free(boat_tmp);
    return (collision);
}
