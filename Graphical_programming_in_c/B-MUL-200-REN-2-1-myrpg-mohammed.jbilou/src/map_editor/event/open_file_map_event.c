/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** event/open_file_map_event.c
*/
/**
 * @file open_file_map_event.c
 *
 * @brief If ctrl o is pressed, can open a file
 *
 * @date 08/04/2023
*/
#include "src.h"
#include "lib_will.h"

grid_t *open_file_map(map_edit_t *map_edit)
{
    char *input = NULL;

    grid_t *grid = NULL;
    input = file_get_input(true);
    grid_destroy(map_edit->grid);
    grid = file_to_map(input, true);
    map_edit->state = DEFAULT;
    return (grid);
}

void open_file_map_event(map_edit_t *map_edit, sfEvent event, bool *can_press)
{
    if (sfKeyboard_isKeyPressed(sfKeyO)
        && sfKeyboard_isKeyPressed(sfKeyLControl) && *can_press) {
        map_edit->state = OPEN;
    }
}

void open_destroy_ressources(map_edit_t *map_edit)
{
    grid_destroy(map_edit->grid);
    game_unit_list_destroy(map_edit->units);
}
