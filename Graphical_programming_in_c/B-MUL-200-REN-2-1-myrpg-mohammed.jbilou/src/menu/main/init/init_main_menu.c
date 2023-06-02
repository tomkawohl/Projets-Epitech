/*
** EPITECH PROJECT, 2023
** init_main_menu.c
** File description:
** initits the menu with all the buttons
*/

#include "src.h"
#include "menu.h"
#include "parser.h"

void set_texture_rect(sfRectangleShape *rect, char const *path)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    sfRectangleShape_setTexture(rect, texture, sfTrue);
}

static void set_texture_main(menu_t *menu)
{
    for (size_t i = 0; i < NB_BUTTONS_START; i++){
        set_texture_rect(menu[i].rect[0], W_LARGE);
        set_texture_rect(menu[i].rect[1], R_LARGE);
    }
}

static void init_main_menu_parsed(parser_t *pr, menu_t *menu, sfFont *font)
{
    sfVector2f scale = {1, 1};

    for (size_t i = 0; i < NB_BUTTONS_START; i++) {
        menu[i].rect[0] = ssl_new_rect(pr[i].size, sfWhite, pr[i].pos_rect);
        menu[i].text[0] = ssl_new_text(font, scale, pr[i].pos_text, pr[i].name);
        menu[i].rect[1] = ssl_new_rect(pr[i].size, sfWhite, pr[i].pos_rect);
        menu[i].text[1] = ssl_new_text(font, scale, pr[i].pos_text, pr[i].name);
        sfText_setColor(menu[i].text[0], sfWhite);
        sfText_setColor(menu[i].text[1], sfRed);
    }
    set_texture_main(menu);
}

void init_main_menu(game_t *gm, menu_t *menu, sfFont *font)
{
    init_parser(gm, "save/menu.txt");
    for (size_t i = 0; i < NB_BUTTONS_START; i++) {
        menu[i].rect = malloc(sizeof(sfRectangleShape *) * 2);
        menu[i].text = malloc(sizeof(sfText *) * 2);
        menu[i].is_on_button = false;
    }
    init_main_menu_parsed(gm->pars, menu, font);
}
