/*
** EPITECH PROJECT, 2023
** map/room/map/
** File description:
** room2_init
*/
/**
 * @file room2_init.c
 *
 * @brief Init room2
 *
 * @date 17/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "player.h"
#include "test_area.h"
#include "game_actor.h"

/*
typedef struct info_actor_s {
    char *name;
    char *asset;
    sfIntRect rect;
    sfVector2i pos;
    bool is_activ;
    bool solid;
    u_int to_animate;
    u_int range;
    void (*interact)(game_t *gm);
    enum ga_type type;
    sfVector2i anim_set;
    float frame_rate;
    u_int nb_frame;
    u_int frame_state;
} info_actor_t;
*/
static void init_quest(game_t *gm)
{
    QUEST_LIST;
    char *text = " Quetes : \n Retournez dehors pour examiner le terrain \n";

    if (gm->g_quest == 1) {
        text_list_add(gm->list_text, (text_info_t){"quest",
            (sfVector2i)QUEST_POS,
            text, 17, GUI_ASSET, TEXT_SQUARE, T_DEF});
        return;
    }
    text_list_add(gm->list_text, (text_info_t){"quest", (sfVector2i)QUEST_POS,
        quest[gm->g_quest], 17, GUI_ASSET, TEXT_SQUARE, T_DEF});
}

void init_chess(game_t *gm)
{
    print_str2d(gm->save);
    sfVector2f shift_pos = {440, 432};

    if (str_find(gm->save[1], "NO")) {
        game_actor_add(gm->ga, (info_actor_t){"chest", CHEST,
        (sfIntRect){0, 34, 32, 40}, (sfVector2i){9, 9}, true, true, false,
        1, room2_interact_chest, ON_LINE, (sfVector2i){32, 0}, 0.1, 3, 0});
        sfSprite_setPosition(gm->ga->first->sprite, shift_pos);
    } else {
        game_actor_add(gm->ga, (info_actor_t){"chest", CHEST,
        (sfIntRect){96, 34, 32, 40}, (sfVector2i){9, 9}, false, true, false,
        1, NULL, ON_LINE, (sfVector2i){32, 0}, 0.1, 3, 0});
        sfSprite_setPosition(gm->ga->first->sprite, shift_pos);
    }
}

void room2_init(game_t *gm)
{
    gm->ga_event = room2_event;
    game_actor_add(gm->ga, (info_actor_t){"go_room", NULL, (sfIntRect)
    {0, 0, 48, 48}, (sfVector2i){4, 4}, true, false, false, 1,
    room2_interact_go_room, ON_IT, (sfVector2i){0, 0}, 0.0, 0, 0});
    game_actor_add(gm->ga, (info_actor_t){"book", BOOKS,
    (sfIntRect){0, 0, 48, 48}, (sfVector2i){9, 5}, true, false, false,
    1, room2_interact_book, ON_LINE, (sfVector2i){0, 48}, 0.3, 3, 0});
    init_chess(gm);
    init_quest(gm);
    return;
}
