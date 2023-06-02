/*
** EPITECH PROJECT, 2023
** map/interact
** File description:
** outside_interact_go_nihil
*/
/**
 * @file outside_interact_go_nihil.c
 *
 * @brief Handle interaction to go to nihil
 *
 * @date 22/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "player.h"
#include "test_area.h"
#include "game_actor.h"

void outside_interact_go_nihil(game_t *gm)
{
    gm->changing_scene = NIHIL;
    player_set_pos(gm, (sfVector2i){20, 47});
}
