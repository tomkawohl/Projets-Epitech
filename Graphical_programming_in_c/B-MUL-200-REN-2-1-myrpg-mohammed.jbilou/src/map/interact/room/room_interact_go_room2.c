/*
** EPITECH PROJECT, 2023
** map/room/interact
** File description:
** room_interact_go_room2
*/
/**
 * @file room_interact_go_room2.c
 *
 * @brief Handle interaction to go to room2
 *
 * @date 17/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "player.h"
#include "test_area.h"
#include "game_actor.h"

void room_interact_go_room2(game_t *gm)
{
    gm->changing_scene = ROOM2;
    player_set_pos(gm, (sfVector2i){5, 4});
}
