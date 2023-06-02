/*
** EPITECH PROJECT, 2023
** skill_tree.c
** File description:
** sill_tree
*/

#include "src.h"
#include "skill_tree.h"
#include "parser.h"
#include "menu.h"

static void init_tab(skill_tree_t *sk, parser_t *ps)
{
    char *icons[] = {"dorado_skull.png", "fire_ball.png",
    "heal.png", "invoke.png", "zap.png"};
    char *cat_C = NULL;
    char *cat_BW = NULL;

    for (size_t i = 0; i < NB_SKILLS; i++) {
        ps[i].pos_rect.x += 60;
        sk[i].rect[0] = ssl_new_rect(ps[i].size, sfWhite, ps[i].pos_rect);
        sk[i].rect[1] = ssl_new_rect(ps[i].size, sfWhite, ps[i].pos_rect);
        if (i > 0) {
            cat_C = msl_strcat(C_ASSET, icons[i - 1]);
            cat_BW = msl_strcat(BW_ASSET, icons[i - 1]);
            set_texture_rect(sk[i].rect[0], cat_C);
            set_texture_rect(sk[i].rect[1], cat_BW);
        }
        if (cat_BW && cat_C) {
            free(cat_BW);
            free(cat_C);
        }
    }
}

void init_skill_tree(skill_tree_t *sk, game_t *gm)
{
    if (gm->pars)
        free(gm->pars);
    init_parser(gm, "save/skill_tree.txt");
    for (size_t i = 0; i < NB_SKILLS; i++) {
        sk[i].rect = malloc(sizeof(sfRectangleShape *) * 2);
        sk[i].C_active = false;
        sk[i].BW_active = true;
    }
    init_tab(sk, gm->pars);
}
