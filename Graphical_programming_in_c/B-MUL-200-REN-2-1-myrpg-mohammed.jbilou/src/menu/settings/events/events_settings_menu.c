/*
** EPITECH PROJECT, 2023
** events_settings_menu.c
** File description:
** events_settings_menu
*/

#include "src.h"
#include "menu.h"
#include "collisions.h"

static void check_mouse_on(game_t *gm)
{
    settings_t *st = gm->start->settings;

    for (size_t i = 0; i < NB_BUTTONS_SETTINGS; i++) {
        if (mouse_over_rect(st[i].rect[0], gm->mouse, gm->wd) == true)
            st[i].is_on_button = true;
        else
            st[i].is_on_button = false;
    }
    move_regulator(gm->sound, gm);
}

static void change_panel(settings_t *st, sfVector2f pos, sfVector2f size)
{
    sfRectangleShape_setPosition(st[3].rect[0], pos);
    sfRectangleShape_setPosition(st[3].rect[1], pos);
    sfRectangleShape_setSize(st[3].rect[0], size);
    sfRectangleShape_setSize(st[3].rect[1], size);
}

static void check_mouse_clicker(settings_t *st, sfVector2i mouse, game_t *gm)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (mouse_over_rect(st[BACK_BUTTON].rect[1], mouse, gm->wd))
            gm->scene = MAIN_MENU_SCENE;
        if (mouse_over_rect(st[0].rect[1], mouse, gm->wd)){
            change_panel(st, (Vect2f){500, 380}, (Vect2f){800, 200});
            gm->button_scene = FPS_SCENE;
            check_button_scene(gm, st);
        }
        if (mouse_over_rect(st[1].rect[1], mouse, gm->wd)) {
            change_panel(st, (Vect2f){600, 300}, (Vect2f){600, 450});
            gm->button_scene = RES_SCENE;
            check_button_scene(gm, st);
        }
        if (mouse_over_rect(st[2].rect[1], mouse, gm->wd)) {
            change_panel(st, (Vect2f){600, 300}, (Vect2f){600, 400});
            gm->button_scene = CONTROL_SCENE;
            check_button_scene(gm, st);
        }
        check_when_to_click(gm, st);
    }
}

void events_settings_menu(game_t *gm)
{
    if (gm->scene != SETTINGS_SCENE)
        return;
    gm->start->menu[SETTINGS_BUTTON].is_on_button = false;
    check_mouse_clicker(gm->start->settings, gm->mouse, gm);
    check_mouse_on(gm);
    set_level_sound(gm->sound, gm);
}
