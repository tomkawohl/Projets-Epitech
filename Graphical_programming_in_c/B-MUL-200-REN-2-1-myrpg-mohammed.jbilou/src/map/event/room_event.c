/*
** EPITECH PROJECT, 2023
** map/room/event
** File description:
** room_event
*/
/**
 * @file room_event.c
 *
 * @brief Handle event for room
 *
 * @date 17/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"
#include "fight.h"

/*
typedef struct text_info_s {
    sfVector2i coord;
    char *text;
    u_int size;
    char *tile_asset;
    sfIntRect asset;
} text_info_t;
*/

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

static void delete_defeat_enemy(game_t *gm)
{
    if (gm->ga_current->is_defeat) {
        gm->ga->first = gm->ga_current->next;
        game_actor_remove(gm->ga);
    }
}

void room_event(game_t *gm)
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
            delete_defeat_enemy(gm);
            return;
        }
        elem = elem->next;
    }
}
