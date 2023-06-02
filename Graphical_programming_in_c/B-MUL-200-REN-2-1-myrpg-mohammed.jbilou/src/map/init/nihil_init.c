/*
** EPITECH PROJECT, 2023
** map/init
** File description:
** nihil_init
*/
/**
 * @file nihil_init.c
 *
 * @brief Init nihil
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
    char *text = " Quete : \n Retournez dans le nihil et trouver Caligula \n";

    if (gm->g_quest == 2)
        text_list_add(gm->list_text, (text_info_t){"quest",
        (sfVector2i)QUEST_POS,
        text, 17, GUI_ASSET, TEXT_SQUARE, T_DEF});
    else {
        gm->g_quest = 2;
        text_list_add(gm->list_text, (text_info_t){"quest",
        (sfVector2i)QUEST_POS, quest[gm->g_quest], 17, GUI_ASSET,
        TEXT_SQUARE, T_DEF});
    }
}

void nihil_init(game_t *gm)
{
    gm->ga_event = nihil_event;
    game_actor_add(gm->ga, (info_actor_t){"book", BOOKS,
    (sfIntRect){0, 0, 48, 48}, (sfVector2i){20, 45}, true, false, false,
    1, nihil_interact_book, ON_LINE, (sfVector2i){0, 48}, 0.3, 3, 0});
    game_actor_add(gm->ga, (info_actor_t){"npc1", CHARS_1,
        (sfIntRect) {292, 148, 48, 48}, (sfVector2i){21, 48}, true, true, false,
        10, nihil_interact_npc, ON_LINE_UP, (sfVector2i){48, 0}, 0.3, 2});
    game_actor_add(gm->ga, (info_actor_t){"Caligula", MINOTAURE,
        (sfIntRect) {26, 20, 55, 43}, (sfVector2i){47, 19}, true, true, false,
        1, init_fight, ON_LINE, (sfVector2i){48, 0}, 0.3, 2});
    init_quest(gm);
}
