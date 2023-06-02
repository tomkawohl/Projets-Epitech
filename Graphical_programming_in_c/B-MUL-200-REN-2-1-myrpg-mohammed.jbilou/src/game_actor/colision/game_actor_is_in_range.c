/*
** EPITECH PROJECT, 2023
** game_actor
** File description:
** game_actor_is_in_range
*/
/**
 * @file game_actor_is_in_range.c
 *
 * @brief Verify if a game actor is in range to interact
 *
 * @date 12/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"

bool ga_is_in_range(game_actor_t *ga, game_t *gm)
{
    if (ga->is_activ == false)
        return (false);
    if (ga->type == ON_LINE)
        return (ga_is_in_line(ga, gm));
    if (ga->type == ON_SQUARE)
        return (ga_is_in_square(ga, gm));
    if (ga->type == ON_IT) {
        if (ga->pos.x == gm->pl->pos.x && ga->pos.y == gm->pl->pos.y)
            return (true);
        else
            return (false);
    }
    if (ga->type == ON_LINE_LEFT)
        return (ga_is_in_line_left(ga, gm));
    if (ga->type == ON_LINE_RIGHT)
        return (ga_is_in_line_right(ga, gm));
    if (ga->type == ON_LINE_UP)
        return (ga_is_in_line_up(ga, gm));
    if (ga->type == ON_LINE_DOWN)
        return (ga_is_in_line_down(ga, gm));
}
