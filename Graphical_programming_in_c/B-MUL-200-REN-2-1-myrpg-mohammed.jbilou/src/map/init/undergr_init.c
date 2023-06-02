/*
** EPITECH PROJECT, 2023
** map/init
** File description:
** undergr_init
*/
/**
 * @file undergr_init.c
 *
 * @brief Init undergr
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

void undergr_init(game_t *gm)
{
    QUEST_LIST;
    gm->ga_event = midlayer_event;
    game_actor_add(gm->ga, (info_actor_t){"go_midlayer", NULL,
    (sfIntRect){0, 0, 48, 48}, (sfVector2i){23, 6}, true, false, false,
    1, undergr_interact_go_midlayer, ON_IT, (sfVector2i){0, 0}, 0.0, 0, 0});
    text_list_add(gm->list_text, (text_info_t){"quest", (sfVector2i)QUEST_POS,
        quest[gm->g_quest], 17, GUI_ASSET, TEXT_SQUARE, T_DEF});
}
