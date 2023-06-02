/*
** EPITECH PROJECT, 2023
** init_ig_menu
** File description:
** init the in game menu
*/

#include "src.h"
#include "menu.h"
#include "parser.h"
#include "src_struct.h"

static void set_texture_ig_menu(in_game_menu_t *ig_menu)
{
    for (size_t i = 0; i < NB_BUTTONS_IG_MENU; i++) {
        set_texture_rect(ig_menu[i].rect[0], W_LARGE);
        set_texture_rect(ig_menu[i].rect[1], R_LARGE);
    }
}

static void init_main_ig_menu(parser_t *pr, in_game_menu_t *ig_menu,
sfFont *font)
{
    sfVector2f scale = {1, 1};

    for (size_t i = 0; i < NB_BUTTONS_IG_MENU; i++) {
        ig_menu[i].rect[0] = ssl_new_rect(pr[i].size, sfWhite, pr[i].pos_rect);
        ig_menu[i].text[0] = ssl_new_text(font,scale,
        pr[i].pos_text, pr[i].name);
        ig_menu[i].rect[1] = ssl_new_rect(pr[i].size, sfWhite, pr[i].pos_rect);
        ig_menu[i].text[1] = ssl_new_text(font, scale,
        pr[i].pos_text, pr[i].name);
        sfText_setColor(ig_menu[i].text[0], sfWhite);
        sfText_setColor(ig_menu[i].text[1], sfRed);
    }
    set_texture_ig_menu(ig_menu);
}

static  bool check_buttons_menu(game_t *gm)
{
    switch (events_ig_menu(gm)) {
        case (0):
            gm->scene = MAIN_MENU_SCENE;
            return false;
        case (1):
            return false;
        case (2):
            return false;
    }
    return true;
}

static void init_elements_ig_menu(game_t *gm)
{
    if (gm->pars)
        free(gm->pars);
    init_parser(gm, "save/in_game.txt");
    sfView_setCenter(gm->view, (sfVector2f){WIDTH / 2, HEIGHT / 2});
    sfRenderWindow_setView(gm->wd, gm->view);
    for (size_t i = 0; i < NB_BUTTONS_IG_MENU; i++) {
        gm->ig_menu[i].rect = malloc(sizeof(sfRectangleShape *) * 2);
        gm->ig_menu[i].text = malloc(sizeof(sfText *) * 2);
        gm->ig_menu[i].is_on_button = false;
    }
}

bool init_ig_menu(game_t *gm, sfFont *font)
{
    init_elements_ig_menu(gm);
    gm->scene = IN_GAME_SCENE;
    init_main_ig_menu(gm->pars, gm->ig_menu, font);
    while (sfRenderWindow_isOpen(gm->wd)) {
        if (check_buttons_menu(gm) == false)
            break;
        sfRenderWindow_clear(gm->wd, sfBlack);
        update_ig_menu(gm);
        sfRenderWindow_display(gm->wd);
    }
    if (gm->scene != IN_GAME_SCENE)
        return false;
    return true;
}
