/*
** EPITECH PROJECT, 2022
** src
** File description:
** map.h
*/

#ifndef MAP_H_
    #define MAP_H_
    #include "src.h"

/* all_map_init */
int all_map_init(char ***map_host, char ***map_enemy,
game_info_t *game_info, char **av);
int all_map_opponent_init(char ***host_opponent, char ***enemy_opponent);
/* map_display */
void map_display(map_t *map, game_info_t *game_info);

/* free_map */
void free_map(char **map_host, char **map_enemy, game_info_t *game_info);

/* attack_map */
int attack_map(int number, int letter, char **map);
#endif /* MAP_H_ */
