/*
** EPITECH PROJECT, 2023
** check_positions.c
** File description:
** check if the room has the good positions
*/
/**
 * @file check_positions.c
 *
 * @brief check if the room has the good positions
 *
 * @date 30/03/2023
*/
#include "src.h"
#include "parser.h"

static bool check_pos_room(info_t *info, size_t j, char **pars)
{
    if (pars[1] && pars[2]){
        info->room[j].x = my_getnbr_int(pars[1]);
        info->room[j].y = my_getnbr_int(pars[2]);
    } else {
        free_array_str2d(pars);
        return false;
    }
    return true;
}

bool get_position_start_end(info_t *info, char const *to_find, size_t j)
{
    char **pars = NULL;
    size_t count = 0;
    char **file = info->file_to_parse;

    for (size_t i = info->idx_to_start; file[i]; i++){
        if (file[i][0] != '#' && str_contains_char(file[i], '-') == false
        && my_strcmp(file[i - 1], to_find) == 0) {
            pars = str_to_array_separator(file[i], ' ', '\t');
            count++;
        }
        if (count > 0 && check_pos_room(info, j, pars) == false)
            return false;
        if (count > 0 && check_pos_room(info, j, pars) == true)
            break;
        count = 0;
    }
    if (pars)
        free_array_str2d(pars);
    return true;
}

bool check_same_pos(info_t *info, size_t i)
{
    for (size_t j = i + 1; j < info->nb_cells; j++){
        if (info->room[j].x == info->room[i].x
        && info->room[j].y == info->room[i].y)
            return false;
    }
    return true;
}

bool check_if_pos_exist(char **pars, info_t *info, size_t *j)
{
    if (pars[1] && pars[2]){
        info->room[*j].x = my_getnbr_int(pars[1]);
        info->room[*j].y = my_getnbr_int(pars[2]);
        free_array_str2d(pars);
        *j += 1;
    } else {
        free_array_str2d(pars);
        return false;
    }
    return true;
}
