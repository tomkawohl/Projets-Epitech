/*
** EPITECH PROJECT, 2023
** animate_die
** File description:
** Animates the die of a character
*/

#include "fight.h"

void animate_pl_die(fight_t *fight)
{
    sfClock *clock = sfClock_create();
    float elapsed = sfClock_getElapsedTime(clock).microseconds;

    while (elapsed < 100000)
        elapsed = sfClock_getElapsedTime(clock).microseconds;
    sfClock_destroy(clock);
    if (fight->pl->dead_frame < 6) {
        fight->pl->rect.left = pl_sprite_left[fight->pl->dead_frame];
        fight->pl->rect.top = 300;
        fight->pl->dead_frame += 1;
    } else {
        fight->is_finished = true;
        fight->has_pl_win = false;
    }
    sfSprite_setTextureRect(fight->pl->sprite, fight->pl->rect);
}

void animate_en_die(fight_t *fight)
{
    sfClock *clock = sfClock_create();
    float elapsed = sfClock_getElapsedTime(clock).microseconds;

    while (elapsed < 100000)
        elapsed = sfClock_getElapsedTime(clock).microseconds;
    sfClock_destroy(clock);
    if (fight->en->dead_frame < 11) {
        fight->en->rect.left = en_sprite_left[fight->en->dead_frame];
        fight->en->rect.top = 350;
        fight->en->dead_frame += 1;
    } else {
        fight->is_finished = true;
        fight->has_pl_win = true;
    }
    sfSprite_setTextureRect(fight->en->sprite, fight->en->rect);
}
