/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** save_grid
*/
/**
 * @file save_grid.c
 *
 * @brief Save the grid of the map
 *
 * @date 06/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_unit.h"

static char *save_tile(sfVector2i coord, tile_t tile, tile_pos_set_t *tile_pos)
{
    char *save_str = NULL;
    char *solid = NULL;

    if (tile.texture == NULL) {
        if (tile.solid)
            save_str = str_cat(save_str, "-/1\n");
        else
            save_str = str_cat(save_str, "-/0\n");
        return (save_str);
    }
    if (tile.solid == 1)
        solid = str_cat(solid, "1\n");
    else
        solid = str_cat(solid, "0\n");
    save_str = str_cat(save_str, tile_pos[coord.y].tile_pos[coord.x]);
    save_str = str_cat(save_str, COL_DEL);
    save_str = str_cat(save_str, solid);
    free(solid);
    return (save_str);
}

static char *save_grid_size(grid_t *grid)
{
    char *x = NULL;
    char *y = NULL;
    char *save_str = NULL;

    x = int_to_string(grid->limit.x);
    y = int_to_string(grid->limit.y);
    save_str = str_cat(save_str, x);
    save_str = str_cat(save_str, COORD_DEL);
    save_str = str_cat(save_str, y);
    save_str = str_cat(save_str, COORD_DEL);
    save_str = str_cat(save_str, ENTRY);
    free(x);
    free(y);
    return (save_str);
}

static void write_file(char *name, char *str)
{
    char *file_name = NULL;
    int file;

    file_name = str_cat(file_name, name);
    file_name = str_cat(file_name, ".txt");
    file = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (file == -1) {
        free(str);
        return;
    }
    write(file, str, str_len(str));
    close(file);
    free(str);
    free(file_name);

}

/*
//map_edit->unit_pos_set = unit_pos_set_add((game_unit_info_t){(sfVector2i){
      //  index.x, index.y}, map_edit->tile_coord_select, map_edit->set_nb});
*/
static char *save_unit_info(map_edit_t *map_edit)
{
    char *str = NULL;
    game_unit_t *tmp = NULL;

    if (map_edit->units->first == NULL)
        return ("INFO DATA : NO\n");
    str = str_cat(str, "INFO DATA : YES\n");
    tmp = map_edit->units->first;
    while (tmp) {
        str = str_cat(str, unit_pos_set_add((game_unit_info_t){tmp->pos_grid,
            tmp->pos_asset, tmp->set}));
        tmp = tmp->next;
    }
    return (str);
}

void map_editor_save_grid(map_edit_t *map_edit, char *name)
{
    char *save_str = NULL;

    if (!map_edit)
        return;
    save_str = save_grid_size(map_edit->grid);
    for (u_int i = 0; i < map_edit->grid->limit.y; i++) {
        for (u_int j = 0; j < map_edit->grid->limit.x; j++) {
            save_str = str_cat(save_str, save_tile((sfVector2i){j, i},
                map_edit->grid->tiles[i][j], map_edit->tiles_pos_set));
        }
    }
    save_str = str_cat(save_str,save_unit_info(map_edit));
    write_file(name, save_str);
    return;
}
