/*
** EPITECH PROJECT, 2023
** map
** File description:
** map_draw
*/
/**
 * @file map_draw.c
 *
 * @brief Handle draw of a map
 *
 * @date 20/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "player.h"
#include "game_actor.h"
#include "stat_hud.h"
#include "npc.h"
#include "skill_tree.h"

static void set_rect_pos(sfRectangleShape *rect, sfVector2f viewDiff,
                        sfVector2f pos)
{
    sfVector2f set_pos = {pos.x + viewDiff.x, pos.y + viewDiff.y};

    sfRectangleShape_setPosition(rect, set_pos);
}

static void set_sp_pos(sfSprite *rect, sfVector2f viewDiff,
                        sfVector2f pos)
{
    sfVector2f set_pos = {pos.x + viewDiff.x, pos.y + viewDiff.y};

    sfSprite_setPosition(rect, set_pos);
}

void draw_inventory(game_t *gm)
{
    static int o = 0;
    sfVector2f viewPos = sfView_getCenter(sfRenderWindow_getView(gm->wd));
    sfVector2f st_pos = { 850.f, 800.f };
    sfVector2f wiew_pos = { 1000.f, 390.f };
    sfVector2f viewDiff = {viewPos.x - wiew_pos.x, viewPos.y - wiew_pos.y};
    sfVector2f set_pos = {0};

    for (size_t i = 0; i < 4; i++, st_pos.x += 43) {
        set_rect_pos(gm->inv->inventory[i], viewDiff, st_pos);
        set_sp_pos(gm->inv->content[i], viewDiff, st_pos);
    }
    for (int i = 0; i != 4; i++) {
        sfRenderWindow_drawRectangleShape(gm->wd, gm->inv->inventory[i], NULL);
        if (gm->inv->is_case_able[i] == true)
            sfRenderWindow_drawSprite(gm->wd, gm->inv->content[i], NULL);
    }
}

void map_draw(struct game_s *gm)
{
    sfRenderWindow_clear(gm->wd, sfBlack);
    if (gm->grid != NULL)
        grid_draw(gm->wd, gm->grid->tiles);
    game_actor_list_draw(gm->wd, gm->ga);
    sfRenderWindow_drawSprite(gm->wd, gm->pl->player, NULL);
    game_unit_list_draw(gm->wd, gm->units);
    text_list_display(gm->wd, gm->list_text);
    update_stat_hud(gm);
    draw_inventory(gm);
    skill_tree_update(gm);
    sfRenderWindow_display(gm->wd);
}
