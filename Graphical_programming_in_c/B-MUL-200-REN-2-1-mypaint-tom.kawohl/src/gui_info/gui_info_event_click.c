/*
** EPITECH PROJECT, 2022
** gui_info/
** File description:
** gui_info_event_cick
*/
#include "my_paint.h"



/*
void check_main_hover(button_main_t *button, paint_t *info,
    sfMouseMoveEvent *mouse)
{
    bool down_display = true;

    if (button->main_activ == true) {
        if(button_is_mouse_hover_moved(button->main, mouse)) {
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
        if (check_down_hover(button, info, mouse) == false
        && down_display == false) {
            button->down_display = false;
            button->down_activ = false;
        }
    }
}
*/
/*
bool check_down_hover(button_main_t *button, paint_t *info,
    sfMouseMoveEvent *mouse)
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
*/

void do_click(button_t *button, paint_t *info)
{
    if (button->is_active == true && button->pressed_left != NULL)
        button->pressed_left(info);
    return;
}

void check_main_click(button_main_t *button, paint_t *info,
    sfMouseButtonEvent *mouse)
{
    if (button->down_activ != true)
        return;
    for (U_INT i = 0; button->down[i] != NULL; i++) {
        if (button_is_mouse_hover(button->down[i], mouse)) {
            do_click(button->down[i], info);
            return;
        }
    }
}

void check_gui_click(sfEvent event, paint_t *info)
{
    if (event.type != sfEvtMouseButtonPressed)
        return;
    if (info->gui->topbar_activ == true) {
        for (U_INT i = 1; info->gui->topbar[i] != NULL; i++)
            check_main_click(info->gui->topbar[i], info,
                &(event.mouseButton));
    }
    if (info->gui->topbar_activ == true) {
        for (U_INT i = 1; info->gui->rightbar[i] != NULL; i++)
            check_main_click(info->gui->rightbar[i], info,
                &(event.mouseButton));
    }
}
