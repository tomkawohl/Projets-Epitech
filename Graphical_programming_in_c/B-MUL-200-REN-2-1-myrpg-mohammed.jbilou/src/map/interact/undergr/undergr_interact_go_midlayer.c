/*
** EPITECH PROJECT, 2023
** map/room/interact
** File description:
** undergr_interact_go_midlayer
*/
/**
 * @file undergr_interact_go_midlayer.c
 *
 * @brief Handle interaction to go to midlayer
 *
 * @date 21/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "player.h"
#include "test_area.h"
#include "game_actor.h"

void undergr_interact_go_midlayer(game_t *gm)
{
    gm->changing_scene = MIDLAYER;
    player_set_pos(gm, (sfVector2i){15, 4});
}
