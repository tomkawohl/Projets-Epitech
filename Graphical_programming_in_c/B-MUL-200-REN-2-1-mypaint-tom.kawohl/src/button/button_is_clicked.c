/*
** EPITECH PROJECT, 2022
** tools/pencil
** File description:
** button_is_clicked
*/
#include "my_paint.h"

bool button_is_mouse_hover(button_t *button, sfMouseButtonEvent *mouse)
{
    if (sfFloatRect_contains((const sfFloatRect *)&(button->hitbox),
        (float)mouse->x, (float)mouse->y)) {
        return (true);
    }
    return (false);
}

bool button_is_mouse_hover_moved(button_t *button, sfMouseMoveEvent *mouse)
{
    if (sfFloatRect_contains((const sfFloatRect *)&(button->hitbox),
        (float)mouse->x, (float)mouse->y)) {
        return (true);
    }
    return (false);
}
