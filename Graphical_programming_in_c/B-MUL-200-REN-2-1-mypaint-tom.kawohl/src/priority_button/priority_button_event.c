/*
** EPITECH PROJECT, 2022
** priority_button
** File description:
** priority_button_event
*/
#include "my_paint.h"

void check_prio_hover(paint_t *info, sfEvent event)
{
    priority_button_element_t *elem = NULL;
    if (event.type != sfEvtMouseMoved)
        return;
    if (info->gui->prio->first == NULL)
        return;
    elem = info->gui->prio->first;
    while (elem) {
        if (button_is_mouse_hover_moved(elem->button, &(event.mouseMove))
            && elem->button->is_active) {
            sfRectangleShape_setFillColor(elem->button->rect, TOP_HVR);
        } else {
            sfRectangleShape_setFillColor(elem->button->rect,
                elem->button->color);
        }
        elem = elem->next;
    }
    return;
}

void do_click_prio(button_t *button, paint_t *info)
{
    if (button->pressed_left != NULL)
        button->pressed_left(info);
    return;
}

void check_prio_click(paint_t *info, sfEvent event)
{
    priority_button_element_t *elem = NULL;
    if (event.type != sfEvtMouseButtonPressed)
        return;
    if (info->gui->prio->first == NULL)
        return;
    elem = info->gui->prio->first;
    while (elem) {
        if (button_is_mouse_hover(elem->button, &(event.mouseButton))
        && elem->button->is_active == true) {
            do_click_prio(elem->button, info);
            return;
        }
        elem = elem->next;
    }
    return;
}

void priority_button_event(sfEvent event, paint_t *info)
{
    check_prio_hover(info, event);
    check_prio_click(info, event);
    return;
}
