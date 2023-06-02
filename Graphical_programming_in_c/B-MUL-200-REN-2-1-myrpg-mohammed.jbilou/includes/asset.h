/*
** EPITECH PROJECT, 2023
** include
** File description:
** asset.h
*/

#ifndef ASSET_H_
    #define ASSET_H_

    #define BASIC_SET "util/ASSETS/basic_tiles/b_tileset.png"
    #define HOUSE_SET_1 "util/ASSETS/MAP/House/house_assets_v1.png"
    #define HOUSE_SET_2 "util/ASSETS/MAP/House/house_assets_v2.png"
    #define HOUSE_SET_3 "util/ASSETS/MAP/House/house_assets_v3.png"
    #define HOUSE_SET_4 "util/ASSETS/MAP/House/house_assets_v4.png"
    #define HOUSE_SET_5 "util/ASSETS/MAP/House/house_assets_v5.png"
    #define HOUSE_SET_6 "util/ASSETS/MAP/House/house_assets_v6.png"
    #define HOUSE_SET_7 "util/ASSETS/MAP/House/house_assets_v7.png"
    #define HOUSE_SET_8 "util/ASSETS/MAP/House/house_assets_v8.png"
    #define HOUSE_SET_9 "util/ASSETS/MAP/House/house_assets_v9.png"
    #define HOUSE_SET_10 "util/ASSETS/MAP/House/house_assets_v10.png"
    #define FOREST_SET_1 "util/ASSETS/MAP/forest/Forest_assets_v1.png"
    #define FOREST_SET_2 "util/ASSETS/MAP/forest/Forest_assets_v2.png"
    #define FOREST_SET_3 "util/ASSETS/MAP/forest/Forest_assets_v3.png"
    #define FOREST_SET_4 "util/ASSETS/MAP/forest/Forest_assets_v4.png"
    #define FOREST_SET_5 "util/ASSETS/MAP/forest/Forest_assets_v5.png"
    #define ROOF "util/ASSETS/MAP/Other/roof.png"
    #define OTHER_1 "util/ASSETS/MAP/Other/Other_assets_v1.png"

    #define FLOOR_1 "util/ASSETS/MAP/Other/Floor_assets_v1.png"
    #define WATER_FIRE "util/ASSETS/MAP/Other/water_and_fire.png"
    #define BOOKS "util/ASSETS/MAP/Other/books.png"
    #define CHEST "util/ASSETS/MAP/Other/chest.png"
    #define CHARS_1 "util/ASSETS/Character_assets/characters_1.png"
    #define CHARS_2 "util/ASSETS/Character_assets/characters_2.png"
    #define MINOTAURE "util/ASSETS/Character_assets/minotaur_assets.png"
    #define SET_ALL char *set[] = {BASIC_SET, HOUSE_SET_1, HOUSE_SET_2,\
        HOUSE_SET_3, HOUSE_SET_4, HOUSE_SET_5, HOUSE_SET_6, HOUSE_SET_7,\
        HOUSE_SET_8, FLOOR_1, HOUSE_SET_9, HOUSE_SET_10, FOREST_SET_1,\
        FOREST_SET_2, FOREST_SET_3, FOREST_SET_4, FOREST_SET_5, ROOF, OTHER_1}
    #include <SFML/Graphics.h>

typedef struct info_tile_s {
    int set;
    sfVector2i coord;
} info_tile_t;

#endif /* ASSET_H_ */
