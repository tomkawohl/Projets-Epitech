/*
** EPITECH PROJECT, 2023
** events_main_menu.c
** File description:
** handles all the events in the menu
*/

#include "src.h"
#include "menu.h"
#include "collisions.h"
#include "parser.h"
#include "test_area.h"
#include "lib_will.h"
#include "player.h"

static void check_mouse_on(game_t *gm)
{
    menu_t *menu = gm->start->menu;

    for (size_t i = 0; i < NB_BUTTONS_START; i++) {
        if (mouse_over_rect(menu[i].rect[0], gm->mouse, gm->wd) == true)
            menu[i].is_on_button = true;
        else
            menu[i].is_on_button = false;
    }
}

static void init(game_t *gm)
{
    char *file = file_to_str_stat("save/save_game.txt");
    char **data = NULL;
    u_int i = 0;
    sfVector2i pl_pos = {0, 0};

    if (str_find(file, "NO"))
        return;
    data = str1d_to_str2d(file);
    gm->changing_scene = my_getnbr_int(data[1]);
    pl_pos.x = my_getnbr_int(data[2]);
    update_idx_arg(data[2], &i);
    pl_pos.y = my_getnbr_int(&(data[2][i]));
    player_set_pos(gm, pl_pos);
    scene_change(gm);
    gm->g_scene = map_run;
    gm->g_scene(gm);
}

static void reset_save(void)
{
    int fd = 0;
    char *str = "SAVE:NO\n";

    fd = open("save/save_game.txt", O_WRONLY | O_CREAT
        | O_TRUNC, 0777);
    write(fd, str, str_len(str));
    close(fd);
}

static void handle_buttons(game_t *gm, menu_t *menu)
{
    if (mouse_over_rect(menu[SETTINGS_BUTTON].rect[1], gm->mouse, gm->wd))
        gm->scene = SETTINGS_SCENE;
    if (mouse_over_rect(menu[EDIT_BUTTON].rect[1], gm->mouse, gm->wd) == true)
        map_editor(gm->wd, gm);
    if (mouse_over_rect(menu[HOW_TO_PLAY_BUTTON].rect[1], gm->mouse, gm->wd))
        gm->scene = HOW_TO_PLAY_SCENE;
    if (mouse_over_rect(menu[RESUME_BUTTON].rect[1], gm->mouse, gm->wd))
        init(gm);
}

void events_main_menu(game_t *gm)
{
    menu_t *menu = gm->start->menu;

    if (gm->scene != 0)
        return;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (mouse_over_rect(menu[EXIT_BUTTON].rect[1], gm->mouse, gm->wd))
            sfRenderWindow_close(gm->wd);
        if (mouse_over_rect(menu[START_BUTTON].rect[1], gm->mouse, gm->wd)){
            reset_save();
            gm->scene = IN_GAME_SCENE;
            gm->changing_scene = ROOM;
            sfMusic_stop(gm->main_music);
            return;
        }
        handle_buttons(gm, menu);
    }
    check_mouse_on(gm);
}
