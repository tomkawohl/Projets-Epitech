/*
** EPITECH PROJECT, 2023
** player
** File description:
** player_can_move
*/
/**
 * @file player_can_move.c
 *
 * @brief Verify if player can move on the tile
 *
 * @date 11/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"

static bool verify_game_actor(game_t *gm, sfVector2i dir)
{
    game_actor_t *game_actor = NULL;

    if (!gm->ga)
        return (true);
    if (!gm->ga->first)
        return (true);
    game_actor = gm->ga->first;
    while (game_actor) {
        if (game_actor->solid
        && game_actor->pos.x == dir.x && game_actor->pos.y == dir.y)
            return (false);
        game_actor = game_actor->next;
    }
    return (true);
}

bool player_can_move(game_t *gm, sfVector2f vector)
{
    sfVector2i tile_target = gm->pl->pos;

    if (vector.x < 0)
        tile_target.x -= 1;
    if (vector.x > 0)
        tile_target.x += 1;
    if (vector.y < 0)
        tile_target.y -= 1;
    if (vector.y > 0)
        tile_target.y += 1;
    if (tile_target.x < 0 || tile_target.x >= gm->grid->limit.x)
        return (false);
    if (tile_target.y < 0 || tile_target.y >= gm->grid->limit.y)
        return (false);
    if (gm->grid->tiles[tile_target.y][tile_target.x].solid == true)
        return (false);
    if (verify_game_actor(gm, tile_target) == false)
        return (false);
    return (true);
}
