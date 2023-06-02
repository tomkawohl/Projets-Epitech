/*
** EPITECH PROJECT, 2023
** map
** File description:
** map_event
*/
/**
 * @file map_event.c
 *
 * @brief Handle event of a map
 *
 * @date 20/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"
#include "src_struct.h"
#include "map.h"
#include "player.h"
#include "menu.h"
#include "inventory.h"
#include "skill_tree.h"

static void play_nihil(game_t *gm)
{
    sfMusic_stop(gm->house_song);
    gm->nihil = 1;
    gm->nihil_song = sfMusic_createFromFile(NIHIL_MUSIC);
    sfMusic_getLoop(gm->nihil_song);
    sfMusic_play(gm->nihil_song);
    sfMusic_setVolume(gm->nihil_song, 100);
}

static void play_house(game_t *gm)
{
    if (gm->house == 1)
        return;
    gm->house = 1;
    gm->house_song = sfMusic_createFromFile(HOUSE_MUSIC);
    sfMusic_getLoop(gm->house_song);
    sfMusic_play(gm->house_song);
    sfMusic_setVolume(gm->house_song, 100);
}

static bool check_ig_menu(struct game_s *gm)
{
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        if (init_ig_menu(gm, gm->font) == false)
            return false;
    return true;
}

bool map_event(struct game_s *gm, sfEvent event)
{
    while (sfRenderWindow_pollEvent(gm->wd, &event)) {
        gm->event = event;
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(gm->wd);
        if (gm->current_scene == NIHIL && gm->nihil == 0)
            play_nihil(gm);
        if (gm->current_scene == 0 || gm->current_scene == 1 ||
        gm->current_scene == 2 || gm->current_scene == 3 ||
        gm->current_scene == 4)
            play_house(gm);
        events_inventory(gm);
        set_pos_skills(gm);
        if (!gm->event_in_progress)
            move_player(gm);
        if (check_ig_menu(gm) == false)
            return false;
    }
    if (gm->ga_event != NULL)
        gm->ga_event(gm);
    return true;
}
