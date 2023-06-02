/*
** EPITECH PROJECT, 2023
** game_unit
** File description:
** game_unit_list_destroy
*/
/**
 * @file game_unit_list_destroy.c
 *
 * @brief Destroy a game_unit_list_t *
 *
 * @date 16/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_unit.h"

void game_unit_list_clear(game_unit_list_t *list)
{
    if (list == NULL)
        return;
    if (list->first == NULL)
        return;
    while (list->first)
        game_unit_list_remove(list);
}

void game_unit_list_destroy(game_unit_list_t *list)
{
    if (list == NULL)
        return;
    while (list->first)
        game_unit_list_remove(list);
    free(list);
    list = NULL;
}
