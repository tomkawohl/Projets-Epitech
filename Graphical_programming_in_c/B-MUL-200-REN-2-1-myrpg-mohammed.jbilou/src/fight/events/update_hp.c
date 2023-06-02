/*
** EPITECH PROJECT, 2023
** update_hp
** File description:
** Updates health points for player and enemy in fight
*/

#include "fight.h"

void update_hp(fight_t *fight, size_t index, size_t charac)
{
    if (charac == 0 && index != ATT_FOUR_BUT)
        fight->en->life -= fight->abut[index]->hp_remove;
    if (charac == 0 && index == ATT_FOUR_BUT)
        fight->pl->life += fight->abut[index]->hp_remove;
    if (charac == 1 && index != 2)
        fight->pl->life -= fight->en_att_hp_remov[index];
    if (charac == 1 && index == 2)
        fight->en->life += fight->en_att_hp_remov[index];
    if (fight->en->life <= 0) {
        fight->en->life = 0;
        fight->en->is_dead = true;
    }
    if (fight->pl->life <= 0) {
        fight->pl->life = 0;
        fight->pl->is_dead = true;
    }
    if (fight->pl->life > 100)
        fight->pl->life = 100;
    if (fight->en->life > 100)
        fight->en->life = 100;
}
