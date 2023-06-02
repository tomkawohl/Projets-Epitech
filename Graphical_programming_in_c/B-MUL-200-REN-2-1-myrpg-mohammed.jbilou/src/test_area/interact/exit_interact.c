/*
** EPITECH PROJECT, 2023
** test_area/interact
** File description:
** exit_interact
*/
/**
 * @file exit_interact.c
 *
 * @brief Function to test exit interact
 *
 * @date 16/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "player.h"
#include "test_area.h"
#include "game_actor.h"

void test_area_exit_interact(game_t *gm)
{
    w_printf("EXIT\n");
    test_room_run(gm);
    test_area_init(gm);
    return;
}
