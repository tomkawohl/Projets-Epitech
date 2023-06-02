/*
** EPITECH PROJECT, 2023
** include
** File description:
** test_area
*/

#ifndef TEST_AREA_H_
    #define TEST_AREA_H_

struct game_t;

/**
 * @brief Init test area
 *
 * @param gm game_t *
 */
void test_area_init(game_t *gm);

/**
 * @brief Run test area to test features
 *
 * @param gm game_t *
 */
void test_area_run(game_t *gm);

/**
 * @brief Draw test area elements
 *
 * @param gm game_t *
 */
void test_area_draw(game_t *gm);

/**
 * @brief Update test area data
 *
 * @param gm game_t *
 */
void test_area_update(game_t *gm);

/**
 * @brief Handle event of test area
 *
 * @param gm game_t *
 * @param event sfEvent
 */
void test_area_event(game_t *gm, sfEvent event);

/**
 * @brief A function to test interaction with game obj
 *
 * @param gm game_t *
 */
void sword_interact(game_t *gm);

/**
 * @brief Reset grid and game_actors list of gm (when init a new scene)
 *
 * @param gm game_t *
 */
void gm_reset_data(game_t *gm);

/**
 * @brief Init test room
 *
 * @param gm game_ *
 */
void test_room_init(game_t *gm);

/**
 * @brief Run test_room
 *
 * @param gm game_t *
 */
void test_room_run(game_t *gm);

/**
 * @brief Exit test_area to enter test_room
 *
 * @param gm game_t *
 */
void test_area_exit_interact(game_t *gm);

/**
 * @brief Destroy data of a map on a game_t *
 *
 * @param gm game_t *
 */
void gm_destroy_data(game_t *gm);

/**
 * @brief Handle interact with book in room
 *
 * @param gm game_t *
 */
void room_interact_book(game_t *gm);

/**
 * @brief Handle event for room
 *
 * @param gm game_t *
 */
void room_event(game_t *gm);

/**
 * @brief Handle interact to go to room2
 *
 * @param gm game_t *
 */
void room_interact_go_room2(game_t *gm);


/**
 * @brief Handle event for room 2
 *
 * @param gm game_t *
 */
void room2_event(game_t *gm);

/**
 * @brief Leave room2 to go to room
 *
 * @param gm game_t *
 */
void room2_interact_go_room(game_t *gm);

/**
 * @brief load
 *
 * @param gm load
 */
void load(game_t *gm);

#endif /* TEST_AREA_H_ */
