/*
** EPITECH PROJECT, 2023
** map/event
** File description:
** midlayer_event
*/
/**
 * @file midlayer_event.c
 *
 * @brief Handle event for midlayer
 *
 * @date 21/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"

void midlayer_event(game_t *gm)
{
    game_actor_t *elem = NULL;

    if (!gm->ga)
        return;
    if (!gm->ga->first)
        return;
    elem = gm->ga->first;
    while (elem) {
        if (ga_is_in_range(elem, gm) && elem->interact != NULL) {
            gm->ga_current = elem;
            elem->interact(gm);
            return;
        }
        elem = elem->next;
    }
}
