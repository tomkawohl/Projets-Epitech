/*
** EPITECH PROJECT, 2023
** scene
** File description:
** scene_change
*/
/**
 * @file scene_change.c
 *
 * @brief Change a scene
 *
 * @date 20/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"
#include "test_area.h"

static void write_current(game_t *gm)
{
    CURRENT_SCENE;
    int fd = 0;
    char *str = NULL;

    str = str_cat(str, "CURRENT : YES\n");
    if (gm->current_scene == -1)
        return;
    fd = open(current_map[gm->current_scene], O_WRONLY | O_CREAT
        | O_TRUNC, 0777);
    if (fd == -1)
        return;
    for (u_int i = 1; gm->save[i] != NULL; i++)
        str = str_cat(str, gm->save[i]);
    write(fd, str, str_len(str));
    close(fd);
    free(str);
}

void scene_change(game_t *gm)
{
    SCENE_FUNCTIONS;
    SCENE_MAP;
    load(gm);
    gm_reset_data(gm);
    gm->grid = file_to_map(scene_map[gm->changing_scene], false);
    gm->units = file_to_map_unit(scene_map[gm->changing_scene]);
    write_current(gm);
    map_init(gm, handle_scene[gm->changing_scene]);
    gm->current_scene = gm->changing_scene;
    gm->changing_scene = -1;
    return;
}
