/*
** EPITECH PROJECT, 2023
** map/interact
** File description:
** midlayer_interact_go_outside
*/
/**
 * @file midlayer_interact_go_outside.c
 *
 * @brief Handle interaction to go to outside
 *
 * @date 22/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "player.h"
#include "test_area.h"
#include "game_actor.h"

void midlayer_interact_go_outside(game_t *gm)
{
    gm->changing_scene = OUTSIDE;
    player_set_pos(gm, (sfVector2i){18, 9});
}
