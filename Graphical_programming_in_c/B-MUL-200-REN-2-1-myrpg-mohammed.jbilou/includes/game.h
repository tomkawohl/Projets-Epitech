/*
** EPITECH PROJECT, 2023
** game.h
** File description:
** game prototypes
*/

#ifndef GAME_H
    #define GAME_H
    #define MAIN_MUSIC "util/SONGS/Main_Menu.ogg"
    #define NIHIL_MUSIC "util/SONGS/Nihil_Music.ogg"
    #define HOUSE_MUSIC "util/SONGS/House_Music.ogg"

/**
 * @brief init all the game
 *
 * @param gm
 */
int init_game(game_t *gm);

/**
 * @brief Init data of game_t *gm
 *
 * @param gm game_t *
 */
void init_game_data(game_t *gm);


/**
 * @brief updates all the elements in the game
 *
 * @param gm
 */
void update_game(game_t *gm);

/**
 * @brief handles all the events in the game
 *
 * @param gm
 */
void events_game(game_t *gm);
#endif /* GAME_H */
