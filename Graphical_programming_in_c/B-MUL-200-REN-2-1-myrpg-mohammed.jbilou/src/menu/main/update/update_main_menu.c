/*
** EPITECH PROJECT, 2023
** update_menu.c
** File description:
** updates the main menu
*/

#include "src.h"
#include "menu.h"

static void draw_menu_elements(game_t *gm)
{
    menu_t *menu = gm->start->menu;

    for (size_t i = 0; i < NB_BUTTONS_START; i++) {
        if (menu[i].is_on_button == false){
            sfRenderWindow_drawRectangleShape(gm->wd, menu[i].rect[0], NULL);
            sfRenderWindow_drawText(gm->wd, menu[i].text[0], NULL);
        } else {
            sfRenderWindow_drawRectangleShape(gm->wd, menu[i].rect[1], NULL);
            sfRenderWindow_drawText(gm->wd, menu[i].text[1], NULL);
        }
    }
}

void update_main_menu(game_t *gm)
{
    if (gm->scene != 0)
        return;
    draw_menu_elements(gm);
}
