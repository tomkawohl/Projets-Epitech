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
#include "stat_hud.h"

void test_area_run(game_t *gm)
{
    sfEvent event;
    test_area_init(gm);
    while (sfRenderWindow_isOpen(gm->wd)) {
        test_area_event(gm, event);
        test_area_update(gm);
        test_area_draw(gm);
    }
    grid_destroy(gm->grid);
    game_actor_list_destroy(gm->ga);
    game_unit_list_destroy(gm->units);
    return;
}
