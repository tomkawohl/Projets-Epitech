/*
** EPITECH PROJECT, 2023
** end_fight
** File description:
** Ends the fight
*/

#include "fight.h"

void end_fight(game_t *gm, fight_t *fight)
{
    sfClock *clock = sfClock_create();
    float elapsed = sfClock_getElapsedTime(clock).microseconds;

    while (elapsed < 2500000 && fight->has_charac_died)
        elapsed = sfClock_getElapsedTime(clock).microseconds;
    sfClock_destroy(clock);
    gm->s_hud->life = fight->pl->life;
    if (fight->has_pl_win) {
        gm->ga_current->is_defeat = true;
        gm->s_hud->xp += 50;
        if (gm->s_hud->xp >= 100) {
            gm->s_hud->lvl += 20;
            gm->s_hud->xp -= 100;
        }
    }
}
