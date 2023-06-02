/*
** EPITECH PROJECT, 2023
** file_map
** File description:
** file_to_map
*/
/**
 * @file file_to_map.c
 *
 * @brief Init a map by file.map
 *
 * @date 08/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "parser.h"

sfVector2i get_limit(char **map_data)
{
    sfVector2i limit = {0, 0};
    u_int i = 0;

    limit.x = my_atoi(&(map_data[0][0]));
    while (map_data[0][i] != COORD_DEL_CHAR)
        i++;
    limit.y = my_atoi(&(map_data[0][++i]));
    return (limit);
}

static void add_tile_coord(grid_t *grid, char *str, u_int tile,
    sfVector2i index)
{
    u_int idx_arg = 0;
    u_int set = 0;
    sfVector2i tile_coord = {0, 0};

    set = my_atoi(&(str[idx_arg]));
    update_idx_arg(str, &idx_arg);
    tile_coord.x = my_atoi(&(str[idx_arg]));
    update_idx_arg(str, &idx_arg);
    tile_coord.y = my_atoi(&(str[idx_arg]));
    update_idx_arg(str, &idx_arg);
    tile_set(grid, (info_tile_t){set, tile_coord}, index);
}

static void add_tile(grid_t *grid, char **map_data, u_int tile,
    sfVector2i index)
{
    u_int i = 0;
    u_int colision = 0;

    if (map_data[tile][0] == '-') {
        if (my_atoi(&(map_data[tile][2])) == 1)
            grid->tiles[index.x][index.y].solid = true;
        return;
    }
    while (map_data[tile][i] != COL_DEL_CHAR && map_data[tile][i] != '\0') {
        add_tile_coord(grid, &(map_data[tile][i]), tile, index);
        while (map_data[tile][i] != TILE_DEL_CHAR)
            i++;
        i++;
    }
    if (map_data[tile][i + 1] == '\0')
        return;
    colision = my_atoi(&(map_data[tile][i + 1]));
    if (colision == 1)
        grid->tiles[index.x][index.y].solid = true;
}

static grid_t *get_grid(char **map_data, bool is_map_editor)
{
    sfVector2i limit = {0, 0};
    grid_t *grid = NULL;
    u_int tile = 1;

    limit = get_limit(map_data);
    if (limit.x <= 0 || limit.y <= 0)
        return (NULL);
    if (is_map_editor)
        grid = grid_create(limit.x, limit.y, (sfVector2f){CANVA_X, CANVA_Y});
    else
        grid = grid_create(limit.x, limit.y, (sfVector2f){0, 0});
    if (!grid)
        return (NULL);
    for (u_int i = 0; i < limit.y; i++) {
        for (u_int j = 0; j < limit.x; j++) {
            add_tile(grid, map_data, tile, (sfVector2i){i, j});
            tile++;
        }
    }
    return (grid);
}

grid_t *file_to_map(const char *file, bool is_map_editor)
{
    char **map_data = NULL;
    grid_t *grid = NULL;

    map_data = get_map_data(file);
    if (!map_data)
        return (NULL);
    grid = get_grid(map_data, is_map_editor);
    free_array_str2d(map_data);
    return (grid);
}
