/*
** EPITECH PROJECT, 2023
** game_actor
** File description:
** game_actor_list_event
*/
/**
 * @file game_actor_list_event.c
 *
 * @brief Handle event for game_actor
 *
 * @date 12/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"

void game_actor_list_event(game_t *gm, sfEvent event)
{
    game_actor_t *elem = NULL;

    if (!gm->ga)
        return;
    if (!gm->ga->first)
        return;
    elem = gm->ga->first;
    while (elem) {
        w_printf("elem->name = %s\n", elem->name);
        if (ga_is_in_range(elem, gm) && elem->interact != NULL) {
            elem->interact(gm);
            return;
        }
        elem = elem->next;
    }
}
