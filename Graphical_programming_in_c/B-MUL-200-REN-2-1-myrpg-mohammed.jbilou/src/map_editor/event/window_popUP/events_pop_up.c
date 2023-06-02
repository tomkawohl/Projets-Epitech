/*
** EPITECH PROJECT, 2023
** events_pop_up.c
** File description:
** events_pop_up
*/

#include "src.h"
#include "lib_will.h"
#include "parser.h"
#include "menu.h"

static pop_win_t check_open_win(pop_win_t win, sfVector2i mouse,
                            map_edit_t *edit)
{
    if (win.index == 2 && win.input)
        edit->file_to_open = msl_strcpy(win.input);
    if (mouse_over_rect(win.rects[2], mouse, win.wd)
        && win.index == 2 && can_close_open_window(edit)) {
        sfRenderWindow_close(win.wd);
        return win;
    }
    return win;
}

static pop_win_t check_input(pop_win_t win, sfEvent event, sfVector2i mouse,
                            map_edit_t *edit)
{
    static bool can_write = false;
    char *input = NULL;

    edit->file_to_open = NULL;
    can_write = get_click(win, mouse, can_write);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (win.input)
            input = msl_strcpy(win.input);
        if (mouse_over_rect(win.rects[2], mouse, win.wd) && win.index == 1) {
            map_editor_save_grid(edit, input);
            sfRenderWindow_close(win.wd);
            return win;
        }
        win = check_open_win(win, mouse, edit);
    }
    if (can_write == false)
        return win;
    win = text_handler(win, event);
    return win;
}

static pop_win_t check_mouse_clicked(pop_win_t m_wd, sfVector2i mouse,
                            sfEvent event, map_edit_t *map_edit)
{
    if (mouse_over_rect(m_wd.rects[1], mouse, m_wd.wd)) {
        map_edit->file_to_open = NULL;
        sfRenderWindow_close(m_wd.wd);
        return m_wd;
    }
    if (m_wd.index == 0 && mouse_over_rect(m_wd.rects[2], mouse, m_wd.wd)) {
        sfRenderWindow_close(m_wd.wd);
        new_grid(map_edit , m_wd.input);
    }
    return m_wd;
}

static void change_color_button(pop_win_t m_wd, sfVector2i mouse)
{
    sfColor color;

    for (size_t i = 0; i < m_wd.nb_buttons; i++) {
        if (mouse_over_rect(m_wd.rects[i], mouse, m_wd.wd)) {
            sfText_setColor(m_wd.text[i], sfRed);
        } else
            sfText_setColor(m_wd.text[i], sfWhite);
    }
}

pop_win_t events_pop_up(pop_win_t m_wd, sfEvent event, map_edit_t *map_edit)
{
    sfVector2i mouse;

    while (sfRenderWindow_pollEvent(m_wd.wd, &event)) {
        mouse = sfMouse_getPositionRenderWindow(m_wd.wd);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(m_wd.wd);
        if (event.type == sfEvtMouseMoved)
            change_color_button(m_wd, mouse);
        if (sfMouse_isButtonPressed(sfMouseLeft))
            check_mouse_clicked(m_wd, mouse, event, map_edit);
        m_wd = check_input(m_wd, event, mouse, map_edit);
    }
    return m_wd;
}
