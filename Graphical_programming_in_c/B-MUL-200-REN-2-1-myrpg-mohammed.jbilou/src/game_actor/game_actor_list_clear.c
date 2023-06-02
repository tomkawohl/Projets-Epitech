/*
** EPITECH PROJECT, 2023
** game_actor
** File description:
** game_actor_clear
*/
/**
 * @file game_actor_clear.c
 *
 * @brief Clear a list of game actors
 *
 * @date 12/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"

void game_actor_list_clear(game_actor_list_t *ga)
{
    if (!ga)
        return;
    if (ga->first == NULL)
        return;
    while (ga->first)
        game_actor_remove(ga);
    return;
}
