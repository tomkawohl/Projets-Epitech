/*
** EPITECH PROJECT, 2023
** init
** File description:
** init_game_data
*/
/**
 * @file init_game_data.c
 *
 * @brief Init data of structure game_t
 *
 * @date 21/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"

void init_game_data(game_t *gm)
{
    gm->grid = NULL;
    gm->ga = NULL;
    gm->units = NULL;
    gm->list_text = NULL;
    gm->ga_event = NULL;
    gm->ga_current = NULL;
    gm->g_quest = HOME;
    gm->delta_move = (sfVector2f){0, 0};
    gm->g_scene = main_menu_run;
    gm->changing_scene = -1;
    gm->load = false;
    gm->save = NULL;
    gm->current_scene = -1;
    gm->event_in_progress = false;
}
