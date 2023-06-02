/*
** EPITECH PROJECT, 2023
** init_stat_hud.c
** File description:
** init_stat_hud
*/

#include "src.h"

static void check_stats_bars(game_t *gm)
{
    stat_hud_t *stat = gm->s_hud;

    sfVector2f size_life = {195 * (stat->life / 100), 17};
    sfVector2f size_lvl = {195 * (stat->lvl / 100), 17};
    sfVector2f size_xp = {195 * (stat->xp / 100), 17};

    sfRectangleShape_setSize(stat->bars[0], size_life);
    sfRectangleShape_setSize(stat->bars[1], size_lvl);
    sfRectangleShape_setSize(stat->bars[2], size_xp);
}

static void set_rect_pos(sfRectangleShape *rect, sfVector2f viewDiff,
                        sfVector2f pos)
{
    sfVector2f set_pos = {pos.x + viewDiff.x, pos.y + viewDiff.y};

    sfRectangleShape_setPosition(rect, set_pos);
}

void update_stat_hud(game_t *gm)
{
    stat_hud_t *st = gm->s_hud;
    sfVector2f viewPos = sfView_getCenter(sfRenderWindow_getView(gm->wd));
    float time = sfTime_asSeconds(sfClock_getElapsedTime(gm->clock));
    sfVector2f st_pos = { 80.f, -160.f };
    sfVector2f bars_pos[] = {{252, -101} , {272, -45.50} , {252, 11}};
    sfVector2f wiew_pos = { 1000.f, 390.f };
    sfVector2f viewDiff = { viewPos.x - wiew_pos.x, viewPos.y - wiew_pos.y};
    sfVector2f set_pos = {0};
    check_stats_bars(gm);
    if (time > 0.005) {
        set_pos = (sfVector2f){st_pos.x + viewDiff.x, st_pos.y + viewDiff.y};
        sfSprite_setPosition(st->hud, set_pos);
        set_rect_pos(st->bars[0], viewDiff, bars_pos[0]);
        set_rect_pos(st->bars[1], viewDiff, bars_pos[1]);
        set_rect_pos(st->bars[2], viewDiff, bars_pos[2]);
        sfClock_restart(gm->clock);
        sfRenderWindow_drawSprite(gm->wd, st->hud, NULL);
        for (size_t i = 0; i < 3; i++)
            sfRenderWindow_drawRectangleShape(gm->wd, st->bars[i], NULL);
    }
}
