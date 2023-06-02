/*
** EPITECH PROJECT, 2023
** DESTROY
** File description:
** DESTROY
*/

#ifndef DESTROY_H
    #define DESTROY_H
    #include "src.h"


/**
 * @brief destroy and free all the game
 *
 * @param gm
 */
void destroy_game(game_t *gm);

/**
 * @brief destroy the menu structure
 *
 * @param menu
 */
void destroy_menu(menu_t *menu);

/**
 * @brief destroy all the elements in settings_t *
 *
 * @param st
 */
void destroy_settings(settings_t *st, sound_t *sd);
#endif /* !DESTROY_H */
