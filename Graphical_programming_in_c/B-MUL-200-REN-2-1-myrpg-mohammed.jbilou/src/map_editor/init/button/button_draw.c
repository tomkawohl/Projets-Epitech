/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** button/button_draw
*/
/**
 * @file button_draw.c
 *
 * @brief Draw a button for map edit
 *
 * @date 06/04/2023
*/
#include "src.h"
#include "lib_will.h"

static void draw_buttons_scene(sfRenderWindow *win,
button_edit_t *buttons, u_int i)
{
    if ( buttons[i].mouseOn == true) {
        if (buttons[i].rect != NULL)
            sfRenderWindow_drawRectangleShape(win, buttons[i].rect[1], NULL);
        if (buttons[i].text != NULL)
            sfRenderWindow_drawText(win, buttons[i].text[1], NULL);
    }
    if (buttons[i].mouseOn == false) {
        if (buttons[i].rect != NULL)
            sfRenderWindow_drawRectangleShape(win, buttons[i].rect[0], NULL);
        if (buttons[i].text != NULL)
            sfRenderWindow_drawText(win, buttons[i].text[0], NULL);
    }
}

void e_button_draw_all(sfRenderWindow *win, button_edit_t *buttons)
{
    for (u_int i = 0; i < NB_BUTTON_EDIT; i++)
        draw_buttons_scene(win, buttons, i);
}
