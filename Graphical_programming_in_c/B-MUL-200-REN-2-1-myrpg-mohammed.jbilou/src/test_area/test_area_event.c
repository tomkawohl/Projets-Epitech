/*
** EPITECH PROJECT, 2023
** test_area
** File description:
** test_area_run
*/
/**
 * @file test_area_run.c
 *
 * @brief Run test area to test features
 *
 * @date 11/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "player.h"
#include "test_area.h"
#include "game_actor.h"
#include "skill_tree.h"

void test_area_event(game_t *gm, sfEvent event)
{
    while (sfRenderWindow_pollEvent(gm->wd, &event)) {
        gm->event = event;
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(gm->wd);
        move_player(gm);
        skill_tree_events(gm);
    }
    if (gm->ga_event != NULL)
        gm->ga_event(gm);
}
