/*
** EPITECH PROJECT, 2023
** map/interact
** File description:
** outside_interact_npc
*/
/**
 * @file outside_interact_npc.c
 *
 * @brief Handle interaction with npc of outside
 *
 * @date 22/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "player.h"
#include "test_area.h"
#include "game_actor.h"
#include "npc.h"

static void handle_activate(game_t *gm, bool *can_press,
    u_int *state)
{
    text_list_add(gm->list_text, (text_info_t){"dialog", (sfVector2i){
        gm->ga_current->pos.x, gm->ga_current->pos.y - 1}, " Attention \n", 15,
        GUI_ASSET, TEXT_SQUARE, T_DEF});
    (*state) = 1;
    (*can_press) = false;
}

static void handle_state(game_t *gm, bool *can_press, u_int *state)
{
    sfVector2f pos = {0, 0};

    if (sfKeyboard_isKeyPressed(sfKeyE) && (*can_press)) {
        if ((*state) == 1)
            text_list_change(gm, " A Caligula \n","dialog");
        if ((*state) == 2) {
            text_list_change(gm, " Ca marche \n", "dialog");
            text_set_pos(gm->list_text, "dialog", (sfVector2i){gm->pl->pos.x,
                gm->pl->pos.y - 1});
        }
        (*state)++;
    }
}

static int handle_event(game_t *gm)
{
    static bool can_press = true;
    static u_int state = 0;

    if (state == 0)
        handle_activate(gm, &can_press, &state);
    else
        handle_state(gm, &can_press, &state);
    if (state == 4) {
        text_list_find_remove(gm->list_text, "dialog");
        return (1);
    }
    if (sfKeyboard_isKeyPressed(sfKeyE))
        can_press = false;
    if (gm->event.type == sfEvtKeyReleased)
        can_press = true;
    return (0);
}

void outside_interact_npc(game_t *gm)
{
    static bool exclam = false;
    static bool arrived = false;

    gm->event_in_progress = true;
    gm->ga_event = gm->ga_current->interact;
    if (exclam == false)
        if (npc_exclamation(gm) != 1)
            return;
    exclam = true;
    if (!arrived && npc_move_ver1(gm->ga_current, (sfVector2i){gm->pl->pos.x,
        gm->pl->pos.y - 1}) != 1)
        return;
    arrived = true;
    gm->ga_current->pos = (sfVector2i){gm->pl->pos.x, gm->pl->pos.y - 1};
    if (handle_event(gm) != 1)
        return;
    gm->event_in_progress = false;
    gm->ga_current->is_activ = false;
    gm->ga_event = outside_event;
}
