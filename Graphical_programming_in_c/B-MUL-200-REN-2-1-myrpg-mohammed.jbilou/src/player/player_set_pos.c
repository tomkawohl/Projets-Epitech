/*
** EPITECH PROJECT, 2023
** player
** File description:
** player_set_pos
*/
/**
 * @file player_set_pos.c
 *
 * @brief Set a position to the player
 *
 * @date 11/04/2023
*/
#include "src.h"
#include "lib_will.h"

void player_set_pos(game_t *gm, sfVector2i pos)
{
    sfVector2f pos_screen = {0, 0};

    if (gm == NULL || gm->pl == NULL)
        return;
    gm->pl->pos = pos;
    pos_screen.x = pos.x * TILE_SIZE;
    pos_screen.y = pos.y * TILE_SIZE;
    sfSprite_setPosition(gm->pl->player, pos_screen);
    return;
}
