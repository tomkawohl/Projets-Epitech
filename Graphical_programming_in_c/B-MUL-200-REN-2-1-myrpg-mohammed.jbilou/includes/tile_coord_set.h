/*
** EPITECH PROJECT, 2023
** include
** File description:
** tile_coord_set.h
*/

#ifndef TILE_COORD_SET_H_
    #define TILE_COORD_SET_H_

typedef struct tile_coord_set_element_s {
    unsigned int nb_set;
    unsigned int x;
    unsigned int y;
    struct tile_coord_set_element_s *next;
} tile_coord_set_element_t;

typedef struct tile_coord_set_s {
    tile_coord_set_element_t *first;
    unsigned int size;
} tile_coord_set_t;

typedef struct grid_tile_coord_set_s {
    tile_coord_set_t **tile_coord;
} grid_tile_coord_set_t;

/**
 * @brief Create a list of tile_coord_set_element_t
 *
 * @return tile_coord_set_t *
 */
tile_coord_set_t *tile_coord_set_create(void);

/**
 * @brief Add an element tile_coord_set_element_t to a list
 *
 * @param list tile_coord_set_t *
 * @param x pos x of the tile in the set
 * @param y pos y of the tile in the set
 * @param nb_set the set concerning, example : BASIC_SET
 */
void tile_coord_set_add(tile_coord_set_t *list, u_int x, u_int y,
    u_int nb_set);

/**
 * @brief Remove an element of list tile_coord_set_t *
 *
 * @param list tile_coord_set_t *
 */
void tile_coord_set_remove(tile_coord_set_t *list);

/**
 * @brief Destroy a list tile_coord_set_t
 *
 * @param list tile_coord_set_t *
 */
void tile_coord_set_destroy(tile_coord_set_t *list);

/**
 * @brief Init a grid_tile_coord struct
 *
 * @param limit of grid
 * @return grid_tile_coord_set_t *
 */
grid_tile_coord_set_t *grid_tile_coord_set_init(sfVector2i limit);

#endif /* TILE_COORD_SET_H_ */
