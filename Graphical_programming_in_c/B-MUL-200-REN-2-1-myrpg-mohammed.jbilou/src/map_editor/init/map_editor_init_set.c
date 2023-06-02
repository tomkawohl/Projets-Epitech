/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** map_editor_init_set
*/
/**
 * @file map_editor_init_set.c
 *
 * @brief Init set of map editor
 *
 * @date 22/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "map_editor.h"

static void init_other_set(set_t *set)
{
    set[17].texture = sfTexture_createFromFile(ROOF, NULL);
    set[18].texture = sfTexture_createFromFile(OTHER_1, NULL);
}

set_t *map_editor_init_set(void)
{
    set_t *set = malloc(sizeof(*set) * NB_SET);
    set[0].texture = sfTexture_createFromFile(BASIC_SET, NULL);
    set[1].texture = sfTexture_createFromFile(HOUSE_SET_1, NULL);
    set[2].texture = sfTexture_createFromFile(HOUSE_SET_2, NULL);
    set[3].texture = sfTexture_createFromFile(HOUSE_SET_3, NULL);
    set[4].texture = sfTexture_createFromFile(HOUSE_SET_4, NULL);
    set[5].texture = sfTexture_createFromFile(HOUSE_SET_5, NULL);
    set[6].texture = sfTexture_createFromFile(HOUSE_SET_6, NULL);
    set[7].texture = sfTexture_createFromFile(HOUSE_SET_7, NULL);
    set[8].texture = sfTexture_createFromFile(HOUSE_SET_8, NULL);
    set[9].texture = sfTexture_createFromFile(FLOOR_1, NULL);
    set[10].texture = sfTexture_createFromFile(HOUSE_SET_9, NULL);
    set[11].texture = sfTexture_createFromFile(HOUSE_SET_10, NULL);
    set[12].texture = sfTexture_createFromFile(FOREST_SET_1, NULL);
    set[13].texture = sfTexture_createFromFile(FOREST_SET_2, NULL);
    set[14].texture = sfTexture_createFromFile(FOREST_SET_3, NULL);
    set[15].texture = sfTexture_createFromFile(FOREST_SET_4, NULL);
    set[16].texture = sfTexture_createFromFile(FOREST_SET_5, NULL);
    init_other_set(set);
    return (set);
}
