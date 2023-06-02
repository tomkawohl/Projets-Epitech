/*
** EPITECH PROJECT, 2023
** file_map
** File description:
** file_to_map_unit
*/
/**
 * @file file_to_map_unit.c
 *
 * @brief Init a game_unit_list_t * by file.map
 *
 * @date 16/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "parser.h"

static void add_game_unit(game_unit_list_t *list, char *str)
{
    u_int set = 0;
    u_int idx_arg = 0;
    sfVector2i unit_asset_pos = {0, 0};
    sfVector2i unit_grid_pos = {0, 0};

    set = my_atoi (&(str[idx_arg]));
    update_idx_arg(str, &idx_arg);
    unit_asset_pos.x = my_atoi(&(str[idx_arg]));
    update_idx_arg(str, &idx_arg);
    unit_asset_pos.y = my_atoi(&(str[idx_arg]));
    update_idx_arg(str, &idx_arg);
    unit_grid_pos.x = my_atoi(&(str[idx_arg]));
    update_idx_arg(str, &idx_arg);
    unit_grid_pos.y = my_atoi(&(str[idx_arg]));
    game_unit_list_add(list, (game_unit_info_t){unit_grid_pos,
        unit_asset_pos, set});
}

static game_unit_list_t *get_game_unit_list(char **map_data)
{
    game_unit_list_t *list = game_unit_list_create();
    u_int i = 0;

    if (!list)
        return (NULL);
    while (str_find(map_data[i], "INFO DATA") == false
        && map_data[i] != NULL)
            i++;
    if (str_find(map_data[i], "NO"))
        return (list);
    i++;
    while (map_data[i] != NULL) {
        add_game_unit(list, map_data[i]);
        i++;
    }
    return (list);
}

game_unit_list_t *file_to_map_unit(const char *file)
{
    game_unit_list_t *list = NULL;
    char **map_data = NULL;

    if (!file)
        return (NULL);
    map_data = get_map_data(file);
    if (!map_data)
        return (NULL);
    list = get_game_unit_list(map_data);
    free_array_str2d(map_data);
    return (list);
}
