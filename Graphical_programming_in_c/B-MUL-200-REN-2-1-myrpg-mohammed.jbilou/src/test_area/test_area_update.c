/*
** EPITECH PROJECT, 2023
** test_area
** File description:
** test_area_update
*/
/**
 * @file test_area_update.c
 *
 * @brief Update test area
 *
 * @date 11/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "player.h"
#include "test_area.h"
#include "game_actor.h"
#include "stat_hud.h"

void test_area_update(game_t *gm)
{
    update_view(gm);
    player_update(gm);
    game_actor_list_anim(gm);
    update_quest_pos(gm);
}
