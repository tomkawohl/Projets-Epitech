/*
** EPITECH PROJECT, 2023
** events_fight_menu
** File description:
** Handles events for fight menu buttons
*/

#include "fight.h"

static void is_menu_but_clicked(game_t *gm, sfVector2i mouse, fight_t *fight)
{
    sfClock *clock = sfClock_create();
    float elapsed = sfClock_getElapsedTime(clock).microseconds;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        while (elapsed < 100000)
            elapsed = sfClock_getElapsedTime(clock).microseconds;
        sfClock_destroy(clock);
        if (mouse_over_rect(fight->fbut[FIGHT_BUT]->rect[0], mouse, gm->wd)) {
            fight->is_attacking = true;
            return;
        }
        if (mouse_over_rect(fight->fbut[RUN_BUT]->rect[0], mouse, gm->wd)) {
            fight->is_finished = true;
            fight->has_pl_win = false;
            return;
        }
    }
}

void is_mouse_on_menu_but(game_t *gm, sfVector2i mouse, fight_t *fight)
{
    for (size_t i = 0; i < NB_FIGHT_MENU_BUT; i++) {
        if (mouse_over_rect(fight->fbut[i]->rect[0], mouse, gm->wd)) {
            fight->fbut[i]->is_on_button = true;
        } else {
            fight->fbut[i]->is_on_button = false;
        }
    }
    is_menu_but_clicked(gm, mouse, fight);
}
