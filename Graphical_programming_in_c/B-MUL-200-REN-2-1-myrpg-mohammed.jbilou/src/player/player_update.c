/*
** EPITECH PROJECT, 2023
** player
** File description:
** player_update
*/
/**
 * @file player_update.c
 *
 * @brief Update player data
 *
 * @date 11/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "player.h"
#include "stat_hud.h"

void player_update(game_t *gm)
{
    if (gm->pl->animation != 0){
        update_pos_player(gm);
    }
}
