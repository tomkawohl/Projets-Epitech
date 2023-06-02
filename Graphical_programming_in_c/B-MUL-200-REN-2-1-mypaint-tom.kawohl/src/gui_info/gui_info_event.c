/*
** EPITECH PROJECT, 2022
** gui_info/
** File description:
** gui_info_event
*/
#include "my_paint.h"

bool check_down_hover(button_main_t *button, sfMouseMoveEvent *mouse)
{
    bool down_display = false;

    for (U_INT i = 0; button->down[i] != NULL; i++) {
        if (button_is_mouse_hover_moved(button->down[i], mouse)) {
            sfRectangleShape_setFillColor(button->down[i]->rect, TOP_HVR);
            down_display = true;
        } else {
            sfRectangleShape_setFillColor(button->down[i]->rect,
                button->down[i]->color);
        }
    }
    return (down_display);

}

void check_main_hover(button_main_t *button, sfMouseMoveEvent *mouse)
{
    bool down_display = true;

    if (button->main_activ == true) {
        if (button_is_mouse_hover_moved(button->main, mouse)) {
            sfRectangleShape_setFillColor(button->main->rect, TOP_HVR);
            button->down_display = true;
            button->down_activ = true;
        } else {
            sfRectangleShape_setFillColor(button->main->rect,
                button->main->color);
            down_display = false;
        }
    }
    if (button->down_display == true) {
        if (check_down_hover(button, mouse) == false
        && down_display == false) {
            button->down_display = false;
            button->down_activ = false;
        }
    }
}

void check_main_hover_right(button_main_t *button, sfMouseMoveEvent *mouse)
{
    bool down_display = true;

    if (button->down_display == true) {
        if (check_down_hover(button, mouse) == false
        && down_display == false) {
            button->down_display = false;
            button->down_activ = false;
        }
    }
}

void check_gui_hover(sfEvent event, paint_t *info)
{
    if (event.type != sfEvtMouseMoved)
        return;
    if (info->gui->topbar_activ == true) {
        for (U_INT i = 1; info->gui->topbar[i] != NULL; i++)
            check_main_hover(info->gui->topbar[i], &(event.mouseMove));
    }
    if (info->gui->rightbar_activ == true) {
        for (U_INT i = 1; info->gui->rightbar[i] != NULL; i++)
            check_main_hover_right(info->gui->rightbar[i],
                &(event.mouseMove));
    }
}

void gui_info_event(sfEvent event, paint_t *info)
{
    check_gui_hover(event, info);
    check_gui_click(event, info);
}
