/*
** EPITECH PROJECT, 2023
** map_editor/tile
** File description:
** tile_pos_set_update
*/
/**
 * @file tile_pos_set_update.c
 *
 * @brief Update tile_pos_set
 *
 * @date 10/04/2023
*/
#include "src.h"
#include "lib_will.h"

static void add_tile_data(tile_pos_set_t *tile_pos, char **map_data,
    u_int tile, sfVector2i coord)
{
    u_int length = 0;

    if (map_data[tile][0] == '-')
        return;
    length = str_len(map_data[tile]);
    map_data[tile][length - 3] = '\0';
    tile_pos[coord.y].tile_pos[coord.x] =
        str_cat(tile_pos[coord.y].tile_pos[coord.x], map_data[tile]);
}

static void update_data(tile_pos_set_t *tile_pos, char **map_data,
    sfVector2i limit)
{
    u_int tile = 1;

    for (u_int i = 0; i < limit.y; i++) {
        for (u_int j = 0; j < limit.x; j++) {
            add_tile_data(tile_pos, map_data, tile, (sfVector2i){j, i});
            tile++;
        }
    }
}

tile_pos_set_t *tile_pos_set_update(tile_pos_set_t *prev, const char *file,
    sfVector2i limit, map_edit_t *map_edit)
{
    char **map_data = NULL;
    tile_pos_set_t *tile_pos = NULL;
    sfVector2i new_limit = {0, 0};
    sfVector2f new_size_canva = {0, 0};

    map_data = get_map_data(file);
    if (!map_data)
        return (prev);
    new_limit = get_limit(map_data);
    new_size_canva = (sfVector2f){new_limit.x * TILE_SIZE,
        new_limit.y * TILE_SIZE};
    destroy_tile_pos_set(prev, limit);
    tile_pos = tile_pos_set_init(new_limit);
    update_data(tile_pos, map_data, new_limit);
    free_array_str2d(map_data);
    sfRectangleShape_setSize(map_edit->buttons[1].rect[0], new_size_canva);
    return (tile_pos);
}
