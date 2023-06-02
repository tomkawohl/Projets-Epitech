/*
** EPITECH PROJECT, 2023
** map/room/interact
** File description:
** midlayer_interact_go_undergr
*/
/**
 * @file midlayer_interact_go_undergr.c
 *
 * @brief Handle interaction to go to undergr
 *
 * @date 21/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "player.h"
#include "test_area.h"
#include "game_actor.h"

void midlayer_interact_go_undergr(game_t *gm)
{
    gm->changing_scene = UNDERGR;
    player_set_pos(gm, (sfVector2i){22, 6});
}
