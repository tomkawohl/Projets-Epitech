/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** event/save_grid_event.c
*/
/**
 * @file save_grid_event.c
 *
 * @brief If ctrl s is pressed, save grid
 *
 * @date 07/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include <math.h>

bool file_is_input_valid(char *input, bool is_open_event)
{
    if (!input)
        return (false);
    for (u_int i = 0; input[i] != '\0'; i++) {
        if (!char_is_alpha(input[i]) && !char_is_num(input[i]) &&
            is_open_event == false)
            return (false);
    }
    if (is_open_event) {
        if (!str_find(input, ".txt"))
            return (false);
    }
    return (true);
}

char *file_get_input(bool is_open_event)
{
    char *input = NULL;
    size_t len = 0;

    w_printf("Enter file name :\n");
    while (!file_is_input_valid(input, is_open_event)) {
        getline(&input, &len, stdin);
        input[str_len(input) - 1] = '\0';
        if (!file_is_input_valid(input, is_open_event)) {
            w_printf("File name incorect, exepected : .txt\n");
        }
    }
    return (input);
}

void save_grid_event(map_edit_t *map_edit, sfEvent event, bool *can_press)
{
    char *input = NULL;

    if (sfKeyboard_isKeyPressed(sfKeyS) &&
        sfKeyboard_isKeyPressed(sfKeyLControl) && *can_press) {
        input = file_get_input(false);
        map_editor_save_grid(map_edit, input);
    }
}
