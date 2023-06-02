/*
** EPITECH PROJECT, 2023
** test_area
** File description:
** test_area_draw
*/
/**
 * @file test_area_draw.c
 *
 * @brief Draw test area elements
 *
 * @date 11/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "player.h"
#include "game_actor.h"
#include "stat_hud.h"
#include "npc.h"
#include "skill_tree.h"


void test_area_draw(game_t *gm)
{
    sfRenderWindow_clear(gm->wd, sfBlack);
    if (gm->grid != NULL)
        grid_draw(gm->wd, gm->grid->tiles);
    game_actor_list_draw(gm->wd, gm->ga);
    sfRenderWindow_drawSprite(gm->wd, gm->pl->player, NULL);
    game_unit_list_draw(gm->wd, gm->units);
    text_list_display(gm->wd, gm->list_text);
    update_stat_hud(gm);
    sfRenderWindow_display(gm->wd);
}
