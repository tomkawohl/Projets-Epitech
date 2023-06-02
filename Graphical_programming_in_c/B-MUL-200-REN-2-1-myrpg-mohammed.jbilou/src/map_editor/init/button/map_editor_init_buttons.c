/*
** EPITECH PROJECT, 2023
** init buttons map editor
** File description:
** map_editor_init_buttons
*/

#include "src.h"
#include "lib_will.h"

static void fill_button_editor(button_edit_t *buttons, char *name[],
sfVector2f start)
{
    sfColor grey = sfColor_fromRGB(144, 144, 144);
    buttons[0] = e_button_create(buttons[0], start,
    (sfVector2f){WIDTH, HEIGHT}, name[0]);
    buttons[1] = e_button_create(buttons[1], (sfVector2f){CANVA_X, CANVA_Y},
        (sfVector2f){C_SIZE_X, C_SIZE_Y}, name[1]);
    sfRectangleShape_setFillColor(buttons[0].rect[0], sfWhite);
    sfRectangleShape_setFillColor(buttons[0].rect[1], sfWhite);
    sfRectangleShape_setFillColor(buttons[0].rect[0], grey);
    sfRectangleShape_setFillColor(buttons[0].rect[1], grey);
    for (u_int i = 2; i < NB_BUTTON_EDIT; i++) {
        buttons[i] = e_button_create(buttons[i], start,
        (sfVector2f){125.0, 35.0}, name[i]);
        set_texture_rect(buttons[i].rect[0], W_LARGE);
        set_texture_rect(buttons[i].rect[1], R_LARGE);
        start.x += 125.0;
    }
}

button_edit_t *map_editor_button_init(void)
{
    button_edit_t *buttons = malloc(sizeof(*buttons) * NB_BUTTON_EDIT);
    sfVector2f start = {0, 0};
    char *name[NB_BUTTON_EDIT] = {NULL, NULL, "NEW", "SAVE", "OPEN", "ADD",
        "DELETE", "<-SET", "SET->"};

    if (!verify_malloc(buttons, "map_editor_button_init"))
        return (NULL);
    for (size_t j = 0; j < NB_BUTTON_EDIT; j++) {
        buttons[j].rect = malloc(sizeof(sfRectangleShape *) * 2);
        buttons[j].text = malloc(sizeof(sfText *) * 2);
        buttons[j].mouseOn = false;
    }
    fill_button_editor(buttons, name, start);
    return (buttons);
}
