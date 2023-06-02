/*
** EPITECH PROJECT, 2023
** map/init
** File description:
** midlayer_init
*/
/**
 * @file midlayer_init.c
 *
 * @brief Init midlayer
 *
 * @date 21/04/2023
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
    char *text = " Quete : \n Retournez dehors pour examiner le terrain \n";

    if (gm->g_quest == 1) {
        text_list_add(gm->list_text, (text_info_t){"quest",
            (sfVector2i)QUEST_POS, text, 17, GUI_ASSET, TEXT_SQUARE, T_DEF});
        return;
    }
    text_list_add(gm->list_text, (text_info_t){"quest", (sfVector2i)QUEST_POS,
        quest[gm->g_quest], 17, GUI_ASSET, TEXT_SQUARE, T_DEF});
}

void midlayer_init(game_t *gm)
{
    gm->ga_event = midlayer_event;
    game_actor_add(gm->ga, (info_actor_t){"go_undegr", NULL,
        (sfIntRect){0, 0, 48, 48}, (sfVector2i){14, 3}, true, false, false,
        2, midlayer_interact_go_undergr, ON_LINE_RIGHT, (sfVector2i){0, 0},
        0.0, 0, 0});
    game_actor_add(gm->ga, (info_actor_t){"go_room", NULL,
        (sfIntRect){0, 0, 48, 48}, (sfVector2i){23, 3}, true, false, false,
        1, midlayer_interact_go_room, ON_IT, (sfVector2i){0, 0},
        0.0, 0, 0});
    game_actor_add(gm->ga, (info_actor_t){"go_outside", NULL,
        (sfIntRect){0, 0, 48, 48}, (sfVector2i){16, 16}, true, false, false,
        2, midlayer_interact_go_outside, ON_LINE_LEFT, (sfVector2i){0, 0},
        0.0, 0, 0});
    game_actor_add(gm->ga, (info_actor_t){"skeletton", SKELETON_PNG,
        (sfIntRect) {0, 0, 64, 64}, (sfVector2i){7, 7}, true, true, true, 1,
        init_fight, ON_SQUARE, (sfVector2i){64, 0}, 0.3, 1});
    init_quest(gm);
}
