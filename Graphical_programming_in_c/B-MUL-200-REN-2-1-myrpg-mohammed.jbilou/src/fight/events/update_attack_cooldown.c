/*
** EPITECH PROJECT, 2023
** update_attack_cooldown
** File description:
** Updates cooldowns for attack
*/

#include "fight.h"

void update_attack_cooldown(fight_t *fight, size_t index)
{
    if (index == ATT_TWO_BUT)
        fight->abut[index]->cooldown = 1;
    if (index == ATT_FOUR_BUT)
        fight->abut[index]->cooldown = 2;
    if (fight->abut[ATT_TWO_BUT]->cooldown > 0 && index != ATT_TWO_BUT)
        fight->abut[ATT_TWO_BUT]->cooldown--;
    if (fight->abut[ATT_FOUR_BUT]->cooldown > 0 && index != ATT_FOUR_BUT)
        fight->abut[ATT_FOUR_BUT]->cooldown--;
}
