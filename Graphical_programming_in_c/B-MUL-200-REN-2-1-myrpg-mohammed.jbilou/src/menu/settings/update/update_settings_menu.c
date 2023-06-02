/*
** EPITECH PROJECT, 2023
** events_settings_menu.c
** File description:
** events_settings_menu
*/

#include "src.h"
#include "menu.h"

static void display_settings(game_t *gm, size_t i, settings_t *st)
{
    if (st[i].is_on_button == false && st[i].can_draw) {
        sfRenderWindow_drawRectangleShape(gm->wd, st[i].rect[0], NULL);
        if (st[i].text[0])
            sfRenderWindow_drawText(gm->wd, st[i].text[0], NULL);
    }
    if (st[i].is_on_button == true && st[i].can_draw) {
        sfRenderWindow_drawRectangleShape(gm->wd, st[i].rect[1], NULL);
        if (st[i].text[1])
            sfRenderWindow_drawText(gm->wd, st[i].text[1], NULL);
    }
}

static void update_settings_menu_elements(sfRenderWindow *wd, game_t *gm)
{
    settings_t *st = gm->start->settings;

    for (size_t i = 0; i < NB_BUTTONS_SETTINGS; i++)
        display_settings(gm, i, st);
    sfRenderWindow_drawCircleShape(gm->wd, gm->sound->music, NULL);
    sfRenderWindow_drawCircleShape(gm->wd, gm->sound->sound, NULL);
}

void update_settings_menu(game_t *gm)
{
    if (gm->scene != SETTINGS_SCENE)
        return;
    update_settings_menu_elements(gm->wd, gm);
}
