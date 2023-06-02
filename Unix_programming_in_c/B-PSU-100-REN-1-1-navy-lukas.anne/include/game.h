/*
** EPITECH PROJECT, 2022
** include
** File description:
** game_handle
*/

#ifndef GAME_H_
    #define GAME_H_
    #include "src.h"

/* game_handle */
int game_handle(map_t *map, game_info_t *game_info);

/* game_host */
void game_host(game_info_t *game_info, map_t *map);
void game_enemy(game_info_t *game_info, map_t *map);

/* input */
coord_t get_input_host(game_info_t *game_info);
int get_input_enemy(game_info_t *game_info);

/* send_sig */
coord_t send_sig_to_enemy(char *attack, game_info_t *game_info);
void send_sig_to_host(char *attack, game_info_t *game_info);

/* sig_enemy */
int get_nb_sig_enemy(int incrementation, int reset);
void get_sig_enemy(void);
int get_letter_enemy(int incrementation, int reset);
int get_number_enemy(int incrementation, int reset);

/* sig_host */
int get_nb_sig_host(int incrementation, int reset);
void get_sig_host(void);
int get_letter_host(int incrementation, int reset);
int get_number_host(int incrementation, int reset);

/* handler_sig */
void handler_sig(UNUSED int signal, siginfo_t *info, UNUSED void *data);

/* game_early */
void game_early_host(siginfo_t *info);
#endif /* GAME_H_ */
