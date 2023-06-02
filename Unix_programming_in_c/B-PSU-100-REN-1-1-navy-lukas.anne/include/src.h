/*
** EPITECH PROJECT, 2022
** src
** File description:
** src.h
*/

#ifndef SRC_H_
    #define SRC_H_
    #define HOST 1
    #define ENEMY 2
    #define HIT 'x'
    #define MISS 'o'
    #define EARLY 1
    #define ATTACK 2
    #define END 3
    #define _GNU_SOURCE

extern int game_state;
typedef struct map_s {
    char **map_host;
    char **map_enemy;
    char **host_vs;
    char **enemy_vs;
} map_t;

typedef struct game_info_s {
    int state;
    int pid_host;
    int pid_ennemy;
} game_info_t;

typedef struct coord_s {
    int number;
    int letter;
} coord_t;

    #include <time.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include "init_map.h"
    #include "connect_player.h"
    #include "map.h"
    #include "game.h"
    #include "manage_error.h"
    #include "state.h"
#endif /* SRC_H_ */
