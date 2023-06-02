/*
** EPITECH PROJECT, 2023
** events_ig_menu.c
** File description:
** events_ig_menu
*/

#include "src.h"
#include "menu.h"
#include "collisions.h"
#include "lib_will.h"

static void check_mouse_on(game_t *gm)
{
    in_game_menu_t *ig_menu = gm->ig_menu;

    for (size_t i = 0; i < NB_BUTTONS_IG_MENU; i++) {
        if (mouse_over_rect(ig_menu[i].rect[0], gm->mouse, gm->wd) == true) {
            ig_menu[i].is_on_button = true;
        } else
            ig_menu[i].is_on_button = false;
    }
}

static void write_save(char *str)
{
    int fd = 0;

    fd = open("save/save_game.txt", O_WRONLY | O_CREAT
        | O_TRUNC, 0777);
    write(fd, str, str_len(str));
    close(fd);
}

static void save(game_t *gm)
{
    char *str = NULL;
    char *scene = int_to_string(gm->current_scene);
    char *x = int_to_string(gm->pl->pos.x);
    char *y = int_to_string(gm->pl->pos.y);

    str = str_cat(str, "SAVE:YES\n");
    str = str_cat(str, scene);
    str = str_cat(str, "\n");
    str = str_cat(str, x);
    str = str_cat(str, "/");
    str = str_cat(str, y);
    str = str_cat(str, "\n");
    write_save(str);
    free(str);
}

static int handle_buttons(game_t *gm, in_game_menu_t *ig_menu)
{
    if (mouse_over_rect(ig_menu[QUIT_BUTTON_IG].rect[1], gm->mouse, gm->wd))
        return 0;
    if (mouse_over_rect(ig_menu[SAVE_BUTTON_IG].rect[1], gm->mouse,
        gm->wd)) {
        save(gm);
        return 1;
    }
    return (-1);
}

int events_ig_menu(game_t *gm)
{
    in_game_menu_t *ig_menu = gm->ig_menu;

    while (sfRenderWindow_pollEvent(gm->wd, &(gm->event))){
        gm->mouse = sfMouse_getPositionRenderWindow(gm->wd);
        check_mouse_on(gm);
        if (!sfMouse_isButtonPressed(sfMouseLeft))
            continue;
        if (mouse_over_rect(ig_menu[RESUME_BUTTON_IG].rect[1], gm->mouse,
            gm->wd))
            return 2;
        if (mouse_over_rect(ig_menu[SETTING_BUTTON_IG].rect[1], gm->mouse,
            gm->wd)) {
            gm->scene = SETTINGS_SCENE;
            return 1;
        }
        return (handle_buttons(gm, ig_menu));
    }
    return (-1);
}
