/*
** EPITECH PROJECT, 2022
** get_info_from_buffer
** File description:
** gets info from buffer
*/
/**
 * @file get_info_from_buffer.c
 *
 * @brief get the informations from the file
 *
 * @date 29/03/2023
*/
#include "src.h"
#include "parser.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include "errors.h"

static void init_struct(info_t *info)
{
    info->cells = NULL;
    info->end = NULL;
    info->start = NULL;
    info->file = NULL;
    info->file_to_parse = NULL;
    info->rooms = NULL;
    info->room = NULL;
}

static void get_cells_from_rooms_start_end(info_t *info)
{
    size_t j = 0;

    info->nb_cells = info->j + 2;
    info->cells = malloc(sizeof(char *) * (info->nb_cells + 1));
    info->cells[info->j + 2] = NULL;
    info->cells[0] = str_cpy(info->start[0]);

    for (size_t i = 1; info->rooms[j] != NULL; i++, j++)
        info->cells[i] = str_cpy(info->rooms[j]);
    info->cells[info->j + 1] = str_cpy(info->end[0]);
}

static size_t get_nb_ants(char **file, info_t *info)
{
    size_t nb = 0;

    for (size_t i = 0; file[i]; i++){
        if (str_is_num(file[i]) == TRUE){
            nb = my_getnbr_int(file[i]);
            info->idx_to_start = i + 1;
            info->nb_ants = nb;
            return nb;
        }
    }
    return 0;
}

static bool info_to_room(info_t *info)
{
    if (info->rooms == NULL)
        return false;
    get_cells_from_rooms_start_end(info);
    if (info->cells == NULL)
        return false;
    return get_all_info_to_struc_tab(info);
}

bool get_info_from_files(info_t *info)
{
    init_struct(info);
    info->idx_to_start = 0;
    if (file_to_info(info) == false)
        return false;
    get_nb_ants(info->file, info);
    if (info->nb_ants <= 0)
        return false;
    if ((info->start = get_room(info, START, info->start)) == NULL)
        return false;
    if ((info->end = get_room(info, END, info->end)) == NULL)
        return false;
    if (info->end == NULL || info->start == NULL)
        return false;
    info->rooms = get_all_the_rooms(info);
    if (info_to_room(info) == false)
        return false;
    return check_file(info);
}
