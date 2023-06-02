/*
** EPITECH PROJECT, 2023
** update_game.c
** File description:
** update the game
*/

#include "src.h"
#include "menu.h"
#include "player.h"
#include "stat_hud.h"
#include "skill_tree.h"
#include "stat_hud.h"
#include "npc.h"

void update_view(game_t *gm)
{
    sfVector2f pos = sfSprite_getPosition(gm->pl->player);

    pos.x += 30;
    pos.y += 30;
    sfView_setCenter(gm->view, pos);
    sfView_setSize(gm->view, (sfVector2f){1920, 1080});
    sfRenderWindow_setView(gm->wd, gm->view);
}

static player_t *animate_player(game_t *gm,
int sfKey, sfVector2f move, int dec)
{
    static int rect = 0;

    if (gm->pl->animation == sfKey){
        if (player_can_move(gm, move)) {
            sfSprite_move(gm->pl->player, move);
            gm->delta_move.x += move.x;
            gm->delta_move.y += move.y;
        }
        if (rect % 5 == 0)
            gm->pl->rect.left += 64;
        if (gm->pl->rect.left >= 575)
            gm->pl->rect.left = 0;
        sfSprite_setTextureRect(gm->pl->player, gm->pl->rect);
        gm->pl->load += dec;
        rect += 2;
    }
    return gm->pl;
}

void update_pos_player(game_t *gm)
{
    sfVector2f new_pos = {0, 0};

    if (gm->pl->load == -48 || gm->pl->load == 48){
        gm->pl->load = 0;
        gm->pl->animation = 0;
        gm->pl->rect.left = 0;
        sfSprite_setTextureRect(gm->pl->player, gm->pl->rect);
        new_pos = sfSprite_getPosition(gm->pl->player);
        new_pos.x /= TILE_SIZE;
        new_pos.y /= TILE_SIZE;
        gm->pl->pos.x = (int)new_pos.x;
        gm->pl->pos.y = (int)new_pos.y;
        return;
    }
    gm->pl = animate_player(gm, sfKeyZ, (sfVector2f){0, -2}, -2);
    gm->pl = animate_player(gm, sfKeyQ, (sfVector2f){-2, 0}, -2);
    gm->pl = animate_player(gm, sfKeyS, (sfVector2f){0, 2}, 2);
    gm->pl = animate_player(gm, sfKeyD, (sfVector2f){2, 0}, 2);
}

void update_game(game_t *gm)
{
    sfRenderWindow_clear(gm->wd, sfBlack);
    update_main_menu(gm);
    update_settings_menu(gm);
    update_how_to_play(gm);
    sfRenderWindow_display(gm->wd);
}
