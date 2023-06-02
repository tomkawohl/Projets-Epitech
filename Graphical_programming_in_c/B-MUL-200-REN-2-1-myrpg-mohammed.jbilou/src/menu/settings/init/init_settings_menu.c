/*
** EPITECH PROJECT, 2023
** events_settings_menu.c
** File description:
** events_settings_menu
*/

#include "src.h"
#include "menu.h"
#include "parser.h"
#include "src_struct.h"

static void create_regulator(sound_t *sd)
{
    sd->music = ssl_new_cirle((Vect2f){1460, 500}, 10, sfWhite);
    sd->sound = ssl_new_cirle((Vect2f){1660, 500}, 10, sfWhite);
}

static void set_bar_rec(sfRectangleShape *rect, sfColor color, sfColor fill)
{
    sfRectangleShape_setOutlineThickness(rect, 2);
    sfRectangleShape_setOutlineColor(rect, color);
    sfRectangleShape_setFillColor(rect, fill);
}

static void set_texture_settings(settings_t *st)
{
    for (size_t i = 0; i < NB_BUTTONS_SETTINGS; i++){
        if (i != 3 && i != 4 && i != 5 && i != 6 && i != 7) {
            set_texture_rect(st[i].rect[0], W_LARGE);
            set_texture_rect(st[i].rect[1], R_LARGE);
        }
    }
    set_texture_rect(st[4].rect[0], W_AUDIO);
    set_texture_rect(st[4].rect[1], R_AUDIO);
    set_texture_rect(st[6].rect[0], W_MUSIC);
    set_texture_rect(st[6].rect[1], R_MUSIC);
    set_bar_rec(st[5].rect[0], sfWhite, sfColor_fromRGB(144, 144, 144));
    set_bar_rec(st[5].rect[1], sfRed, sfColor_fromRGB(144, 144, 144));
    set_bar_rec(st[7].rect[0], sfWhite, sfColor_fromRGB(144, 144, 144));
    set_bar_rec(st[7].rect[1], sfRed, sfColor_fromRGB(144, 144, 144));
}

static void init_main_settings(parser_t *pr, settings_t *st, sfFont *font)
{
    sfVector2f scale = {1, 1};

    for (size_t i = 0; i < NB_BUTTONS_SETTINGS; i++) {
        st[i].rect[0] = ssl_new_rect(pr[i].size, sfWhite, pr[i].pos_rect);
        st[i].rect[1] = ssl_new_rect(pr[i].size, sfWhite, pr[i].pos_rect);
        if (msl_strcmp(pr[i].name, ".") != 0) {
            st[i].text[0] = ssl_new_text(font, scale,
            pr[i].pos_text, pr[i].name);
            st[i].text[1] = ssl_new_text(font, scale,
            pr[i].pos_text, pr[i].name);
            sfText_setColor(st[i].text[0], sfWhite);
            sfText_setColor(st[i].text[1], sfRed);
        } else {
            st[i].text[0] = NULL;
            st[i].text[1] = NULL;
        }
    }
    set_texture_settings(st);
}

void init_settings_menu(game_t *gm, sfFont *font)
{
    gm->sound->check_music = false;
    gm->sound->check_sound = false;
    if (gm->pars)
        free(gm->pars);
    init_parser(gm, "save/settings.txt");
    for (size_t i = 0; i < NB_BUTTONS_SETTINGS; i++) {
        gm->start->settings[i].rect = malloc(sizeof(sfRectangleShape *) * 2);
        gm->start->settings[i].text = malloc(sizeof(sfText *) * 2);
        gm->start->settings[i].can_draw = true;
    }
    for (size_t i = 8; i < NB_BUTTONS_SETTINGS - 1; i++)
        gm->start->settings[i].can_draw = false;
    init_main_settings(gm->pars, gm->start->settings, font);
    create_regulator(gm->sound);
}
