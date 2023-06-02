/*
** EPITECH PROJECT, 2023
** test_area
** File description:
** test_area_init
*/
/**
 * @file test_area_init.c
 *
 * @brief Init test area to test features
 *
 * @date 12/04/2023
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
    u_int range;
    void (*interact)(game_t *gm);
    enum ga_type;
} info_actor_t;
*/
/*
faire la fonction de la porte pour exit
//game_actor_add(gm->ga, (info_actor_t){"exit", NULL,
    //(sfIntRect){0, 0, 0, 0}, (sfVector2i){1, 10}, true, 1, sword_interact});
*/
/*
    game_actor_add(gm->ga, (info_actor_t){"test", HOUSE_SET_5,
    (sfIntRect){0, 0, 48, 48}, (sfVector2i){2, 2}, true, true, 5,
        sword_interact, ON_LINE_RIGHT});
    game_actor_add(gm->ga, (info_actor_t){"exit", NULL,
    (sfIntRect){0, 0, 48, 48}, (sfVector2i){7, 2}, true, false, 1,
        test_area_exit_interact, ON_IT});
*/
void test_area_init(game_t *gm)
{
    gm_reset_data(gm);
    gm->grid = file_to_map("test.txt", false);
    gm->units = file_to_map_unit("test.txt");
    player_set_pos(gm, (sfVector2i){5 , 5});
}
