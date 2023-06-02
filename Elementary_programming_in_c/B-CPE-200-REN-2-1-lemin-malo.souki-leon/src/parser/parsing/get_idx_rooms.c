/*
** EPITECH PROJECT, 2023
** get_idx_rooms.c
** File description:
** get_idx_rooms
*/

#include "src.h"
#include "parser.h"

int get_idx_rooms(info_t *info, char const *room)
{
    size_t idx = 0;

    for (int i = 0; info->cells[i]; i++, idx++) {
        if (my_strcmp(info->cells[i], room) == 0)
            return idx;
    }
    return -1;
}
