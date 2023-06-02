/*
** EPITECH PROJECT, 2022
** rooms_to_structure.c
** File description:
** rooms to structure
*/
/**
 * @file rooms_to_structure.c
 *
 * @brief get the rooms in the file and put them in the structure
 *
 * @date 30/03/2023
*/
#include "src.h"
#include "parser.h"

char **get_room(info_t *info, char *const to_find, char **room)
{
    room = NULL; ;

    for (size_t i = info->idx_to_start; info->file[i]; i++){
        if (my_strcmp(info->file[i], to_find) == 0 && info->file[i + 1]
        && info->file[i + 2] && info->file[i + 3]){
            room = malloc(sizeof(char *) * (NB_COLS + 1));
            room[NB_COLS] = NULL;
            room[0] = str_cpy(info->file[i + 1]);
            room[1] = str_cpy(info->file[i + 2]);
            room[2] = str_cpy(info->file[i + 3]);
        }
    }
    return room;
}

static size_t count_nb_rooms(char **file, info_t *info)
{
    info->count = 0;

    for (size_t i = info->idx_to_start; file[i]; i++)
        if (file[i][0] != '#'
        && str_contains_char(info->file_to_parse[i], '-') == false
        && my_strcmp(file[i - 1], START) != 0
        && my_strcmp(file[i - 1], END) != 0)
            info->count++;
    return info->count;
}

static void fill_rooms(info_t *info, size_t i, char **room, char **pars)
{
    if (info->file_to_parse[i][0] == '#')
        return;
    if (str_contains_char(info->file_to_parse[i], '-') == true)
        return;
    if (my_strcmp(info->file_to_parse[i - 1], START) == 0)
        return;
    if (my_strcmp(info->file_to_parse[i - 1], END) == 0)
        return;
    pars = str_to_array_separator(info->file_to_parse[i], ' ', '\t');
    room[info->j] = str_cpy(pars[0]);
    info->j++;
    if (pars)
        free_array_str2d(pars);
}

char **get_all_the_rooms(info_t *info)
{
    char **pars = NULL;
    size_t nb_rooms = count_nb_rooms(info->file_to_parse, info);
    char **room = malloc(sizeof(char *) * (nb_rooms + 1));

    info->j = 0;
    if (check_malloc(room, "get_info_from_buffer.c") == 1)
        return NULL;
    room[nb_rooms] = NULL;
    for (size_t i = info->idx_to_start; info->file_to_parse[i]; i++)
        fill_rooms(info, i, room, pars);
    return room;
}
