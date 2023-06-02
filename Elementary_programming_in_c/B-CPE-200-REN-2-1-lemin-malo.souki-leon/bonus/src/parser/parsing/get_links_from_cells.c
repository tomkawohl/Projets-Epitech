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
 * @date 01/04/2023
*/
#include "src.h"
#include "parser.h"

static int get_idx_rooms(info_t *info, char const *room)
{
    size_t idx = 0;

    for (int i = 0; info->cells[i]; i++, idx++) {
        if (my_strcmp(info->cells[i], room) == 0)
            return idx;
    }
    return -1;
}

static bool check_linker(info_t *info, size_t i, char **pars, size_t pos)
{
    int idx = get_idx_rooms(info, pars[pos]);

    if (idx == -1)
        return false;
    if (info->room[i].list == NULL) {
        info->room[i].list = list_int_create();
        list_int_add(info->room[i].list, idx);
    } else
        list_int_add(info->room[i].list, idx);
    return true;
}

static bool get_links(info_t *info, size_t i, size_t j, char **pars)
{
    bool check = true;

    if (str_contains_char(info->file_to_parse[j], '-') == true) {
        pars = str_to_array_separator(info->file_to_parse[j], '-', ' ');
        if (my_strcmp(pars[0], info->cells[i]) == 0)
            check = check_linker(info, i, pars, 1);
        if (my_strcmp(pars[1], info->cells[i]) == 0)
            check = check_linker(info, i, pars, 0);
        free_array_str2d(pars);
        if (check == false)
            return false;
    }
    return true;
}

static bool add_link_to_room(info_t *info, size_t i, char **pars)
{
    size_t count = 0;

    for (size_t j = 0; info->file[j]; j++) {
        if (str_contains_char(info->file[j], '-') == true)
            count++;
    }
    if (count == 0)
        return false;
    for (size_t j = 0; info->file_to_parse[j]; j++) {
        if (get_links(info, i, j, pars) == false)
            return false;
    }
    return true;
}

bool get_alls_the_rooms_linked(info_t *info)
{
    char **pars = NULL;

    for (size_t i = 0; info->cells[i]; i++) {
        if (add_link_to_room(info, i, pars) == false)
            return false;
    }
    return true;
}
