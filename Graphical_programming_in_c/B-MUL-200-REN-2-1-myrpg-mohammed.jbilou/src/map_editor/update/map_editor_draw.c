/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** map_editor_draw
*/
/**
 * @file map_editor_draw.c
 *
 * @brief Draw all map editor
 *
 * @date 06/04/2023
*/
#include "src.h"
#include "lib_will.h"

void map_editor_draw(sfRenderWindow *win, map_edit_t *map_edit)
{
    e_button_draw_all(win, map_edit->buttons);
    grid_draw(win, map_edit->grid->tiles);
    if (map_edit->state == COLLISION)
        edit_obj_draw(win, map_edit->list_col);
    if (map_edit->set_is_activ) {
        sfRenderWindow_drawSprite(win, map_edit->set_sprite, NULL);
        sfRenderWindow_drawSprite(win, map_edit->selected.sprite, NULL);
    }
    game_unit_list_draw(win, map_edit->units);
    sfRenderWindow_drawSprite(win, map_edit->tile_place.sprite, NULL);
    text_list_display(win, map_edit->list_text);
}
