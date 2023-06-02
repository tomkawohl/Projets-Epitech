/*
** EPITECH PROJECT, 2023
** game/load
** File description:
** load
*/
/**
 * @file game_actor_add.c
 *
 * @brief Display load on scree
 *
 * @date 18/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"
#include "test_area.h"

/*
typedef struct text_info_s {
    sfVector2i coord;
    char *text;
    u_int size;
    char *tile_asset;
    sfIntRect asset;
    enum text_type type;
} text_info_t;
*/

void load(game_t *gm)
{
    sfVector2i coord = {14 , 7};
    sfVector2f center = (sfVector2f){17 * TILE_SIZE, 9 * TILE_SIZE};
    sfView *view = sfView_create();

    sfRenderWindow_clear(gm->wd, sfBlack);
    sfView_setCenter(view, center);
    sfView_setSize(view, (sfVector2f){1920, 1080});
    sfRenderWindow_setView(gm->wd, view);
    if (gm->list_text != NULL) {
        text_list_destroy(gm->list_text);
        gm->list_text = NULL;
    }
    if (gm->list_text == NULL)
        gm->list_text = text_list_create();
    text_list_add(gm->list_text, (text_info_t){ NULL, coord,
    " Load... \n", 50, GUI_ASSET, TEXT_SQUARE, T_DEF});
    text_list_display(gm->wd, gm->list_text);
    sfRenderWindow_display(gm->wd);
    text_list_remove(gm->list_text);
    sfView_destroy(view);
}
