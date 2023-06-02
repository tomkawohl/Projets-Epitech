/*
** EPITECH PROJECT, 2023
** init
** File description:
** list_text_init
*/
/**
 * @file list_text_init.c
 *
 * @brief Init list_text for map_edit
 *
 * @date 15/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "text_list.h"

/*
typedef struct text_info_s {
    sfVector2i coord;
    char *text;
    u_int size;
    char *tile_asset;
    sfIntRect asset;
} text_info_t;
*/

text_list_t *map_edit_list_text_init(void)
{
    text_list_t *list = text_list_create();

    if (!list)
        return (NULL);
    text_list_add(list, (text_info_t){NULL, (sfVector2i){32, 1},
        " Mode : Default \n", 21, GUI_ASSET, (sfIntRect)TEXT_SQUARE, T_DEF});
    return (list);
}
