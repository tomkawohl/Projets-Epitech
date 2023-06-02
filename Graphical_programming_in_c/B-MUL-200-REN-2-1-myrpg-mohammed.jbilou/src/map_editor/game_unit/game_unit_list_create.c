/*
** EPITECH PROJECT, 2023
** game_unit
** File description:
** game_unit_list_create
*/
/**
 * @file game_unit_list_create.c
 *
 * @brief Create a game unit list
 *
 * @date 16/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_unit.h"

game_unit_list_t *game_unit_list_create(void)
{
    game_unit_list_t *list = malloc(sizeof(*list));

    if (!verify_malloc(list, "game_unit_list_create"))
        return (NULL);
    list->first = NULL;
    list->end = NULL;
    list->size = 0;
    return (list);
}
