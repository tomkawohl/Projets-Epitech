/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** map_editor_handle_sreen
*/
/**
 * @file map_editor_handle_sreen.c
 *
 * @brief Handle screen for map editor
 *
 * @date 10/04/2023
*/
#include "src.h"
#include "lib_will.h"

void map_editor_handle_screen(sfRenderWindow *win, map_edit_t *map_edit)
{
    sfRenderWindow_clear(win, sfBlack);
    map_editor_draw(win, map_edit);
    sfRenderWindow_display(win);
}
