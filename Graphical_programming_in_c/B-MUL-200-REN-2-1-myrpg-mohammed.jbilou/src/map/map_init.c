/*
** EPITECH PROJECT, 2023
** map
** File description:
** map_init
*/
/**
 * @file map_init.c
 *
 * @brief Init a map
 *
 * @date 20/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"
#include "src_struct.h"
#include "stat_hud.h"
#include "map.h"

static bool use_current(char *map)
{
    if (map == NULL)
        return (false);
    if (str_find(map, "YES"))
        return (true);
    free(map);
    return (false);
}

static char *get_map(game_t *gm)
{
    DEFAULT_SCENE;
    CURRENT_SCENE;
    SCENE_SAVE;
    char *map = file_to_str_stat(current_map[gm->changing_scene]);

    if (use_current(map) == false) {
        map = NULL;
        if (gm->load == false)
            map = file_to_str_stat(default_map[gm->changing_scene]);
        else
            map = file_to_str_stat(save_map[gm->changing_scene]);
        return (map);
    }
    return (map);
}

void map_init(game_t *gm, void (*scene_func)(struct game_s *))
{
    char *map = get_map(gm);

    if (map != NULL) {
        if (gm->save != NULL) {
            free_array_str2d(gm->save);
            gm->save = NULL;
        }
        gm->save = str1d_to_str2d(map);
        free(map);
    }
    scene_func(gm);
}
