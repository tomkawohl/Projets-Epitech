/*
** EPITECH PROJECT, 2023
** menu
** File description:
** menu_run.c
*/
/**
 * @file menu_run.c
 *
 * @brief Run main_menu
 *
 * @date 20/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"
#include "test_area.h"
#include "src_struct.h"
#include "map.h"
#include "player.h"

void main_menu_run(struct game_s *gm)
{
    while (sfRenderWindow_isOpen(gm->wd)) {
        events_game(gm);
        update_game(gm);
        sfRenderWindow_display(gm->wd);
        if (gm->changing_scene != -1)
            break;
    }
    if (gm->changing_scene != -1) {
        player_set_pos(gm, (sfVector2i){15, 8});
        scene_change(gm);
        gm->g_scene = map_run;
        gm->g_scene(gm);
    }
}
