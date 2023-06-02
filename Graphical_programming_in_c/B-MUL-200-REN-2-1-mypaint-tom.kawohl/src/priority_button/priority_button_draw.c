/*
** EPITECH PROJECT, 2022
** priority_button
** File description:
** priority_button_draw
*/
#include "my_paint.h"

void priority_button_draw(priority_button_t *prio, paint_t *info)
{
    priority_button_element_t *element = NULL;
    unsigned int i = 0;

    if (prio->first == NULL || prio->size == 0)
        return;
    element = prio->first;
    while (element && i < prio->size) {
        if (element->button->rect != NULL && element->button->display == true)
            sfRenderWindow_drawRectangleShape(info->window,
                element->button->rect, NULL);
        if (element->button->text != NULL && element->button->display == true)
            sfRenderWindow_drawText(info->window,
                element->button->text, NULL);
        element = element->next;
        i++;
    }
    return;
}
