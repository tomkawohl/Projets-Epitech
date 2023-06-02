/*
** EPITECH PROJECT, 2023
** game_actor
** File description:
** game_actor_list_create
*/
/**
 * @file game_actor_list_create.c
 *
 * @brief Create a list of game_actor
 *
 * @date 12/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"

game_actor_list_t *game_actor_list_create(void)
{
    game_actor_list_t *list = malloc(sizeof(*list));

    if (!verify_malloc(list, "gae_actor_list_create"))
        return (NULL);
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
    return (list);
}
