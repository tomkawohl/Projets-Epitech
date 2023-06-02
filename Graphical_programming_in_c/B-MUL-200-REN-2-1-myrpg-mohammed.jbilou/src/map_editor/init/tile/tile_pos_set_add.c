/*
** EPITECH PROJECT, 2023
** map_editor/tile
** File description:
** tile_pos_set_add
*/
/**
 * @file tile_pos_set_add.c
 *
 * @brief Add tile_pos_set
 *
 * @date 10/04/2023
*/
#include "src.h"
#include "lib_will.h"

static char *get_tile_info(char *set, char *asset_x, char *asset_y)
{
    char *str = NULL;

    str = str_cat(str, set);
    str = str_cat(str, COORD_DEL);
    str = str_cat(str, asset_x);
    str = str_cat(str, COORD_DEL);
    str = str_cat(str, asset_y);
    str = str_cat(str, TILE_DEL);
    return (str);
}

void tile_pos_set_add(tile_pos_set_t *tile, info_tile_t info,
sfVector2i pos, sfVector2i limit)
{
    char *set = NULL;
    char *asset_x = NULL;
    char *asset_y = NULL;

    if (pos.x >= limit.x || pos.y >= limit.y)
        return;
    set = int_to_string((long long)info.set);
    asset_x = int_to_string(info.coord.x);
    asset_y = int_to_string(info.coord.y);
    tile[pos.y].tile_pos[pos.x] = str_cat(tile[pos.y].tile_pos[pos.x],
        get_tile_info(set, asset_x, asset_y));
    free(set);
    free(asset_x);
    free(asset_y);
    return;
}

/*
typedef struct game_unit_info_s {
    sfVector2i pos_grid;
    sfVector2i pos_asset;
    int set;
} game_unit_info_t;
*/
static char *get_unit_info(char *set, char *asset_x, char *asset_y,
    char *pos_grid_x)
{
    char *str = NULL;

    str = str_cat(str, set);
    str = str_cat(str, COORD_DEL);
    str = str_cat(str, asset_x);
    str = str_cat(str, COORD_DEL);
    str = str_cat(str, asset_y);
    str = str_cat(str, COORD_DEL);
    str = str_cat(str, pos_grid_x);
    str = str_cat(str, COORD_DEL);
    return (str);
}

char *unit_pos_set_add(game_unit_info_t info)
{
    char *units = NULL;
    char *set = int_to_string(info.set);
    char *asset_x = int_to_string(info.pos_asset.x);
    char *asset_y = int_to_string(info.pos_asset.y);
    char *pos_grid_x = int_to_string(info.pos_grid.x);
    char *pos_grid_y = int_to_string(info.pos_grid.y);

    units = str_cat(units, get_unit_info(set, asset_x, asset_y, pos_grid_x));
    units = str_cat(units, pos_grid_y);
    units = str_cat(units, "\n");
    free(set);
    free(asset_x);
    free(asset_y);
    free(pos_grid_x);
    free(pos_grid_y);
    return (units);
}
