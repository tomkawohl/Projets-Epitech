/*
** EPITECH PROJECT, 2022
** game
** File description:
** game_host
*/
#include "src.h"

void game_host(game_info_t *game_info, map_t *map)
{
    int letter = 0;
    int number = 0;
    if (game_info->state == HOST) {
            get_input_host(game_info);
            game_state = ATTACK;
        } else {
            game_state = EARLY;
            get_sig_enemy();
            while (get_nb_sig_enemy(FALSE, FALSE) != 2);
            letter = get_letter_enemy(FALSE, FALSE);
            number = get_number_enemy(FALSE, FALSE);
            attack_map(number, letter, map->map_enemy);
            get_number_enemy(FALSE, TRUE);
            get_letter_enemy(FALSE, TRUE);
            get_nb_sig_enemy(FALSE, TRUE);
        }
}
