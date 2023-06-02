/*
** EPITECH PROJECT, 2023
** game_actor
** File description:
** game_actor_remove
*/
/**
 * @file game_actor_remove.c
 *
 * @brief Remove a game actor to a list of game actors
 *
 * @date 12/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"

static void delete_data(game_actor_t *actor)
{
    if (actor->name != NULL) {
        free(actor->name);
        actor->name = NULL;
    }
    if (actor->texture != NULL) {
        sfTexture_destroy(actor->texture);
        actor->texture = NULL;
    }
    if (actor->sprite != NULL) {
        sfSprite_destroy(actor->sprite);
        actor->sprite = NULL;
    }
    if (actor->clock_anim != NULL) {
        sfClock_destroy(actor->clock_anim);
        actor->clock_anim = NULL;
    }
}

void game_actor_destroy(game_actor_t *actor)
{
    if (!actor)
        return;
    delete_data(actor);
    actor->next = NULL;
    actor->prev = NULL;
    free(actor);
    actor = NULL;
}

void game_actor_remove(game_actor_list_t *list)
{
    game_actor_t *to_remove = NULL;

    if (!list)
        return;
    if (list->first == NULL)
        return;
    if (list->size == 0)
        return;
    to_remove = list->first;
    list->first = list->first->next;
    game_actor_destroy(to_remove);
    list->size--;
}
