/*
** EPITECH PROJECT, 2023
** test_area
** File description:
** gm_destroy_data
*/
/**
 * @file gm_destroy_data.c
 *
 * @brief Destroy data of a map on gm
 *
 * @date 16/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "player.h"
#include "game_actor.h"
#include "text_list.h"

void gm_destroy_data(game_t *gm)
{
    if (gm->grid != NULL) {
        grid_destroy(gm->grid);
        gm->grid = NULL;
    }
    if (gm->units != NULL) {
        game_unit_list_destroy(gm->units);
        gm->units = NULL;
    }
    if (gm->ga != NULL) {
        game_actor_list_destroy(gm->ga);
        gm->ga = NULL;
    }
    if (gm->list_text != NULL) {
        text_list_destroy(gm->list_text);
        gm->list_text = NULL;
    }
}
