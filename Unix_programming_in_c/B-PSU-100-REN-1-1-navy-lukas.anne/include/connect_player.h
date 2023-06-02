/*
** EPITECH PROJECT, 2022
** src
** File description:
** connect_player
*/

#ifndef CONNECT_PLAYER_H_
    #define CONNECT_PLAYER_H_
    #define UNUSED __attribute__((unused))
    #include <signal.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include "src.h"
/* player.c */
int config_game(char **av, game_info_t *game_info);

/* is_connected */
int is_connected(int flag);

/* protocol_connection.c */
void connect_protocol(void);
int host_get_pid_enemy(int pid_enemy, int get);

/* init_pid_enemy */
void init_pid_enemy(game_info_t *game_info);

/* get_player */
game_info_t get_player(game_info_t *game_info);
#endif
