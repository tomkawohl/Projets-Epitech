/*
** EPITECH PROJECT, 2023
** detect_mouse_on_fight_but
** File description:
** Handles events for a fight
*/

#include "fight.h"

static void detect_die(fight_t *fight)
{
    if (fight->pl->is_dead) {
        animate_pl_die(fight);
        fight->has_charac_died = true;
        return;
    }
    if (fight->en->is_dead) {
        animate_en_die(fight);
        fight->has_charac_died = true;
        return;
    }
    return;
}

void handle_fight_events(game_t *gm, fight_t *fight)
{
    detect_die(fight);
    if (fight->has_charac_died)
        return;
    while (sfRenderWindow_pollEvent(gm->wd, &(fight->event))) {
        fight->mouse = sfMouse_getPositionRenderWindow(gm->wd);
        if (fight->event.type == sfEvtClosed) {
            fight->is_finished = true;
            return;
        }
    }
    if (!fight->is_attacking) {
        is_mouse_on_menu_but(gm, fight->mouse, fight);
    } else {
        is_mouse_on_attack_but(gm, fight->mouse, fight);
    }
}
