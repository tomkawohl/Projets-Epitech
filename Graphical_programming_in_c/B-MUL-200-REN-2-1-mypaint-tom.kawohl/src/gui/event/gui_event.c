/*
** EPITECH PROJECT, 2023
** src/gui/gui_top_init
** File description:
** handles the gui events
*/

#include "my_paint.h"
/*
void show_dropdown(dropdown_btn_t btn, sfRenderWindow *window)
{
    // for (int i = 0; i < btn.options_len; i++) {
    //     sfRenderWindow_drawRectangleShape(window, btn.options[i].rect, NULL);
    //     sfRenderWindow_drawText(window, btn.options[i].text, NULL);
    // }
}

void gui_event_cut1(sfEvent event, paint_t *info, int i)
{
    perimiter_t *perim;

    perim = info->gui.topbar->dropdown_btn[i].main_btn.perim;
    if (get_is_in_perimiter(event.mouseMove.y,
        event.mouseMove.x, perim, 0) == true) {
        set_hover(info->gui.topbar->dropdown_btn[i].main_btn);
    } else
        set_none(info->gui.topbar->dropdown_btn[i].main_btn);
    if (get_is_in_perimiter(sfMouse_getPositionRenderWindow(info->window).
        y, sfMouse_getPositionRenderWindow(info->window).x, perim, 0) ==
        true && event.type == sfEvtMouseButtonPressed) {
        set_inactive_all(info->gui.topbar->dropdown_btn);
        info->gui.topbar->dropdown_btn[i].main_btn.active = true;
    }
    if (info->gui.topbar->dropdown_btn[i].main_btn.active == true)
        set_active(info->gui.topbar->dropdown_btn[i], info->window);
}

void gui_event(sfEvent event, paint_t *info)
{
    if (event.type == sfEvtMouseMoved && event.mouseMove.y > 200) {
        set_inactive_all(info->gui.topbar->dropdown_btn);
        return;
    }
    for (int i = 0; i < TOPBTN_LEN; i++) {
        gui_event_cut1(event, info, i);
    }
}
*/
