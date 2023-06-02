/*
** EPITECH PROJECT, 2023
** sound_events.c
** File description:
** sound_events
*/

#include "src.h"
#include "menu.h"
#include "collisions.h"

void set_level_sound(sound_t *sd, game_t *gm)
{
    float vol = sfMusic_getVolume(gm->main_music);
    sfVector2f pos = sfCircleShape_getPosition(sd->sound);
    float pos_value = (pos.y - 500) / (720 - 500) * (0 - 100) + 96;

    sfMusic_setVolume(gm->main_music, pos_value);
}

void move_regulator(sound_t *sd, game_t *gm)
{
    float rad = sfCircleShape_getRadius(sd->music);
    sfVector2f pos_music = {1460, gm->mouse.y - rad};
    sfVector2f pos_sound = {1660, gm->mouse.y - rad};

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (mouse_over_circle(sd->music, gm->mouse) == true)
            sd->check_music = true;
        if (mouse_over_circle(sd->sound, gm->mouse) == true)
            sd->check_sound = true;
    }
    if (gm->event.type == sfEvtMouseButtonReleased) {
        sd->check_music = false;
        sd->check_sound = false;
    }
    if (sd->check_music && sd->check_sound != true
    && gm->mouse.y >= 510 && gm->mouse.y <= 720)
        sfCircleShape_setPosition(sd->music, pos_music);
    if (sd->check_sound && sd->check_music != true
    && gm->mouse.y >= 510 && gm->mouse.y <= 720)
        sfCircleShape_setPosition(sd->sound, pos_sound);
}
