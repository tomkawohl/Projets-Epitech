/*
** EPITECH PROJECT, 2023
** update_pop_up.c
** File description:
** update_pop_up
*/

#include "src.h"
#include "lib_will.h"
#include "parser.h"
#include "menu.h"

bool can_close_open_window(map_edit_t *edit)
{
    struct stat info;

    if (edit->file_to_open == NULL)
        return false;
    if (stat(edit->file_to_open , &info) < 0){
        edit->file_to_open = NULL;
        return false;
    }
    return true;
}

void update_buttons_window(pop_win_t m_wd)
{
    for (size_t i = 0; i < m_wd.nb_buttons; i++) {
        sfRenderWindow_drawRectangleShape(m_wd.wd, m_wd.rects[i], NULL);
        sfRenderWindow_drawText(m_wd.wd, m_wd.text[i], NULL);
    }
}
