/*
** EPITECH PROJECT, 2023
** game_actor
** File description:
** game_actor_list_destroy
*/
/**
 * @file game_actor_list_destroy.c
 *
 * @brief Destroy a list of game actor
 *
 * @date 12/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"

void game_actor_list_destroy(game_actor_list_t *list)
{
    if (list == NULL)
        return;
    while (list->first && list->size != 0)
        game_actor_remove(list);
    free(list);
    list = NULL;
    return;
}
