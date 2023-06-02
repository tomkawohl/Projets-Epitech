/*
** EPITECH PROJECT, 2023
** save_events.c
** File description:
** save_events
*/

#include "src.h"
#include "lib_will.h"
#include "parser.h"
#include "menu.h"

bool get_click(pop_win_t win, sfVector2i mouse, bool can_write)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)){
        if (mouse_over_rect(win.rects[0], mouse, win.wd))
            can_write = true;
        else
            can_write = false;
    }
    return can_write;
}

pop_win_t text_handler(pop_win_t win, sfEvent event)
{
    if (event.type != sfEvtTextEntered)
        return win;
    if (event.text.unicode != 8 && win.idx_text < 30) {
        win.input[win.idx_text] = event.text.unicode;
        if (win.idx_text + 1 < 30)
            win.input[win.idx_text + 1] = '\0';
        sfText_setString(win.text[0], win.input);
        win.idx_text++;
    }
    if (event.text.unicode == 8) {
        if (win.idx_text > 0) {
            win.idx_text--;
            win.input[win.idx_text] = '\0';
            sfText_setString(win.text[0], win.input);
        }
    }
    return win;
}
