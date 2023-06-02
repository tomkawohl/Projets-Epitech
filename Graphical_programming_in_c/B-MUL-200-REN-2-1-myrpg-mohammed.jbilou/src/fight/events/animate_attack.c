/*
** EPITECH PROJECT, 2023
** animate_player_attack
** File description:
** Handles attack animation
*/

#include "fight.h"

static void reset_pl_sprite(fight_t *fight, size_t i)
{
    sfClock *clock = sfClock_create();
    float elapsed = sfClock_getElapsedTime(clock).microseconds;

    while (elapsed < 500000 && i != ATT_FOUR_BUT)
        elapsed = sfClock_getElapsedTime(clock).microseconds;
    sfClock_destroy(clock);
    fight->pl->rect.left = 0;
    fight->pl->rect.top = 0;
    fight->abut[i]->att_frame = 0;
    sfSprite_setPosition(fight->pl->sprite, PLAYER_POS);
    sfSprite_setPosition(fight->pl->life_bar->sprite, PL_LIFE_HUD_POS);
    sfRectangleShape_setPosition(fight->pl->life_bar->rect, PL_LIFE_BAR_POS);
    update_hp(fight, i, 0);
}

void animate_pl_attack(fight_t *fight, size_t i)

{
    sfClock *clock = sfClock_create();
    float elapsed = sfClock_getElapsedTime(clock).microseconds;

    while (elapsed < 100000)
        elapsed = sfClock_getElapsedTime(clock).microseconds;
    sfClock_destroy(clock);
    if (fight->abut[i]->att_frame < 7) {
        fight->pl->rect.left = pl_sprite_left[fight->abut[i]->att_frame - 1];
        fight->pl->rect.top = pl_attack_top[i];
        fight->abut[i]->att_frame++;
    }
    if (fight->abut[i]->att_frame == 7) {
        reset_pl_sprite(fight, i);
        update_attack_cooldown(fight, i);
    }
    if (fight->abut[i]->att_frame > 6)
        move_pl(fight, i);
    sfSprite_setTextureRect(fight->pl->sprite, fight->pl->rect);
}

static void reset_en_sprite(fight_t *fight, size_t i)
{
    sfClock *clock = sfClock_create();
    float elapsed = sfClock_getElapsedTime(clock).microseconds;

    while (elapsed < 500000 && i != 2)
        elapsed = sfClock_getElapsedTime(clock).microseconds;
    sfClock_destroy(clock);
    fight->en->rect.left = 0;
    fight->en->rect.top = 0;
    fight->en_att_frame[i] = 0;
    fight->has_pl_attacked = false;
    sfSprite_setPosition(fight->en->sprite, ENEMY_POS);
    sfSprite_setPosition(fight->en->life_bar->sprite, EN_LIFE_HUD_POS);
    sfRectangleShape_setPosition(fight->en->life_bar->rect, EN_LIFE_BAR_POS);
    update_hp(fight, i, 1);
}

void animate_en_attack(fight_t *fight, size_t i)
{
    sfClock *clock = sfClock_create();
    float elapsed = sfClock_getElapsedTime(clock).microseconds;

    while (elapsed < 100000)
        elapsed = sfClock_getElapsedTime(clock).microseconds;
    sfClock_destroy(clock);
    if (fight->en_att_frame[i] < 7) {
        fight->en->rect.left = en_sprite_left[fight->en_att_frame[i] - 1];
        fight->en->rect.top = en_attack_top[i];
        fight->en_att_frame[i] += 1;
    }
    if (fight->en_att_frame[i] == 7)
        reset_en_sprite(fight, i);
    if (fight->en_att_frame[i] > 7)
        move_en(fight, i);
    sfSprite_setTextureRect(fight->en->sprite, fight->en->rect);
}
