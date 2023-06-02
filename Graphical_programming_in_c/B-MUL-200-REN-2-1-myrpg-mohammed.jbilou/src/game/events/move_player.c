/*
** EPITECH PROJECT, 2023
** move_player
** File description:
** move_player
*/

#include "src.h"

static player_t *det_key(player_t *pl, sfIntRect rect,
sfVector2i cord, int sfKey)
{
    if (pl->animation != 0)
        return pl;
    if (sfKeyboard_isKeyPressed(sfKey)){
        sfSprite_setTextureRect(pl->player, rect);
        pl->rect = rect;
        pl->animation = sfKey;
    }
    return pl;
}

void move_player(game_t *gm)
{
    gm->pl = det_key(gm->pl, (sfIntRect){0, 515, 65, 60},
    (sfVector2i){0, -48}, sfKeyZ);
    gm->pl = det_key(gm->pl, (sfIntRect){0, 580, 65, 60},
    (sfVector2i){-48, 0}, sfKeyQ);
    gm->pl = det_key(gm->pl, (sfIntRect){0, 650, 65, 60},
    (sfVector2i){0, 48}, sfKeyS);
    gm->pl = det_key(gm->pl, (sfIntRect){0, 715, 65, 60},
    (sfVector2i){48, 0}, sfKeyD);
}
