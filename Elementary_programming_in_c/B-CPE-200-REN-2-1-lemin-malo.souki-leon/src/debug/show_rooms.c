/*
** EPITECH PROJECT, 2022
** check_file.c
** File description:
** check file
*/

#include "src.h"
#include "parser.h"

void show_rooms(info_t *info)
{
    for (size_t i = 0; i < info->nb_cells; i++) {
        my_printf("-------[ROOM]-------\n\n");
        my_printf("NAME [%s]   |   INDEX [%d]\n", info->room[i].name, i);
        my_printf("X = [%d] | Y = %d\n", info->room[i].x, info->room[i].y);
        my_printf("LINKED TO:\n");
        list_int_display(info->room[i].list);
        my_printf("\n--------------------\n\n");
    }
}
