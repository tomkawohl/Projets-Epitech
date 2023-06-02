/*
** EPITECH PROJECT, 2023
** include
** File description:
** game_actor
*/

#ifndef GAME_ACTOR_H_
    #define GAME_ACTOR_H_
    #include "src.h"

enum ga_type {
    BASIC,
    ON_IT,
    ON_LINE,
    ON_LINE_LEFT,
    ON_LINE_RIGHT,
    ON_LINE_UP,
    ON_LINE_DOWN,
    ON_SQUARE
};

typedef struct info_actor_s {
    char *name;
    char *asset;
    sfIntRect rect;
    sfVector2i pos;
    bool is_activ;
    bool solid;
    u_int to_animate;
    u_int range;
    void (*interact)(game_t *gm);
    enum ga_type type;
    sfVector2i anim_set;
    float frame_rate;
    u_int nb_frame;
    u_int frame_state;
} info_actor_t;

typedef struct game_actor_s {
    char *name;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2i pos;
    sfIntRect rect;
    bool is_activ;
    bool solid;
    u_int to_animate;
    u_int range;
    void (*interact)(game_t *gm);
    enum ga_type type;
    sfVector2i anim_set;
    float frame_rate;
    u_int nb_frame;
    sfClock *clock_anim;
    u_int frame_state;
    struct game_actor_s *prev;
    struct game_actor_s *next;
    bool is_defeat;
} game_actor_t;

typedef struct game_actor_list_s {
    game_actor_t *first;
    game_actor_t *last;
    u_int size;
} game_actor_list_t;

/**
 * @brief Create a list of game actor
 *
 * @return game_actor_list_t*
 */
game_actor_list_t *game_actor_list_create(void);

/**
 * @brief Add a game actor to a list
 *
 * @param list game_actor_list_t *
 * @param info info of the new game actor to add
 */
void game_actor_add(game_actor_list_t *list, info_actor_t info);

/**
 * @brief Remove the last game actor added to the list
 *
 * @param list game_actor_list_t *
 */
void game_actor_remove(game_actor_list_t *list);

/**
 * @brief Destroy a list of game actor
 *
 * @param list game_actor_list_t *
 */
void game_actor_list_destroy(game_actor_list_t *list);

/**
 * @brief Draw a list of game actors activ and sprite != NULL
 *
 * @param win sfRenderWindow *win
 * @param list game_actor_list_t *
 */
void game_actor_list_draw(sfRenderWindow *win, game_actor_list_t *list);

/**
 * @brief Verify if a player is in range to interact with a game actor
 *
 * @param ga game_actor_t *
 * @param gm game_t *
 * @return true if he is in range
 * @return false if he isn't in range
 */
bool ga_is_in_range(game_actor_t *ga, game_t *gm);

/**
 * @brief Verify if a player is in range to interact with a game actor in line
 * direction left
 *
 * @param ga game_actor_t *
 * @param gm game_t *
 * @return true if he is in range
 * @return false if he isn't in range
 */
bool ga_is_in_line_left(game_actor_t *ga, game_t *gm);

/**
 * @brief Verify if a player is in range to interact with a game actor in line
 * direction right
 *
 * @param ga game_actor_t *
 * @param gm game_t *
 * @return true if he is in range
 * @return false if he isn't in range
 */
bool ga_is_in_line_right(game_actor_t *ga, game_t *gm);

/**
 * @brief Verify if a player is in range to interact with a game actor in line
 * direction up
 *
 * @param ga game_actor_t *
 * @param gm game_t *
 * @return true if he is in range
 * @return false if he isn't in range
 */
bool ga_is_in_line_up(game_actor_t *ga, game_t *gm);

/**
 * @brief Verify if a player is in range to interact with a game actor in line
 * direction down
 *
 * @param ga game_actor_t *
 * @param gm game_t *
 * @return true if he is in range
 * @return false if he isn't in range
 */
bool ga_is_in_line_down(game_actor_t *ga, game_t *gm);

/**
 * @brief Verify if a player in in range to interact with a game actor in line
 *
 * @param ga game_actor_t *
 * @param gm game_t *
 * @return true if he is in range
 * @return false if he isn't in range
 */
bool ga_is_in_line(game_actor_t *ga, game_t *gm);

/**
 * @brief Verify if a player is in range to interact with a game actor
 * in square
 *
 * @param ga game_actor_t *
 * @param gm game_t *
 * @return true if he is in range
 * @return false if he isn't in range
 */
bool ga_is_in_square(game_actor_t *ga, game_t *gm);

/**
 * @brief Handle event of games actor
 *
 * @param gm game_t *
 * @param event sfEvent
 */
void game_actor_list_event(game_t *gm, sfEvent event);

/**
 * @brief Clear a list of game actors without destroying the list
 *
 * @param ga game_actor_list_t *
 */
void game_actor_list_clear(game_actor_list_t *ga);

/**
 * @brief Anime game_actors
 *
 * @param gm game_t *gm
 */
void game_actor_list_anim(game_t *gm);

/**
 * @brief Clear all elements of a game_unit_list_t *
 *
 * @param list game_unit_list_t *
 */
void game_unit_list_clear(game_unit_list_t *list);

#endif /* GAME_ACTOR_H_ */
