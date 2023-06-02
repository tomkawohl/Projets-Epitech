/*
** EPITECH PROJECT, 2023
** include
** File description:
** tile
*/

#ifndef TILE_H_
    #define TILE_H_
    #define TILE_SIZE 48
    typedef unsigned int u_int;
    #include <SFML/Graphics.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include "asset.h"

struct game_s;

enum tile_type {
    TILE_GROUND,
    TILE_WALL,
    TILE_DOOR
};

/**
 * @brief Date struct of a tile element
 *
 */
typedef struct tile_s {
    unsigned char set;
    sfVector2i asset;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    bool solid;
    bool is_end;
    void (*event)(struct game_s);
} tile_t;

typedef struct map_s {
    char *tiles;
} map_t;

typedef struct grid_s {
    tile_t **tiles;
    sfVector2f pos;
    sfVector2i limit;
} grid_t;

/**
 * @brief Create a generic tile 64x64
 *
 * @param pos Pos where the tile is
 * @return tile_t
 */
tile_t tile_create(sfVector2f pos);

/**
 * @brief Set a tile in a grid
 *
 * @param grid grid_t *grid concerned
 * @param info Has the int asset, coord of the asset. Look at the image of set
 * to find the asset you want, BASIC_SET ==1, 0,2 == grass for example
 * @param pos The pos in the grid, {0, 0} for example
 */
void tile_set(grid_t *grid, info_tile_t info, sfVector2i pos);

/**
 * @brief Destroy a tile
 *
 * @param tile tile_t *
 */
void tile_destroy(tile_t tile);

/**
 * @brief Create a grid allocated
 *
 * @param width The width of the grid desired
 * @param height The height of the grid desired
 * @param pos Where it should begin to add tile. It add by 64 x 64
 * Example : in the room in the middle of the screen, pos is the middle of
 * the screen
 * @return grid**
 */
grid_t *grid_create(unsigned int width, unsigned int height, sfVector2f pos);

/**
 * @brief Grid all tiles that have textures of a draw
 *
 * @param window sfRenderWindow *
 * @param grid tile_t *, for example tile_t *map
 */
void grid_draw(sfRenderWindow *window, tile_t **grid);

/**
 * @brief Destroy a grid
 *
 * @param grid tile_t *
 */
void grid_destroy(grid_t *grid);
#endif /* TILE_H_ */
