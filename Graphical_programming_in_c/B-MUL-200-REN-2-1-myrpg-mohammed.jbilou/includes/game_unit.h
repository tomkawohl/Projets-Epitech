/*
** EPITECH PROJECT, 2023
** include
** File description:
** game_unit.h
*/

#ifndef GAME_UNIT_H_
    #define GAME_UNIT_H_
    #include <SFML/Graphics.h>

typedef struct game_unit_info_s {
    sfVector2i pos_grid;
    sfVector2i pos_asset;
    int set;
} game_unit_info_t;

typedef struct game_unit_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2i pos_grid;
    sfVector2i pos_asset;
    int set;
    struct game_unit_s *next;
    struct game_unit_s *prev;
} game_unit_t;

typedef struct game_unit_list_s {
    game_unit_t *first;
    game_unit_t *end;
    unsigned int size;
} game_unit_list_t;

/**
 * @brief Create a game_unit_list_t *
 *
 * @return game_unit_list_t*
 */
game_unit_list_t *game_unit_list_create(void);

/**
 * @brief Add a game_uni_t * to a list game_unit_list_t *
 *
 * @param list game_unit_list_t *
 * @param info game_unit_info_t
 */
void game_unit_list_add(game_unit_list_t *list, game_unit_info_t info);

/**
 * @brief Remove a game_unit_t *
 *
 * @param game_unit game_unit_t *
 */
void game_unit_remove(game_unit_t *game_unit);

/**
 * @brief Remove a game_unit_t * from a game_unit_list_t *
 *
 * @param list game_unit_list_t *
 */
void game_unit_list_remove(game_unit_list_t *list);

/**
 * @brief Destroy a game_unit_list_t *
 *
 * @param list game_unit_list_t *
 */
void game_unit_list_destroy(game_unit_list_t *list);

/**
 * @brief Draw all game_unit_t of a game_unit_list_t *
 *
 * @param win sfRenderWindow *
 * @param list game_unit_list_t *
 */
void game_unit_list_draw(sfRenderWindow *win, game_unit_list_t *list);

#endif /* GAME_UNIT_H_ */
