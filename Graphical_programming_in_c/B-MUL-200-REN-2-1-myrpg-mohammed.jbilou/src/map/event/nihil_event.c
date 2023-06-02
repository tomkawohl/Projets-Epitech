/*
** EPITECH PROJECT, 2023
** map/event
** File description:
** nihil_event
*/
/**
 * @file nihil_event.c
 *
 * @brief Handle event for nihil
 *
 * @date 22/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"

static void display_interact_button(game_t *gm, game_actor_t *ga)
{
    static bool add = false;

    if (str_cmp(ga->name, "book") == 1)
        return;
    if (ga_is_in_range(ga, gm) && add == false) {
        text_list_add(gm->list_text, (text_info_t){"E", ga->pos.x,
        ga->pos.y - 1, " E \n", 19, GUI_ASSET, TEXT_SQUARE, T_INTERACT});
        add = true;
    }
    if (!ga_is_in_range(ga, gm) && add == true) {
        text_list_find_remove(gm->list_text, "E");
        add = false;
    }
}

void nihil_event(game_t *gm)
{
    game_actor_t *elem = NULL;

    if (!gm->ga)
        return;
    if (!gm->ga->first)
        return;
    elem = gm->ga->first;
    while (elem) {
        display_interact_button(gm, elem);
        if (ga_is_in_range(elem, gm) && elem->interact != NULL) {
            gm->ga_current = elem;
            elem->interact(gm);
            return;
        }
        elem = elem->next;
    }
}
