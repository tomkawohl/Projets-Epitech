/*
** EPITECH PROJECT, 2023
** npc
** File description:
** npc_move
*/
/**
 * @file npc_move.c
 *
 * @brief Move a npc
 *
 * @date 22/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"

static sfVector2f get_go(game_actor_t *ga, sfVector2i pos, sfClock *clock)
{
    sfTime elapsed_time = sfClock_getElapsedTime(clock);
    sfVector2f go = {0, 0};

    if (ga->pos.x < pos.x)
        go.x = 48.0f * (float)elapsed_time.microseconds / 1000000.0f;
    else
        go.y = 48.0f * (float)elapsed_time.microseconds / 1000000.0f;
    sfClock_restart(clock);
    return (go);
}

int npc_move_ver1(game_actor_t *ga, sfVector2i pos)
{
    static sfClock *clock = NULL;
    sfVector2f go = {0, 0};
    sfVector2f sprite_pos = sfSprite_getPosition(ga->sprite);
    if (clock == NULL) {
        clock = sfClock_create();
        if (ga->clock_anim == NULL)
            ga->clock_anim = sfClock_create();
        ga->to_animate = 1;
    }
    go = get_go(ga, pos, clock);
    sprite_pos.x += go.x;
    sprite_pos.y += go.y;
    sfSprite_setPosition(ga->sprite, sprite_pos);
    if ((int)(sprite_pos.x / TILE_SIZE) >= pos.x
        && (int)(sprite_pos.y / TILE_SIZE) >= pos.y) {
        ga->to_animate = 0;
        sfClock_destroy(clock);
        return (1);
    }
    return (0);
}
