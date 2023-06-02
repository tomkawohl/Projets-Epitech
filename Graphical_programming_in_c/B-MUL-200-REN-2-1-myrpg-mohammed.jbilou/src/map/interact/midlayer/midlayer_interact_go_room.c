/*
** EPITECH PROJECT, 2023
** map/room/interact
** File description:
** midlayer_interact_go_room
*/
/**
 * @file midlayer_interact_go_room.c
 *
 * @brief Handle interaction to go to room
 *
 * @date 21/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "player.h"
#include "test_area.h"
#include "game_actor.h"

void midlayer_interact_go_room(game_t *gm)
{
    gm->changing_scene = ROOM;
    player_set_pos(gm, (sfVector2i){5, 10});
}
