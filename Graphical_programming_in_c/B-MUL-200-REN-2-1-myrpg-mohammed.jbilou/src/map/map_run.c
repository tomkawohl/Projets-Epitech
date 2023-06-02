/*
** EPITECH PROJECT, 2023
** map
** File description:
** map_run
*/
/**
 * @file map_run.c
 *
 * @brief Run a map
 *
 * @date 20/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"
#include "src_struct.h"
#include "map.h"
#include "test_area.h" //to change

static bool check_events_close(struct game_s *gm, sfTime time, sfEvent event,
                            sfClock *clock)
{
    if (time.microseconds >= 1000000 / 60) {
        if (map_event(gm, event) == false)
            return false;
        map_update(gm);
        map_draw(gm);
        sfClock_restart(clock);
    }
    return true;
}

void map_run(struct game_s *gm)
{
    sfEvent event;
    sfClock *clock = sfClock_create();
    sfTime time = {0};
    while (sfRenderWindow_isOpen(gm->wd)) {
        time = sfClock_getElapsedTime(clock);
        if (check_events_close(gm, time, event, clock) == false){
            gm->g_scene = main_menu_run;
            gm->scene = SETTINGS_SCENE;
            gm->g_scene(gm);
            return;
        }
        if (gm->changing_scene != -1)
            break;
    }
    sfClock_destroy(clock);
    if (gm->changing_scene != -1) {
        scene_change(gm);
        gm->g_scene = map_run;
        gm->g_scene(gm);
    }
}
