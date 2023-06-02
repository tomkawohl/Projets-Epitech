/*
** EPITECH PROJECT, 2023
** tile
** File description:
** tile_set
*/
/**
 * @file tile_set.c
 *
 * @brief Set a tile
 *
 * @date 10/04/2023
*/
#include "tile.h"
#include "lib_will.h"

static void update_texture(sfImage *image, const sfUint8 *pixels,
    sfVector2i index, sfTexture *texture)
{
    if (sfImage_getPixel(image, index.x, index.y).a == 0)
        return;
    sfTexture_updateFromPixels(texture,
        &pixels[(index.y * TILE_SIZE + index.x) * 4], 1, 1, index.x, index.y);
}

static void add_texture(grid_t *grid, sfVector2i pos, info_tile_t info)
{
    SET_ALL;
    sfIntRect area = {info.coord.x * 48, info.coord.y * 48, 48, 48};
    sfTexture *to_add = sfTexture_createFromFile(set[info.set], &(area));
    sfImage *image = sfTexture_copyToImage(to_add);
    const sfUint8 *pixels = sfImage_getPixelsPtr(image);

    for (u_int y = 0; y < TILE_SIZE; y++) {
        for (u_int x = 0; x < TILE_SIZE; x++) {
            update_texture(image, pixels, (sfVector2i){x, y},
                grid->tiles[pos.x][pos.y].texture);
        }
    }
    sfSprite_setTexture(grid->tiles[pos.x][pos.y].sprite,
        grid->tiles[pos.x][pos.y].texture, sfFalse);
    sfTexture_destroy(to_add);
    sfImage_destroy(image);
}

static void update_set(grid_t *grid, sfVector2i pos, info_tile_t info)
{
    sfIntRect area = {info.coord.x * 48, info.coord.y * 48, 48, 48};

    SET_ALL;
    if (grid->tiles[pos.x][pos.y].texture != NULL) {
        add_texture(grid, pos, info);
    } else {
        grid->tiles[pos.x][pos.y].texture =
            sfTexture_createFromFile(set[info.set], &(area));
    }
}

void tile_set(grid_t *grid, info_tile_t info, sfVector2i pos)
{
    if (!grid)
        return;
    if (pos.y > grid->limit.x - 1 || pos.x > grid->limit.y - 1)
        return;
    if (pos.x < 0 || pos.y < 0)
        return;
    update_set(grid, pos, info);
    grid->tiles[pos.x][pos.y].sprite = sfSprite_create();
    sfSprite_setTexture(grid->tiles[pos.x][pos.y].sprite,
        grid->tiles[pos.x][pos.y].texture, sfFalse);
    sfSprite_setPosition(grid->tiles[pos.x][pos.y].sprite,
        grid->tiles[pos.x][pos.y].position);
    grid->tiles[pos.x][pos.y].asset = info.coord;
    grid->tiles[pos.x][pos.y].set = info.set;
    return;
}
