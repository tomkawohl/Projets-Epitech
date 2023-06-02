/*
** EPITECH PROJECT, 2023
** destroy_settings.c
** File description:
** destroy_settings
*/

#include "src.h"
#include "menu.h"

static void destroy_rect(settings_t *st)
{
    for (size_t i = 0; i < NB_BUTTONS_SETTINGS; i++){
        sfRectangleShape_destroy(st[i].rect[0]);
        sfRectangleShape_destroy(st[i].rect[1]);
    }
}

static void destroy_text(settings_t *st)
{
    for (size_t i = 0; i < NB_BUTTONS_SETTINGS; i++){
        if (st[i].text[0] && st[i].text[1]){
            sfText_destroy(st[i].text[0]);
            sfText_destroy(st[i].text[1]);
        }
    }
}

void destroy_settings(settings_t *st, sound_t *sd)
{
    destroy_rect(st);
    destroy_text(st);
    sfCircleShape_destroy(sd->music);
    sfCircleShape_destroy(sd->sound);
    free(sd);
    free(st);
}
