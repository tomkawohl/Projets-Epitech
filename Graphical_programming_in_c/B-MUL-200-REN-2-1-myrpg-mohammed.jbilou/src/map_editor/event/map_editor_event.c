/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** map_editor_event
*/
/**
 * @file map_editor_event.c
 *
 * @brief Handle editor event
 *
 * @date 10/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include <math.h>
#include "parser.h"
#include "menu.h"

static void check_button_clicked(map_edit_t *map_edit, game_t *gm)
{
    if (mouse_over_rect(map_edit->buttons[2].rect[0], gm->mouse, gm->wd)
        == true) {
        gm->m_wd[0] = init_info_pop_win(gm->m_wd[0],
        "new", 3, (sfVector2u){600, 300});
        create_new_window(gm, gm->m_wd[0], "save/pop_up/new.txt", map_edit);
    }
    if (mouse_over_rect(map_edit->buttons[3].rect[0], gm->mouse, gm->wd)
        == true) {
        gm->m_wd[1] = init_info_pop_win(gm->m_wd[1],
        "save", 3, (sfVector2u){600, 300});
        create_new_window(gm, gm->m_wd[1], "save/pop_up/save.txt", map_edit);
    }
    if (mouse_over_rect(map_edit->buttons[4].rect[0], gm->mouse, gm->wd)
        == true) {
        gm->m_wd[1] = init_info_pop_win(gm->m_wd[2],
        "open", 3, (sfVector2u){600, 300});
        create_new_window(gm, gm->m_wd[1], "save/pop_up/open.txt", map_edit);
    }
}

static void check_mouse_on(map_edit_t *map_edit, game_t *gm)
{
    for (size_t i = 2; i < NB_BUTTON_EDIT; i++) {
        if (mouse_over_rect(map_edit->buttons[i].rect[0], gm->mouse, gm->wd))
            map_edit->buttons[i].mouseOn = false;
        else
            map_edit->buttons[i].mouseOn = true;
    }
}

static void handle_mouse_button_pressed(map_edit_t *map_edit,
    sfMouseButtonEvent *mouse)
{
    update_selected(map_edit, mouse);
    map_editor_update_grid(map_edit, mouse);
    map_editor_col_event(map_edit, mouse);
    delete_event(map_edit, mouse);
    map_edit_unit_event(map_edit, mouse);
    map_edit_unit_delete_event(map_edit, mouse);
}

static void handle_key_pressed(map_edit_t *map_edit, sfEvent event,
    bool *can_press)
{
    save_grid_event(map_edit, event, can_press);
    update_tools_selection(map_edit, event, can_press);
    hide_set(map_edit, event, can_press);
    open_file_map_event(map_edit, event, can_press);
    swap_set_event(map_edit, event, can_press);
    new_grid_event(map_edit, can_press);
    handle_view_event(map_edit, can_press);
    *can_press = false;
}

void map_editor_handle_event(game_t *gm, map_edit_t *map_edit)
{
    static bool can_press = true;

    while (sfRenderWindow_pollEvent(gm->wd, &(gm->event))) {
        gm->mouse = sfMouse_getPositionRenderWindow(gm->wd);
        if (gm->event.type == sfEvtMouseButtonPressed) {
            handle_mouse_button_pressed(map_edit, &(gm->event.mouseButton));
            check_button_clicked(map_edit, gm);
        }
        if (gm->event.type == sfEvtClosed)
            sfRenderWindow_close(gm->wd);
        if (gm->event.type == sfEvtMouseMoved) {
            update_tile_place(map_edit, &(gm->event.mouseMove));
            check_mouse_on(map_edit, gm);
        }
        if (gm->event.type == sfEvtKeyPressed)
            handle_key_pressed(map_edit, gm->event, &can_press);
        if (gm->event.type == sfEvtKeyReleased)
            can_press = true;
    }
}
