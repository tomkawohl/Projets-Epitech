/*
** EPITECH PROJECT, 2022
** tools/pencil
** File description:
** button_init
*/
#include "my_paint.h"

button_t *button_init(sfVector2f pos, sfVector2f size, sfColor color)
{
    button_t *button = malloc(sizeof(*button));

    button->font = NULL;
    button->text = NULL;
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setFillColor(button->rect, color);
    sfRectangleShape_setPosition(button->rect, pos);
    button->state = (button_state_t){false, false, false};
    button->color = color;
    button->is_active = true;
    button->display = true;
    button->hitbox = sfRectangleShape_getGlobalBounds(button->rect);
    button->pressed_left = NULL;
    button->hover = NULL;
    return (button);
}
