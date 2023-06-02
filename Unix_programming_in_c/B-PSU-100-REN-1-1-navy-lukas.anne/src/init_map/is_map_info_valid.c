/*
** EPITECH PROJECT, 2022
** src
** File description:
** is_map_info_valid
*/
#include "src.h"

void fill_boat_pos_horizontal(char **boat_pos, char **map_info_2d, int i)
{
    char *buffer = malloc(sizeof(char) * 3);
    int left = to_left(map_info_2d, i);
    buffer[0] = 'a';
    buffer[1] = 'b';
    buffer[2] = '\0';
    int j = i + 2;
    char c = map_info_2d[i][2];
    char nb = map_info_2d[i][3];
    while (j != 2) {
        if (left)
            c--;
        else
            c++;
        buffer[0] = c;
        buffer[1] = nb;
        boat_pos[0] = str_recat(boat_pos[0], buffer);
        j--;
    }
    if (buffer) free(buffer);
}

void fill_boat_pos_vertical(char **boat_pos, char **map_info_2d, int i)
{
    char *buffer = malloc(sizeof(char) * 3);
    int down = to_down(map_info_2d, i);
    buffer[0] = 'a';
    buffer[1] = 'b';
    buffer[2] = '\0';
    int j = i + 2;
    char c = map_info_2d[i][2];
    int nb = my_getnbr_int(&map_info_2d[i][3]);
    char nb_char = 'a';
    while (j != 2) {
        if (down) nb++;
        else
        nb--;
        nb_char = (nb + '0');
        buffer[0] = c;
        buffer[1] = nb_char;
        boat_pos[0] = str_recat(boat_pos[0], buffer);
        j--;
    }
    if (buffer) free(buffer);
}

int check_boats_pos(char **map_info_2d, int i)
{
    char *boat_pos = NULL;
    char *dep = NULL;
    char *arr = NULL;
    int is_valid = TRUE;
    dep = my_strncpy(dep, &(map_info_2d[i][2]), 2);
    arr = my_strncpy(arr, &(map_info_2d[i][5]), 2);
    boat_pos = str_recat(boat_pos, dep);
    if (is_horizontal(map_info_2d, i))
        fill_boat_pos_horizontal(&boat_pos, map_info_2d, i);
    else
        fill_boat_pos_vertical(&boat_pos, map_info_2d, i);
    boat_pos = str_recat(boat_pos, arr);
    is_valid = init_collisions(boat_pos, map_info_2d, i);
    free(dep);
    free(arr);
    free(boat_pos);
    return (is_valid);
}

int check_map_info(char **map_info_2d)
{
    for (int i = 0; i < 4; i++){
        if (check_boats_pos(map_info_2d, i) == FALSE) {
            return (FALSE);
        }
    }
    return (TRUE);
}
