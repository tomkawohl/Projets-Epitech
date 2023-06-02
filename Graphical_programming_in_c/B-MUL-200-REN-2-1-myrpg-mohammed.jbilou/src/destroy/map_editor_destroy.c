/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** map_editor_destroy
*/
/**
 * @file map_editor_desotry.c
 *
 * @brief Destroy the struct map editor
 *
 * @date 06/04/2023
*/
#include "src.h"
#include "lib_will.h"

static void destroy_grid_coord(grid_tile_coord_set_t *grid_coord,
    sfVector2i limit)
{
    if (!grid_coord)
        return;
    for (u_int i = 0; i < limit.y; i++) {
        w_printf("i %d\n", i);
        for (u_int j = 0; j < limit.x; j++) {
            tile_coord_set_destroy(grid_coord[i].tile_coord[j]);
        }
    }
    free(grid_coord);
}

static void destroy_cursor(map_edit_t *map_edit)
{
    if (map_edit->selected.sprite != NULL)
        sfSprite_destroy(map_edit->selected.sprite);
    if (map_edit->selected.texture != NULL)
        sfTexture_destroy(map_edit->selected.texture);
    if (map_edit->tile_place.sprite != NULL)
        sfSprite_destroy(map_edit->tile_place.sprite);
    if (map_edit->tile_place.texture != NULL)
        sfTexture_destroy(map_edit->tile_place.texture);
}

static void free_str(char *str)
{
    if (!str)
        return;
    free(str);
}

void destroy_tile_pos_set(tile_pos_set_t *tile_pos, sfVector2i limit)
{
    if (!tile_pos)
        return;
    for (u_int i = 0; i < limit.y; i++) {
        for (u_int j = 0; j < limit.x; j++) {
            free_str(tile_pos[i].tile_pos[j]);
        }
        if (tile_pos[i].tile_pos) {
            free(tile_pos[i].tile_pos);
        }
    }
    if (tile_pos)
        free(tile_pos);
}

void map_edit_destroy(map_edit_t *map_edit)
{
    destroy_tile_pos_set(map_edit->tiles_pos_set, map_edit->grid->limit);
    game_unit_list_destroy(map_edit->units);
    grid_destroy(map_edit->grid);
    e_button_destroy_all(map_edit->buttons, NB_BUTTON_EDIT);
    for (u_int i = 0; i < NB_SET; i++) {
        if (map_edit->set[i].texture != NULL)
            sfTexture_destroy(map_edit->set[i].texture);
    }
    free(map_edit->set);
    sfSprite_destroy(map_edit->set_sprite);
    destroy_cursor(map_edit);
    edit_obj_destroy(map_edit->list_col);
    text_list_destroy(map_edit->list_text);
    free(map_edit);
}
