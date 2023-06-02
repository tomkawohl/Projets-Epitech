/*
** EPITECH PROJECT, 2022
** src
** File description:
** free_program.c
*/
/**
 * @file destroy_program.c
 *
 * @brief Destroys all the elements that have been alloc'd
 *
 * @date 28/03/2023
*/
#include "src.h"
#include "parser.h"

static void destroy_room(info_t *info)
{
    if (info->room == NULL)
        return;
    for (size_t i = 0; i < info->nb_cells; i++){
        free(info->room[i].name);
        list_int_clear(info->room[i].list);
    }
    free(info->room);
}

static void destroy_info(info_t *info)
{
    if (info->rooms)
        free_array_str2d(info->rooms);
    if (info->end)
        free_array_str2d(info->end);
    if (info->start)
        free_array_str2d(info->start);
    if (info->file)
        free_array_str2d(info->file);
    if (info->file_to_parse)
        free_array_str2d(info->file_to_parse);
    if (info->cells)
        free_array_str2d(info->cells);
    destroy_room(info);
    free(info);
}

void destroy_program(info_t *info, graph_element_t *graph)
{
    destroy_info(info);
    if (graph != NULL)
        graph_destroy(graph);
}
