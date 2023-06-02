/*
** EPITECH PROJECT, 2022
** rooms_linker.c
** File description:
** get the linkers in the room
*/
/**
 * @file rooms_linker.c
 *
 * @brief get the linkers in the file and set them in the structure
 *
 * @date 30/03/2023
*/
#include "src.h"
#include "parser.h"

static bool get_info_positions(info_t *info, size_t j)
{
    char **pars = NULL;
    char **file = info->file_to_parse;
    size_t count = 0;

    if (get_position_start_end(info, START, 0) == false)
        return false;
    if (get_position_start_end(info, END, info->nb_cells - 1) == false)
        return false;
    for (size_t i = info->idx_to_start; file[i]; i++){
        if (file[i][0] != '#' && str_contains_char(file[i], '-') == false
        && my_strcmp(file[i - 1], START) != 0
        && my_strcmp(file[i - 1], END) != 0) {
            pars = str_to_array_separator(file[i], ' ', '\t');
            count++;
        }
        if (count > 0 && check_if_pos_exist(pars, info, &j) == false)
            return false;
        count = 0;
    }
    return true;
}

bool get_all_info_to_struc_tab(info_t *info)
{
    size_t j = 1;
    info->room = malloc(sizeof(rooms_t) * (info->nb_cells));

    for (size_t i = 0, j = 0; info->cells[i]; i++, j++) {
        info->room[j].list = NULL;
        info->room[j].name = str_cpy(info->cells[i]);
    }
    if (get_info_positions(info, j) == false)
        return false;
    for (size_t i = 0; i < info->nb_cells; i++) {
        if (check_same_pos(info, i) == false)
            return false;
    }
    if (get_alls_the_rooms_linked(info) == false)
        return false;
    return true;
}
