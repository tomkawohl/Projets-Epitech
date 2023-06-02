/*
** EPITECH PROJECT, 2023
** game_unit
** File description:
** game_unit_list_remove
*/
/**
 * @file game_unit_list_remove.c
 *
 * @brief Remove a game unit to a list
 *
 * @date 16/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_unit.h"

void game_unit_remove(game_unit_t *game_unit)
{
    if (!game_unit)
        return;
    if (game_unit->sprite != NULL) {
        sfSprite_destroy(game_unit->sprite);
        game_unit->sprite = NULL;
    }
    if (game_unit->texture) {
        sfTexture_destroy(game_unit->texture);
        game_unit->texture = NULL;
    }
    free(game_unit);
    game_unit = NULL;
}

void game_unit_list_remove(game_unit_list_t *list)
{
    game_unit_t *to_remove = NULL;

    if (list == NULL)
        return;
    if (list->first == NULL)
        return;
    to_remove = list->first;
    list->first = list->first->next;
    game_unit_remove(to_remove);
    list->size--;
    return;
}
