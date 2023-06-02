/*
** EPITECH PROJECT, 2023
** events_attack
** File description:
** Handles events for fight attack buttons
*/

#include "fight.h"

static void detect_attack(game_t *gm, sfVector2i mouse, fight_t *fight)
{
    for (size_t i = 0; i < 4; i++) {
        if (!fight->abut[i]->is_active)
            continue;
        if (mouse_over_rect(fight->abut[i]->rect[0], mouse, gm->wd) && i != 3) {
            fight->has_pl_attacked = true;
            fight->abut[i]->att_frame = 50;
            animate_pl_attack(fight, i);
            return;
        }
        if (mouse_over_rect(fight->abut[i]->rect[0], mouse, gm->wd) && i == 3) {
            fight->has_pl_attacked = true;
            animate_pl_attack(fight, i);
            return;
        }
    }
}

static void is_attack_but_clicked(game_t *gm, sfVector2i mouse, fight_t *fight)
{
    sfClock *clock = sfClock_create();
    float elapsed = sfClock_getElapsedTime(clock).microseconds;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        while (elapsed < 100000)
            elapsed = sfClock_getElapsedTime(clock).microseconds;
        sfClock_destroy(clock);
        if (mouse_over_rect(fight->abut[GO_BACK_BUT]->rect[0], mouse, gm->wd)) {
            fight->is_attacking = false;
            return;
        }
        detect_attack(gm, mouse, fight);
    }
}

static size_t choose_random_num(fight_t *fight)
{
    size_t rd_nb;

    srand(time(0));
    rd_nb = rand() % 9;
    if (rd_nb == 8) {
        rd_nb = 2;
    } else {
        rd_nb %= 2;
        fight->en_att_frame[rd_nb] = 50;
    }
    return rd_nb;
}

static void handle_enemy_attack(fight_t *fight)
{
    sfClock *clock = sfClock_create();
    float elapsed = sfClock_getElapsedTime(clock).microseconds;
    size_t rd_nb;

    for (size_t i = 0; i < 3; i++) {
        if (fight->en_att_frame[i] != 0) {
            animate_en_attack(fight, i);
            sfClock_destroy(clock);
            return;
        }
    }
    while (elapsed < 1500000)
        elapsed = sfClock_getElapsedTime(clock).microseconds;
    sfClock_destroy(clock);
    rd_nb = choose_random_num(fight);
    animate_en_attack(fight, rd_nb);
}

void is_mouse_on_attack_but(game_t *gm, sfVector2i mouse, fight_t *fight)
{
    for (size_t i = 0; i < NB_ATTACK_BUT; i++) {
        if (mouse_over_rect(fight->abut[i]->rect[0], mouse, gm->wd)) {
            fight->abut[i]->is_on_button = true;
        } else
            fight->abut[i]->is_on_button = false;
    }
    for (size_t i = 0; i < NB_ATTACK_BUT; i++) {
        if (fight->abut[i]->att_frame != 0) {
            animate_pl_attack(fight, i);
            return;
        }
    }
    if (fight->has_pl_attacked) {
        handle_enemy_attack(fight);
        return;
    }
    is_attack_but_clicked(gm, mouse, fight);
}
