/*
** EPITECH PROJECT, 2023
** map
** File description:
** map_update
*/
/**
 * @file map_update.c
 *
 * @brief Update data of a map
 *
 * @date 20/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"
#include "src_struct.h"
#include "map.h"
#include "player.h"

void map_update(struct game_s *gm)
{
    update_view(gm);
    player_update(gm);
    game_actor_list_anim(gm);
    update_quest_pos(gm);
}
