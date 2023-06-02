/*
** EPITECH PROJECT, 2023
** test_area
** File description:
** gm_reset_data
*/
/**
 * @file gm_reset_data.c
 *
 * @brief Reset grid and game_actors_list_t
 *
 * @date 12/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "player.h"
#include "game_actor.h"

void gm_reset_data(game_t *gm)
{
    if (gm->ga != NULL)
        game_actor_list_clear(gm->ga);
    else
        gm->ga = game_actor_list_create();
    if (gm->units != NULL)
        game_unit_list_clear(gm->units);
    else
        gm->units = game_unit_list_create();
    if (gm->list_text == NULL)
        gm->list_text = text_list_create();
    if (gm->grid != NULL)
        grid_destroy(gm->grid);
    gm->delta_move = (sfVector2f){0, 0};
}
