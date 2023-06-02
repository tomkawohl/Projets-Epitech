/*
** EPITECH PROJECT, 2022
** tools/pencil
** File description:
** topbar_init
*/
#include "my_paint.h"

button_t **help_btn_init(void)
{
    button_t **buttons = NULL;
    U_INT nb_buttons = 2;
    sfVector2f pos = {200, TOPBAR_HEIGHT_BTN};

    buttons = malloc(sizeof(*buttons) * (nb_buttons + 1));
    buttons[nb_buttons] = NULL;
    for (U_INT i = 0; i < nb_buttons; i++) {
        buttons[i] = button_init(pos, (sfVector2f){100.0, TOPBAR_HEIGHT_BTN},
        TOP_BG);
        pos.y += TOPBAR_HEIGHT_BTN;
    }
    button_set_text(buttons[0], "About", FONT_SIZE, FONT_BASIC);
    button_set_text(buttons[1], "Help", FONT_SIZE, FONT_BASIC);
    buttons[1]->pressed_left = help_press_left;
    return (buttons);
}

button_t **edit_btn_init(void)
{
    button_t **buttons = NULL;
    U_INT nb_buttons = 2;
    sfVector2f pos = {100, TOPBAR_HEIGHT_BTN};

    buttons = malloc(sizeof(*buttons) * (nb_buttons + 1));
    buttons[nb_buttons] = NULL;
    for (U_INT i = 0; i < nb_buttons; i++) {
        buttons[i] = button_init(pos, (sfVector2f){100.0, TOPBAR_HEIGHT},
        TOP_BG);
        pos.y += TOPBAR_HEIGHT;
    }
    button_set_text(buttons[0], "Pencil", FONT_SIZE, FONT_BASIC);
    buttons[0]->pressed_left = pencil_btn_press_left;
    button_set_text(buttons[1], "Eraser", FONT_SIZE, FONT_BASIC);
    buttons[1]->pressed_left = eraser_btn_press_left;
    return (buttons);
}

button_t **file_btn_init(void)
{
    button_t **buttons = NULL;
    U_INT nb_buttons = 3;
    sfVector2f pos = {0, TOPBAR_HEIGHT_BTN};

    buttons = malloc(sizeof(*buttons) * (nb_buttons + 1));
    if (!buttons)
        return (NULL);
    buttons[nb_buttons] = NULL;
    for (U_INT i = 0; i < nb_buttons; i++) {
        buttons[i] = button_init(pos, (sfVector2f){100.0, TOPBAR_HEIGHT},
        TOP_BG);
        pos.y += TOPBAR_HEIGHT;
    }
    button_set_text(buttons[0], "New file", FONT_SIZE, FONT_BASIC);
    buttons[0]->pressed_left = new_file_press_left;
    button_set_text(buttons[1], "Open file", FONT_SIZE, FONT_BASIC);
    buttons[1]->pressed_left = open_file;
    button_set_text(buttons[2], "Save file", FONT_SIZE, FONT_BASIC);
    buttons[2]->pressed_left = save_file;
    return (buttons);
}

button_t **topbar_init(void)
{
    button_t **buttons = NULL;
    sfVector2f pos = {0.0, 0.0};
    U_INT nb_buttons = 4;

    buttons = malloc(sizeof(*buttons) * (nb_buttons + 1));
    if (!buttons)
        return (NULL);
    buttons[nb_buttons] = NULL;
    buttons[0] = button_init((sfVector2f){300.0, 0.0}, (sfVector2f){WIDTH,
        TOPBAR_HEIGHT_BTN}, TOP_BG);
    buttons[0]->is_active = false;
    for (U_INT i = 1; i < nb_buttons; i++) {
        buttons[i] = button_init(pos, (sfVector2f){100.0, TOPBAR_HEIGHT_BTN},
            TOP_BG);
        pos.x += 100.0;
    }
    button_set_text(buttons[1], "File", FONT_SIZE, FONT_BASIC);
    button_set_text(buttons[2], "Edit", FONT_SIZE, FONT_BASIC);
    button_set_text(buttons[3], "Help", FONT_SIZE, FONT_BASIC);
    return (buttons);
}
