/*
** EPITECH PROJECT, 2023
** map/init
** File description:
** outside_init
*/
/**
 * @file outside_init.c
 *
 * @brief Init outside
 *
 * @date 22/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "player.h"
#include "test_area.h"
#include "game_actor.h"
#include "npc.h"
#include "fight.h"

static void init_quest(game_t *gm)
{
    QUEST_LIST;

    if (gm->g_quest >= 1)
        return;
    gm->g_quest = 1;
    text_list_add(gm->list_text, (text_info_t){"quest", (sfVector2i)QUEST_POS,
        quest[gm->g_quest], 17, GUI_ASSET, TEXT_SQUARE, T_DEF});
}

void outside_init(game_t *gm)
{
    gm->ga_event = outside_event;
    game_actor_add(gm->ga, (info_actor_t){"go_midlayer", NULL,
        (sfIntRect){0, 0, 48, 48}, (sfVector2i){18, 8}, true, false, false,
        1, outside_interact_go_midlayer, ON_IT, (sfVector2i){0, 0},
        0.0, 0, 0});
    game_actor_add(gm->ga, (info_actor_t){"npc", CHARS_1,
        (sfIntRect) {3, 3, 48, 48}, (sfVector2i){15, 9}, true, true, false,
        10, outside_interact_npc, ON_LINE_DOWN, (sfVector2i){48, 0}, 0.3, 2});
    game_actor_add(gm->ga, (info_actor_t){"go_nihil", NULL,
        (sfIntRect) {3, 3, 48, 48}, (sfVector2i){16, 15}, true, false, false,
        2, outside_interact_go_nihil, ON_LINE_LEFT, (sfVector2i){48, 0},
        0.0, 0});
    game_actor_add(gm->ga, (info_actor_t){"skeletton1", SKELETON_PNG,
        (sfIntRect) {0, 0, 64, 64}, (sfVector2i){11, 5}, true, true, true, 1,
        init_fight, ON_SQUARE, (sfVector2i){64, 0}, 0.3, 1});
    game_actor_add(gm->ga, (info_actor_t){"skeletton2", SKELETON_PNG,
        (sfIntRect) {0, 0, 64, 64}, (sfVector2i){9, 8}, true, true, true, 1,
        init_fight, ON_SQUARE, (sfVector2i){64, 0}, 0.3, 1});
    init_quest(gm);
}
