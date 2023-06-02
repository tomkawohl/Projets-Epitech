/*
** EPITECH PROJECT, 2022
** src
** File description:
** main
*/
#include "src.h"
int game_state = EARLY;

int init_game_info(int ac, char **av, game_info_t *game_info)
{
    if (ac == 2) {
        game_info->state = HOST;
        if (handle_error_host(av) == -1)
            return (-1);
    } else {
        game_info->state = ENEMY;
        if (handle_error_enemy(av) == -1)
            return (-1);
    }
    return (0);
}

/* rm GAME_INFO */
int main(int ac, char **av)
{
    game_info_t game_info = {HOST, 0, 0};
    map_t *map = NULL;
    if (ac != 2 && ac != 3) return (84);
    if (init_game_info(ac, av, &game_info) == -1)
        return (84);
    get_player(&game_info);
    if (config_game(av, &game_info) == -1) return (84);
    map = map_struct_init();
    init_pid_enemy(&game_info);
    get_player(&game_info);
    if (all_map_init(&map->map_host, &map->map_enemy, &game_info, av) == -1)
        return (84);
    if (all_map_opponent_init(&map->host_vs, &map->enemy_vs) == -1)
        return (84);
    game_handle(map, &game_info);
    free_map(map->map_host, map->map_enemy, &game_info);
    free_array_str2d(map->enemy_vs);
    free_array_str2d(map->host_vs);
    free(map);
    return (0);
}
