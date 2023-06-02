/*
** EPITECH PROJECT, 2022
** game
** File description:
** send_sig
*/
#include "src.h"

coord_t send_sig_to_enemy(char *attack, game_info_t *game_info)
{
    int nb_letter = letter_into_int(attack[0]);
    int number = (attack[1] - 48);
    coord_t coord = {number, nb_letter};
    for (int i = 0; i < nb_letter; i++) {
        kill(game_info->pid_ennemy, SIGUSR1);
        nanosleep((const struct timespec[]){{0, 500000000L}}, NULL);
    }
    kill(game_info->pid_ennemy, SIGUSR2);
    nanosleep((const struct timespec[]){{0, 500000000L}}, NULL);
    for (int i = 0; i < number; i++) {
        kill(game_info->pid_ennemy, SIGUSR1);
        nanosleep((const struct timespec[]){{0, 500000000L}}, NULL);
    }
    kill(game_info->pid_ennemy, SIGUSR2);
    nanosleep((const struct timespec[]){{0, 500000000L}}, NULL);
    return (coord);
}

void send_sig_to_host(char *attack, game_info_t *game_info)
{
    int nb_letter = letter_into_int(attack[0]);
    int number = (attack[1] - 48);
    for (int i = 0; i < nb_letter; i++) {
        kill(game_info->pid_host, SIGUSR1);
        nanosleep((const struct timespec[]){{0, 500000000L}}, NULL);
    }
    kill(game_info->pid_host, SIGUSR2);
    nanosleep((const struct timespec[]){{0, 500000000L}}, NULL);
    for (int i = 0; i < number; i++) {
        kill(game_info->pid_host, SIGUSR1);
        nanosleep((const struct timespec[]){{0, 500000000L}}, NULL);
    }
    kill(game_info->pid_host, SIGUSR2);
    nanosleep((const struct timespec[]){{0, 500000000L}}, NULL);
}
