/*
** EPITECH PROJECT, 2023
** src
** File description:
** src
*/

#ifndef STAT_HD_H
    #define STAT_HD_H
    #include "src.h"
    #define STAT_HUD_PNG "util/ASSETS/STATS/stat_hud.png"

/**
 * @brief init stat hud
 *
 * @param s_hd stat_hud_t *
 */
void init_stat_hud(stat_hud_t *s_hd, double life,  double lvl, double xp);

/**
 * @brief update stat hud
 *
 * @param gm
 */
void update_stat_hud(game_t *gm);
#endif /* !STAT_HD_H */
