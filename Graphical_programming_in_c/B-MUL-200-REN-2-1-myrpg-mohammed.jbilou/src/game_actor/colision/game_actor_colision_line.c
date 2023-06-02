/*
** EPITECH PROJECT, 2023
** game_actor
** File description:
** game_actor_colision_line
*/
/**
 * @file game_actor_colision_line.c
 *
 * @brief Verify if player is in range on line with a game_actor
 *
 * @date 12/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"

bool ga_is_in_line_left(game_actor_t *ga, game_t *gm)
{
    for (u_int i = 1; i < ga->range + 1; i++) {
        if (ga->pos.x - i == gm->pl->pos.x && ga->pos.y == gm->pl->pos.y)
            return (true);
    }
    return (false);
}

bool ga_is_in_line_right(game_actor_t *ga, game_t *gm)
{
    for (u_int i = 1; i < ga->range + 1; i++) {
        if (ga->pos.x + i == gm->pl->pos.x && ga->pos.y == gm->pl->pos.y)
            return (true);
    }
    return (false);
}

bool ga_is_in_line_up(game_actor_t *ga, game_t *gm)
{
    for (u_int i = 1; i < ga->range + 1; i++) {
        if (ga->pos.x == gm->pl->pos.x && ga->pos.y - i == gm->pl->pos.y)
            return (true);
    }
    return (false);
}

bool ga_is_in_line_down(game_actor_t *ga, game_t *gm)
{
    for (u_int i = 1; i < ga->range + 1; i++) {
        if (ga->pos.x == gm->pl->pos.x && ga->pos.y + i == gm->pl->pos.y)
            return (true);
    }
    return (false);
}

bool ga_is_in_line(game_actor_t *ga, game_t *gm)
{
    for (u_int i = 1; i < ga->range + 1; i++) {
        if (ga->pos.x + i == gm->pl->pos.x && ga->pos.y == gm->pl->pos.y)
            return (true);
    }
    for (u_int i = 1; i < ga->range + 1; i++) {
        if (ga->pos.x - i == gm->pl->pos.x && ga->pos.y == gm->pl->pos.y)
            return (true);
    }
    for (u_int i = 1; i < ga->range + 1; i++) {
        if (ga->pos.x == gm->pl->pos.x && ga->pos.y + i == gm->pl->pos.y)
            return (true);
    }
    for (u_int i = 1; i < ga->range + 1; i++) {
        if (ga->pos.x == gm->pl->pos.x && ga->pos.y - i == gm->pl->pos.y)
            return (true);
    }
    return (false);
}
