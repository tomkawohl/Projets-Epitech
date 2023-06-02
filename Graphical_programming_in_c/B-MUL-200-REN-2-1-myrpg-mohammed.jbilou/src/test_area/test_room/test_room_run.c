/*
** EPITECH PROJECT, 2023
** test_area/test_room
** File description:
** test_room_run
*/
/**
 * @file test_room_run.c
 *
 * @brief Run test room to test features
 *
 * @date 12/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "player.h"
#include "test_area.h"
#include "game_actor.h"
#include "stat_hud.h"

void test_room_run(game_t *gm)
{
    sfEvent event;
    test_room_init(gm);
    while (sfRenderWindow_isOpen(gm->wd)) {
        test_area_event(gm, event);
        test_area_update(gm);
        test_area_draw(gm);
    }
    return;
}
