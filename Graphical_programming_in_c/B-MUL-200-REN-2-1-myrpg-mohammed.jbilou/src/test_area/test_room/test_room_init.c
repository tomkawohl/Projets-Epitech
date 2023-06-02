/*
** EPITECH PROJECT, 2023
** test_area/test_room
** File description:
** test_room_init
*/
/**
 * @file test_room_init.c
 *
 * @brief Init test_room
 *
 * @date 12/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "player.h"
#include "test_area.h"
#include "game_actor.h"

void test_room_init(game_t *gm)
{
    gm_reset_data(gm);
    gm->grid = file_to_map("testroom.txt", false);
    gm->units = file_to_map_unit("testroom.txt");
    player_set_pos(gm, (sfVector2i){2 , 2});
}
