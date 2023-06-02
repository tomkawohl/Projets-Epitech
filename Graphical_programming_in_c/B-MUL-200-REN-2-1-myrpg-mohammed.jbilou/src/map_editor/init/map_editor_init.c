/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** map_editor_init
*/
/**
 * @file map_editor_init.c
 *
 * @brief Init struct of map editor
 *
 * @date 06/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "map_editor.h"

static edit_object_t map_editor_init_cursor(sfSprite *set)
{
    edit_object_t cursor;
    sfIntRect select = CURSOR_SELECTED;
    sfVector2f set_pos = sfSprite_getPosition(set);

    cursor.texture = sfTexture_createFromFile(CURSOR_ASSET, &select);
    cursor.sprite = sfSprite_create();
    cursor.pos = (sfVector2i){0, 0};
    sfSprite_setTexture(cursor.sprite, cursor.texture, sfFalse);
    sfSprite_setScale(cursor.sprite, (sfVector2f){3.0, 3.0});
    sfSprite_setPosition(cursor.sprite, set_pos);
    return (cursor);
}

static edit_object_t map_editor_init_tile_cursor(void)
{
    edit_object_t cursor;
    sfIntRect select = CURSOR_TILE;

    cursor.texture = sfTexture_createFromFile(CURSOR_ASSET, &select);
    cursor.sprite = sfSprite_create();
    cursor.pos = (sfVector2i){0, 0};
    sfSprite_setTexture(cursor.sprite, cursor.texture, sfFalse);
    sfSprite_setScale(cursor.sprite, (sfVector2f){3.0, 3.0});
    sfSprite_setPosition(cursor.sprite, (sfVector2f){CANVA_X, CANVA_Y});
    return (cursor);
}

static void init_value(map_edit_t *map_edit)
{
    map_edit->state = DEFAULT;
    map_edit->set_is_activ = true;
    map_edit->set_nb = 0;
    map_edit->tile_coord_select = (sfVector2i){0, 0};
    map_edit->delta_move = (sfVector2f){0, 0};
}

map_edit_t *map_editor_init(void)
{
    map_edit_t *map_edit = malloc(sizeof(*map_edit));
    if (!verify_malloc(map_edit, "map_editor_init")) return (NULL);
    map_edit->grid = grid_create(GRID_X, GRID_Y,
        (sfVector2f){CANVA_X, CANVA_Y});
    map_edit->buttons = map_editor_button_init();
    map_edit->set = map_editor_init_set();
    map_edit->set_sprite = sfSprite_create();
    sfSprite_setTexture(map_edit->set_sprite, map_edit->set[0].texture,
        sfFalse);
    sfSprite_setPosition(map_edit->set_sprite, (sfVector2f){0, SET_POS_Y});
    map_edit->selected = map_editor_init_cursor(map_edit->set_sprite);
    map_edit->tile_place = map_editor_init_tile_cursor();
    map_edit->list_col = edit_obj_create();
    map_edit->tiles_pos_set = tile_pos_set_init(map_edit->grid->limit);
    init_value(map_edit);
    map_edit->list_text = map_edit_list_text_init();
    map_edit->units = game_unit_list_create();
    map_edit->file_to_open = NULL;
    return (map_edit);
}
