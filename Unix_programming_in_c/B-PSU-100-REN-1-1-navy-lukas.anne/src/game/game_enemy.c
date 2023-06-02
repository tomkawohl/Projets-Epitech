/*
** EPITECH PROJECT, 2022
** game
** File description:
** game_enemy
*/
#include "src.h"

void game_enemy(game_info_t *game_info, map_t *map)
{
    int letter = 0;
    int number = 0;
    if (game_info->state == ENEMY) {
            get_input_enemy(game_info);
            game_state = ATTACK;
        } else {
            game_state = EARLY;
            get_sig_host();
            while (get_nb_sig_host(FALSE, FALSE) != 2);
            get_nb_sig_host(FALSE, TRUE);
            letter = get_letter_host(FALSE, FALSE);
            number = get_number_host(FALSE, FALSE);
            attack_map(number, letter, map->map_host);
            get_letter_host(FALSE, TRUE);
            get_number_host(FALSE, TRUE);
        }
}
