/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** event/new_grid_event.c
*/
/**
 * @file new_grid_event.c
 *
 * @brief Create a new grid
 *
 * @date 10/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "parser.h"

/*
char *file_get_input(bool is_open_event)
{
    char *input = NULL;
    size_t len = 0;

    w_printf("Enter file name :\n");
    while (!file_is_input_valid(input, is_open_event)) {
        getline(&input, &len, stdin);
        input[str_len(input) - 1] = '\0';
        if (!file_is_input_valid(input, is_open_event)) {
            w_printf("File name incorect, exepected : .map\n");
        }
    }
    return (input);
}
*/

static bool is_input_correct(char *input)
{
    u_int i = 0;

    if (!input)
        return (false);
    if (my_atoi(&input[i]) == 0)
        return (false);
    while (input[i] != '\0' && input[i] != ':')
        i++;
    if (input[i] != ':')
        return (false);
    if (input[i++] == '\0')
        return (false);
    if (my_atoi(&input[i]) == 0)
        return (false);
    return (true);
}

char *get_input_grid_size(void)
{
    char *input = NULL;
    size_t len = 0;

    w_printf("Enter grid dimension : type\t");
    w_printf("\"with(number) : height(number)\n");
    while (!is_input_correct(input)) {
        getline(&input, &len, stdin);
        input[str_len(input) - 1] = '\0';
        if (!is_input_correct(input)) {
            w_printf("Dimension incorrect : type\t");
            w_printf("\"with(number) : height(number)\n");
        }
    }
    return (input);
}

void new_grid(map_edit_t *map_edit, char *input)
{
    u_int width = 0;
    u_int height = 0;
    u_int i = 0;

    grid_destroy(map_edit->grid);
    destroy_tile_pos_set(map_edit->tiles_pos_set, map_edit->grid->limit);
    width = my_atoi(&input[i]);
    while (input[i] != '\0' && input[i] != ':')
        i++;
    height = my_atoi(&input[i + 1]);
    map_edit->grid = grid_create(width, height, (sfVector2f){CANVA_X, CANVA_Y});
    sfRectangleShape_setSize(map_edit->buttons[1].rect[0],
        (sfVector2f){width * TILE_SIZE, height * TILE_SIZE});
        map_edit->tiles_pos_set = tile_pos_set_init(map_edit->grid->limit);
    return;
}

void new_grid_event(map_edit_t *map_edit, bool *can_press)
{
    return;
}
