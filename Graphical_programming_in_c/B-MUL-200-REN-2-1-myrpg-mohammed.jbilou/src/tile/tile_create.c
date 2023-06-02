/*
** EPITECH PROJECT, 2023
** tile
** File description:
** tile_create
*/
/**
 * @file tile_create.c
 *
 * @brief Create a tile
 *
 * @date 05/04/2023
*/
#include "tile.h"
#include "lib_will.h"

/*
tile_t *tile_init(sfVector2f pos, char *ressource, sfIntRect asset,
    int type)
{
    tile_t *tile = malloc(sizeof(*tile));

    if (!verify_malloc(tile, "tile_create"))
        return (NULL);
    tile->texture = sfTexture_createFromFile(ressource, &asset);
    tile->sprite = sfSprite_create();
    tile->position = pos;
    tile->type = type;
    if (tile->type == 0)
        tile->solid = false;
    else
        tile->solid = true;
    sfSprite_setTexture(tile->sprite, tile->texture, sfFalse);
    sfSprite_setPosition(tile->sprite, tile->position);
    if (asset.width == 32)
        sfSprite_setScale(tile->sprite, (sfVector2f){2, 2});
    return (tile);
}
*/


tile_t tile_create(sfVector2f pos)
{
    tile_t tile = {0};

    tile.texture = NULL;
    tile.sprite = NULL;
    tile.position = pos;
    tile.solid = false;
    tile.is_end = false;
    tile.event = NULL;
    tile.set = 0;
    tile.asset = (sfVector2i){0, 0};
    return (tile);
}
