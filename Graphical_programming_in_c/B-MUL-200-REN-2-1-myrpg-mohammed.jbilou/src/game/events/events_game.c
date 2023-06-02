/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "src.h"
#include <stdio.h>
#include "menu.h"
#include "parser.h"
#include "player.h"
#include "skill_tree.h"

/* HANDLE MENU EVENTS */
void events_game(game_t *gm)
{
    while (sfRenderWindow_pollEvent(gm->wd, &(gm->event))){
        gm->mouse = sfMouse_getPositionRenderWindow(gm->wd);
        if (gm->event.type == sfEvtClosed)
            sfRenderWindow_close(gm->wd);
        events_main_menu(gm);
        event_how_to_play(gm);
        events_settings_menu(gm);
    }
}
