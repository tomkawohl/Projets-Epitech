/*
** EPITECH PROJECT, 2023
** tile
** File description:
** tile_destroy
*/
/**
 * @file tile_destroy.c
 *
 * @brief Destroy a tile
 *
 * @date 05/04/2023
*/
#include "tile.h"
#include "lib_will.h"

void tile_destroy(tile_t tile)
{
    if (tile.texture != NULL) {
        sfTexture_destroy(tile.texture);
        tile.texture = NULL;
    }
    if (tile.sprite != NULL) {
        sfSprite_destroy(tile.sprite);
        tile.sprite = NULL;
    }
    return;
}
