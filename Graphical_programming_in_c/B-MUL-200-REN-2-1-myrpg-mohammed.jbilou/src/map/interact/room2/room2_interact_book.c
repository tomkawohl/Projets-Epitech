/*
** EPITECH PROJECT, 2023
** map/interact/room2
** File description:
** room2_interact_book
*/
/**
 * @file room2_interact_book.c
 *
 * @brief Handle interaction with book in room2
 *
 * @date 20/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "player.h"
#include "test_area.h"
#include "game_actor.h"

static void handle_text(game_t *gm, u_int *state, bool can_press)
{
    if ((*state) > 0 && sfKeyboard_isKeyPressed(sfKeyE) && can_press == true) {
        if ((*state) == 1)
            text_list_change(gm, " Est dangereux \n", "book1");
        (*state)++;
    }
}

static void handle_last_state(game_t *gm, u_int *state, bool *activate)
{
    if ((*state) == 3) {
        text_list_find_remove(gm->list_text, "book1");
        (*state) = 0;
        (*activate) = false;
        gm->ga_event = room2_event;
        gm->event_in_progress = false;
    }
}

static void handle_activate(game_t *gm, bool *activate, bool *can_press,
    u_int *state)
{
    gm->ga_current->to_animate = 2;
    if (gm->ga_current->clock_anim == NULL)
        gm->ga_current->clock_anim = sfClock_create();
    gm->ga_event = gm->ga_current->interact;
    (*activate) = true;
    text_list_find_remove(gm->list_text, "E");
    text_list_add(gm->list_text, (text_info_t){"book1", (sfVector2i){
        gm->ga_current->pos.x, gm->ga_current->pos.y - 1}, " Caligula \n", 15,
        GUI_ASSET, TEXT_SQUARE, T_DEF});
    (*state) = 1;
    (*can_press) = false;
    gm->event_in_progress = true;
}

void room2_interact_book(game_t *gm)
{
    static bool activate = false;
    static bool can_press = true;
    static u_int state = 0;
    if (!activate && sfKeyboard_isKeyPressed(sfKeyE)
    && can_press == true && state == 0)
        handle_activate(gm, &activate, &can_press, &state);
    handle_text(gm, &state, can_press);
    if (sfKeyboard_isKeyPressed(sfKeyE))
        can_press = false;
    if (gm->event.type == sfEvtKeyReleased)
        can_press = true;
    handle_last_state(gm, &state, &activate);
}
