/*
** EPITECH PROJECT, 2023
** update_ig_menu.c
** File description:
** update_ig_menu
*/

#include "src.h"
#include "menu.h"

static void draw_ig_menu_elements(game_t *gm)
{
    in_game_menu_t *ig_menu = gm->ig_menu;

    for (size_t i = 0; i < NB_BUTTONS_IG_MENU; i++) {
        if (ig_menu[i].is_on_button == false) {
            sfRenderWindow_drawRectangleShape(gm->wd, ig_menu[i].rect[0], NULL);
            sfRenderWindow_drawText(gm->wd, ig_menu[i].text[0], NULL);
        } else {
            sfRenderWindow_drawRectangleShape(gm->wd, ig_menu[i].rect[1], NULL);
            sfRenderWindow_drawText(gm->wd, ig_menu[i].text[1], NULL);
        }
    }
}

void update_ig_menu(game_t *gm)
{
    draw_ig_menu_elements(gm);
}
