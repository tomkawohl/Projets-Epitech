/*
** EPITECH PROJECT, 2023
** init_stat_hud.c
** File description:
** init_stat_hud
*/

#include "src.h"
#include "stat_hud.h"

static void init_bars_life(stat_hud_t *stat, double life, double lvl, double xp)
{
    sfVector2f pos_life = {252, -101};
    sfVector2f pos_lvl = {272, -45.50};
    sfVector2f pos_xp = {252, -11};
    sfVector2f size_life = {195 * (stat->life / 100), 17};
    sfVector2f size_lvl = {195 * (stat->lvl / 100), 17};
    sfVector2f size_xp = {195 * (stat->xp / 100), 17};

    stat->bars[0] = ssl_new_rect(size_life, sfRed, pos_life);
    stat->bars[2] = ssl_new_rect(size_lvl, sfBlue , pos_lvl);
    stat->bars[1] = ssl_new_rect(size_xp, sfYellow , pos_xp);
}

void init_stat_hud(stat_hud_t *s_hd, double life,  double lvl, double xp)
{
    sfTexture *txt = sfTexture_createFromFile(STAT_HUD_PNG, NULL);

    s_hd->bars = malloc(sizeof(sfRectangleShape *) * 3);
    s_hd->hud = sfSprite_create();
    s_hd->life = life;
    s_hd->lvl = lvl;
    s_hd->xp = xp;
    if (s_hd->life == 0)
        s_hd->life = 1;
    if (s_hd->lvl == 0)
        s_hd->lvl = 1;
    if (s_hd->xp == 0)
        s_hd->xp = 1;
    sfSprite_setTexture(s_hd->hud , txt, sfTrue);
    sfSprite_setScale(s_hd->hud, (sfVector2f){0.8, 0.8});
    sfSprite_setPosition(s_hd->hud, (sfVector2f){80, -160});
    init_bars_life(s_hd, life, lvl, xp);
}
