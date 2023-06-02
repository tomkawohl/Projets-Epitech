/*
** EPITECH PROJECT, 2022
** tools/pencil
** File description:
** button_destroy
*/
#include "my_paint.h"

void button_destroy(button_t *button)
{
    if (!button)
        return;
    if (button->rect != NULL)
        sfRectangleShape_destroy(button->rect);
    if (button->text != NULL)
        sfText_destroy(button->text);
    if (button->font != NULL)
        sfFont_destroy(button->font);
    free(button);
}

void button_destroy_all(button_t **buttons)
{
    if (buttons == NULL)
        return;
    for (U_INT i = 0; buttons[i] != NULL; i++) {
        button_destroy(buttons[i]);
    }
    free(buttons);
}
