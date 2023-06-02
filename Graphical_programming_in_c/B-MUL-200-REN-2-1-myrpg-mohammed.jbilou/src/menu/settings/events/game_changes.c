/*
** EPITECH PROJECT, 2023
** game_changes.c
** File description:
** game_changes
*/

#include "src.h"
#include "menu.h"
#include "collisions.h"

static void set_draw_false(settings_t *st)
{
    for (size_t i = 8; i < 17; i++)
        st[i].can_draw = false;
}

void check_frames_clicked(game_t *gm, settings_t *st)
{
    if (mouse_over_rect(st[_30_BUTTON].rect[1], gm->mouse, gm->wd))
        sfRenderWindow_setFramerateLimit(gm->wd, 30);
    if (mouse_over_rect(st[_60_BUTTON].rect[1], gm->mouse, gm->wd))
        sfRenderWindow_setFramerateLimit(gm->wd, 60);
    if (mouse_over_rect(st[_120_BUTTON].rect[1], gm->mouse, gm->wd))
        sfRenderWindow_setFramerateLimit(gm->wd, 120);
}

void check_resolution_clicked(game_t *gm, settings_t *st)
{
    sfVideoMode mode = {0, 0, 32};

    if (mouse_over_rect(st[_1920_1080_BUTTON].rect[1], gm->mouse, gm->wd)){
        mode.height = 1080;
        mode.width = 1920;
        sfRenderWindow_destroy(gm->wd);
        gm->wd = sfRenderWindow_create(mode, "My_rpg",
        sfResize | sfClose, NULL);
    }
    if (mouse_over_rect(st[_Fullscreen_BUTTON].rect[1], gm->mouse, gm->wd)) {
        mode.height = 1080;
        mode.width = 1920;
        sfRenderWindow_destroy(gm->wd);
        gm->wd = sfRenderWindow_create(mode, "My_rpg", sfResize
        | sfFullscreen, NULL);
    }
}

void check_when_to_click(game_t *gm, settings_t *st)
{
    if (gm->button_scene == FPS_SCENE)
        check_frames_clicked(gm, st);
    if (gm->button_scene == RES_SCENE)
        check_resolution_clicked(gm, st);
}

void check_button_scene(game_t *gm, settings_t *st)
{
    switch (gm->button_scene) {
        case FPS_SCENE:
            set_draw_false(st);
            for (size_t i = 8; i <= 10; i++)
                st[i].can_draw = true;
        break;
        case RES_SCENE:
            set_draw_false(st);
            for (size_t i = 11; i <= 12; i++)
                st[i].can_draw = true;
        break;
        case CONTROL_SCENE:
            set_draw_false(st);
            for (size_t i = 13; i <= 16; i++)
                st[i].can_draw = true;
        break;
    }
}
