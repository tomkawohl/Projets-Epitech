/*
** EPITECH PROJECT, 2023
** map/interact/room2
** File description:
** room2_interact_chest
*/
/**
 * @file room2_interact_chest.c
 *
 * @brief Handle interaction with chest in room2
 *
 * @date 20/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "player.h"
#include "test_area.h"
#include "game_actor.h"

static void handle_event(game_t *gm)
{
    text_list_find_remove(gm->list_text, "chest");
    gm->ga_current->is_activ = false;
    gm->ga_event = room2_event;
    gm->event_in_progress = false;
}

static void handle_display(game_t *gm, bool *activate, bool *display)
{
    char *poti = "voici une potion\n";

    text_list_add(gm->list_text, (text_info_t){"chest", (sfVector2i){
    gm->ga_current->pos.x, gm->ga_current->pos.y - 1},
        poti, my_strlen(poti),
    GUI_ASSET, TEXT_SQUARE, T_DEF});
    (*display) = true;
    gm->inv->is_case_able[0] = true;

}

//SEARCH EVENT to gm->save : GENERIC
static void handle_activate(game_t *gm , bool *activate, bool *can_press)
{
    gm->ga_current->to_animate = 2;
    if (gm->ga_current->clock_anim == NULL)
        gm->ga_current->clock_anim = sfClock_create();
    gm->ga_event = gm->ga_current->interact;
    (*activate) = true;
    text_list_find_remove(gm->list_text, "E");
    (*can_press) = false;
    free(gm->save[1]);
    gm->save[1] = NULL;
    gm->save[1] = str_cat(gm->save[1], "CHEST:YES\n");
    gm->event_in_progress = true;
}

void room2_interact_chest(game_t *gm)
{
    static bool activate = false;
    static bool can_press = true;
    static bool display = false;

    if (activate == false && sfKeyboard_isKeyPressed(sfKeyE)
    && can_press == true)
        handle_activate(gm, &activate, &can_press);
    if (activate && gm->ga_current->to_animate == 0 && display == false)
        handle_display(gm, &activate, &display);
    if (activate == true && sfKeyboard_isKeyPressed(sfKeyE)
        && can_press == true && gm->ga_current->to_animate == 0)
        handle_event(gm);
    if (sfKeyboard_isKeyPressed(sfKeyE))
        can_press = false;
    if (gm->event.type == sfEvtKeyReleased)
        can_press = true;
}
