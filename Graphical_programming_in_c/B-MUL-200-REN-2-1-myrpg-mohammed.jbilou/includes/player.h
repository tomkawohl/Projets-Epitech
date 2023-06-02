/*
** EPITECH PROJECT, 2023
** include
** File description:
** player.h
*/

#ifndef PLAYER_H_
    #define PLAYER_H_
    #include "src_struct.h"

/**
 * @brief Set a position to the player struct
 *
 * @param gm game_t *
 * @param pos sfVector2i : for example {0.5} move the player at x 0 and y 5
 * on grid of tiles
 */
void player_set_pos(game_t *gm, sfVector2i pos);

/**
 * @brief Update position of player in game
 *
 * @param gm game_t *
 */
void update_pos_player(game_t *gm);

/**
 * @brief Update view when player move
 *
 * @param gm game_t *
 */
void update_view(game_t *gm);

/**
 * @brief Update player data
 *
 * @param gm game_t *
 */
void player_update(game_t *gm);

/**
 * @brief Move the player in game
 *
 * @param gm game_t *
 */
void move_player(game_t *gm);

/**
 * @brief Verify if a player can move on the tile
 *
 * @param gm game_t *
 * @param pos sfVector2i pos
 * @return true if there is no colision
 * @return false if there is a colision
 */
/*
bool player_can_move(game_t *gm, sfVector2i pos);
*/

/**
 * @brief Verify if a player can move on the tile
 *
 * @param gm game_t *
 * @param vector Vector where he move
 * @return true if there is no colision
 * @return false false if there is colision
 */
bool player_can_move(game_t *gm, sfVector2f vector);
#endif /* PLAYER_H_ */
