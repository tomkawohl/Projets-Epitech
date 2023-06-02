/*
** EPITECH PROJECT, 2023
** create_pop_up.c
** File description:
** create_pop_up
*/

#include "src.h"
#include "lib_will.h"
#include "parser.h"
#include "menu.h"

static void init_buttons(parser_t *pars, pop_win_t m_wd, sfFont *font)
{
    for (size_t i = 0; i < m_wd.nb_buttons; i++) {
        m_wd.rects[i] = ssl_new_rect(pars[i].size, sfWhite, pars[i].pos_rect);
        set_texture_rect(m_wd.rects[i], W_LARGE);
        m_wd.text[i] = ssl_new_text(font, (sfVector2f){1, 1}, pars[i].pos_text,
        pars[i].name);
        sfText_setColor(m_wd.text[i], sfWhite);
    }
}

static void init_elements_window(pop_win_t m_wd, game_t *gm, char const *path)
{
    if (gm->pars)
        free(gm->pars);
    init_parser(gm,  path);
    init_buttons(gm->pars, m_wd, gm->font);
}

void create_new_window(game_t *gm, pop_win_t m_wd, char const *filepath,
                        map_edit_t *map_edit)
{
    init_elements_window(m_wd, gm, filepath);
    sfEvent event;

    sfRenderWindow_setPosition(m_wd.wd, (sfVector2i){WIDTH - 1300, 200});
    while (sfRenderWindow_isOpen(m_wd.wd)) {
        m_wd = events_pop_up(m_wd, event, map_edit);
        sfRenderWindow_clear(m_wd.wd, sfWhite);
        update_buttons_window(m_wd);
        sfRenderWindow_display(m_wd.wd);
    }
    sfRenderWindow_destroy(m_wd.wd);
}

pop_win_t init_info_pop_win(pop_win_t m_wd , char const *name,
                            size_t nb_buttons, sfVector2u size)
{
    sfVideoMode mode = {size.x, size.y, 32};

    m_wd.nb_buttons = nb_buttons;
    m_wd.rects = malloc(sizeof(sfRectangleShape *) * m_wd.nb_buttons);
    m_wd.text = malloc(sizeof(sfText *) * m_wd.nb_buttons);
    m_wd.input = malloc(sizeof(char) * 100);
    memset(m_wd.input, '\0', 100);
    m_wd.wd = sfRenderWindow_create(mode, name, sfClose, NULL);
    m_wd.idx_text = 0;
    return m_wd;
}
