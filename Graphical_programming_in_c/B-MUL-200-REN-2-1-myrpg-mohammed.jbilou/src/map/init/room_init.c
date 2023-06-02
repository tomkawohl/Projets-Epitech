/*
** EPITECH PROJECT, 2023
** map/room
** File description:
** room_init
*/
/**
 * @file room_init.c
 *
 * @brief Init room
 *
 * @date 16/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "player.h"
#include "test_area.h"
#include "game_actor.h"
#include "npc.h"
#include "fight.h"

/*
typedef struct info_actor_s {
    char *name;
    char *asset;
    sfIntRect rect;
    sfVector2i pos;
    bool is_activ;
    bool solid;
    bool to_animate;
    u_int range;
    void (*interact)(game_t *gm);
    enum ga_type type;
    sfVector2i anim_set;
    float frame_rate;
    u_int nb_frame;
} info_actor_t;
*/

static void init_quest(game_t *gm)
{
    QUEST_LIST;
    char *text = " Quetes : \n Retournez dehors pour examiner le terrain \n";

    if (gm->g_quest == 1) {
        text_list_add(gm->list_text, (text_info_t){"quest",
            (sfVector2i)QUEST_POS, text, 17, GUI_ASSET, TEXT_SQUARE, T_DEF});
        return;
    }
    text_list_add(gm->list_text, (text_info_t){"quest", (sfVector2i)QUEST_POS,
        quest[gm->g_quest], 17, GUI_ASSET, TEXT_SQUARE, T_DEF});
}

static void init_go(game_t *gm)
{
    game_actor_add(gm->ga, (info_actor_t){"go_room2", NULL,
    (sfIntRect){0, 0, 48, 48}, (sfVector2i){16, 4}, true, false, false,
    1, room_interact_go_room2, ON_IT, (sfVector2i){0, 0}, 0.0, 0, 0});
    game_actor_add(gm->ga, (info_actor_t){"go_midlayer", NULL,
    (sfIntRect){0, 0, 48, 48}, (sfVector2i){4, 10}, true, false, false,
    1, room_interact_go_midlayer, ON_IT, (sfVector2i){0, 0}, 0.0, 0, 0});
}

void room_init(game_t *gm)
{
    gm->ga_event = room_event;
    game_actor_add(gm->ga, (info_actor_t){"candle", WATER_FIRE, (sfIntRect)
    {48,241, 48, 48}, (sfVector2i){6, 2}, true, false, true, 0, NULL, BASIC,
    (sfVector2i){48, 0}, 0.3, 3, 0});
    game_actor_add(gm->ga, (info_actor_t){"book", NULL,
    (sfIntRect){0, 0, 48, 48}, (sfVector2i){6, 5}, true, false, false,
    1, room_interact_book, ON_LINE, (sfVector2i){0, 0}, 0.0, 0, 0});
    init_go(gm);
    game_actor_add(gm->ga, (info_actor_t){"skeletton", SKELETON_PNG,
    (sfIntRect) {0, 0, 64, 64}, (sfVector2i){10, 5}, true, true, true, 1,
    init_fight, ON_SQUARE, (sfVector2i){64, 0}, 0.3, 1});
    init_quest(gm);
}
/**[TO TEST PNG INTERACT]
game_actor_add(gm->ga, (info_actor_t){"npc", CHARS_1,
(sfIntRect) {3, 3, 48, 48}, (sfVector2i){14, 4}, true, true, false, 5,
outside_interact_npc, ON_LINE_DOWN, (sfVector2i){48, 0}, 0.3, 2});
[TO TEST PNG INTERACT]**/
