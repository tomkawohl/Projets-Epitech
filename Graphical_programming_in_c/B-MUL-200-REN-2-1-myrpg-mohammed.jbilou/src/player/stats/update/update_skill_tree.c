/*
** EPITECH PROJECT, 2023
** player_update.c
** File description:
** player_update
*/

#include "src.h"
#include "player.h"
#include "skill_tree.h"
#include "menu.h"

static void set_rect_pos(sfRectangleShape *rect, sfVector2f viewDiff,
                        sfVector2f pos)
{
    sfVector2f set_pos = {pos.x + viewDiff.x, pos.y + viewDiff.y};

    sfRectangleShape_setPosition(rect, set_pos);
}

static bool check_on(game_t *gm, sfVector2f set_pos, sfVector2f wiew_pos)
{
    sfVector2f viewPos = sfView_getCenter(sfRenderWindow_getView(gm->wd));
    sfVector2f st_pos[] = {{1400, 100}, {1500, 120},
    {1750, 120}, {1500, 370}, {1750, 370}, {1630, 570}};
    sfVector2f viewDiff = {viewPos.x - wiew_pos.x, viewPos.y - wiew_pos.y};
    if (gm->event.type == sfEvtKeyPressed && gm->is_skill_tree == true
    && gm->event.text.unicode == sfKeyTab) {
        for (size_t i = 0; i < NB_SKILLS; i++) {
            st_pos[i].x -= 600;
            sfRectangleShape_setPosition(gm->skill_t[i].rect[0], st_pos[i]);
            sfRectangleShape_setPosition(gm->skill_t[i].rect[1], st_pos[i]);
        }
        gm->is_skill_tree = false;
        for (size_t i = 0; i < NB_SKILLS; i++){
            set_rect_pos(gm->skill_t[i].rect[0], viewDiff, st_pos[i]);
            set_rect_pos(gm->skill_t[i].rect[1], viewDiff, st_pos[i]);
        }
        return false;
    }
    return true;
}

static bool check_in(game_t *gm, sfVector2f set_pos, sfVector2f wiew_pos)
{
    sfVector2f viewPos = sfView_getCenter(sfRenderWindow_getView(gm->wd));
    sfVector2f st_pos[] = {{1400, 100}, {1500, 120},
    {1750, 120}, {1500, 370}, {1750, 370}, {1630, 570}};
    sfVector2f viewDiff = {viewPos.x - wiew_pos.x, viewPos.y - wiew_pos.y};
    if (gm->event.type == sfEvtKeyPressed && gm->is_skill_tree == false
    && gm->event.text.unicode == sfKeyTab) {
        for (size_t i = 0; i < NB_SKILLS; i++) {
            st_pos[i].x += 600;
            sfRectangleShape_setPosition(gm->skill_t[i].rect[0], st_pos[i]);
            sfRectangleShape_setPosition(gm->skill_t[i].rect[1], st_pos[i]);
        }
        gm->is_skill_tree = true;
        for (size_t i = 0; i < NB_SKILLS; i++){
            set_rect_pos(gm->skill_t[i].rect[0], viewDiff, st_pos[i]);
            set_rect_pos(gm->skill_t[i].rect[1], viewDiff, st_pos[i]);
        }
        return false;
    }
    return true;
}

void set_pos_skills(game_t *gm)
{
    sfVector2f view_pos = { 1000.f, 390.f };
    sfVector2f set_pos = {0};
    if (check_on(gm, set_pos, view_pos) == false)
        return;
    if (check_in(gm, set_pos, view_pos) == false)
        return;
}

void skill_tree_update(game_t *gm)
{
    skill_tree_t *sk = gm->skill_t;

    if (gm->s_hud->xp > 0 && gm->s_hud->xp < 100){
        sk[0].BW_active = false;
        sk[0].C_active = true;
        sk[1].BW_active = false;
        sk[1].C_active = true;
    }
    for (size_t i = 0; i < NB_SKILLS; i++) {
        if (sk[i].C_active == true)
            sfRenderWindow_drawRectangleShape(gm->wd, sk[i].rect[0], NULL);
        if (sk[i].BW_active == true)
            sfRenderWindow_drawRectangleShape(gm->wd, sk[i].rect[1], NULL);
    }
}
