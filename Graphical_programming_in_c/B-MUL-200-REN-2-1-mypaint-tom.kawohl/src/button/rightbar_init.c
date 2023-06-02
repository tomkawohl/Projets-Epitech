/*
** EPITECH PROJECT, 2022
** button
** File description:
** rightbar_init
*/
#include "my_paint.h"

void set_button_rightbar(button_t  **buttons)
{
    button_set_text(buttons[0], "Size 1", FONT_SIZE, FONT_BASIC);
    buttons[0]->pressed_left = click_size1;
    button_set_text(buttons[1], "Size 2", FONT_SIZE, FONT_BASIC);
    buttons[1]->pressed_left = click_size2;
    button_set_text(buttons[2], "Size 3", FONT_SIZE, FONT_BASIC);
    buttons[2]->pressed_left = click_size3;
    button_set_text(buttons[3], "Circle Brush", FONT_SIZE, FONT_BASIC);
    buttons[3]->pressed_left = click_circle_form;
    button_set_text(buttons[4], "Rectangle Brush", FONT_SIZE, FONT_BASIC);
    buttons[4]->pressed_left = click_square_form;
}

button_t **init_pencil_setting(void)
{
    button_t **buttons = NULL;
    U_INT nb_buttons = 5;
    sfVector2f pos = {WIDTH - (RIGHT_WIDTH / 2) - 100.0 ,
        TOPBAR_HEIGHT_BTN * 2};
    buttons = malloc(sizeof(*buttons) * (nb_buttons + 1));
    buttons[nb_buttons] = NULL;
    for (U_INT i = 0; i < nb_buttons; i++) {
        buttons[i] = button_init(pos, (sfVector2f){200.0, TOPBAR_HEIGHT_BTN},
        TOP_BG);
        pos.y += TOPBAR_HEIGHT_BTN + 20.0;
    }
    set_button_rightbar(buttons);
    return (buttons);
}

void set_button(button_t **buttons)
{
    button_set_text(buttons[0], "Size 1", FONT_SIZE, FONT_BASIC);
    buttons[0]->pressed_left = click_size1;
    button_set_text(buttons[1], "Size 2", FONT_SIZE, FONT_BASIC);
    buttons[1]->pressed_left = click_size2;
    button_set_text(buttons[2], "Size 3", FONT_SIZE, FONT_BASIC);
    buttons[2]->pressed_left = click_size3;
    button_set_text(buttons[3], "Circle Brush", FONT_SIZE, FONT_BASIC);
    buttons[3]->pressed_left = click_circle_form;
    button_set_text(buttons[4], "Rectangle Brush", FONT_SIZE, FONT_BASIC);
    buttons[4]->pressed_left = click_square_form;
}

button_t **init_eraser_setting(void)
{
    button_t **buttons = NULL;
    U_INT nb_buttons = 5;
    sfVector2f pos = {WIDTH - (RIGHT_WIDTH / 2) - 100.0 ,
        TOPBAR_HEIGHT_BTN * 2};

    buttons = malloc(sizeof(*buttons) * (nb_buttons + 1));
    buttons[nb_buttons] = NULL;
    for (U_INT i = 0; i < nb_buttons; i++) {
        buttons[i] = button_init(pos, (sfVector2f){200.0, TOPBAR_HEIGHT_BTN},
        TOP_BG);
        pos.y += TOPBAR_HEIGHT_BTN + 20.0;
    }
    set_button(buttons);
    return (buttons);
}
