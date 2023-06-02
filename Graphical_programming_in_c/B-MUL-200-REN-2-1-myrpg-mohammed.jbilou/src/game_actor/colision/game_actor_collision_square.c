/*
** EPITECH PROJECT, 2023
** game_actor
** File description:
** game_actor_collision_square
*/
/**
 * @file game_actor_collision_square.c
 *
 * @brief Verify if player is in range on square with a game_actor
 *
 * @date 12/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"


static bool is_in_square_line(game_actor_t *ga, game_t *gm, u_int max,
    u_int i)
{
    int j = -ga->range;

    while (j < (int)max) {
        if (ga->pos.y + i == gm->pl->pos.y && ga->pos.x + j == gm->pl->pos.x)
            return (true);
        j++;
    }
    return (false);
}

bool ga_is_in_square(game_actor_t *ga, game_t *gm)
{
    int i = -ga->range;
    u_int max = ga->range * 2;

    if (ga->range != 1)
        max += 1;
    while (i < (int)max) {
        if (is_in_square_line(ga, gm, max, i))
            return (true);
        i++;
    }
    return (false);
}
