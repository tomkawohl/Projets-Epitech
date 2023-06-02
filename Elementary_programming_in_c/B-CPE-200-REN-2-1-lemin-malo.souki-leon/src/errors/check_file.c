/*
** EPITECH PROJECT, 2022
** check_file.c
** File description:
** check file
*/

#include "src.h"
#include "parser.h"

static bool check_name(info_t *info, size_t i)
{
    for (size_t j = i + 1; j < info->nb_cells; j++) {
        if (my_strcmp(info->room[i].name, info->room[j].name) == 0)
            return false;
    }
    return true;
}

static bool check_same_name_room(info_t *info)
{
    for (size_t i = 0; i < info->nb_cells; i++){
        if (i + 1 == info->nb_cells)
            break;
        if (check_name(info, i) == false)
            return false;
    }
    return true;
}

bool check_file(info_t *info)
{
    size_t count = 0;

    for (int i = 0; info->file[i] != NULL; i++){
        if (my_strcmp(info->file[i], "##start") == 0)
            count++;
        if (my_strcmp(info->file[i], "##end") == 0)
            count++;
    }
    if (check_same_name_room(info) == false)
        return false;
    if (count == 2)
        return true;
    return false;
}
