/*
** EPITECH PROJECT, 2023
** destroy_game.c
** File description:
** Free and destroy all the elements in the game
*/

#include "src.h"
#include "destroy.h"
#include "game_actor.h"
#include "lib_will.h"

static void game_elements_destroy(game_t *gm)
{
    if (gm->main_music)
        sfMusic_destroy(gm->main_music);
    if (gm->nihil_song)
        sfMusic_destroy(gm->nihil_song);
    if (gm->house_song)
        sfMusic_destroy(gm->house_song);
    if (gm->font)
        sfFont_destroy(gm->font);
    sfRenderWindow_destroy(gm->wd);
    if (gm->ga)
        game_actor_list_destroy(gm->ga);
    if (gm->grid)
        grid_destroy(gm->grid);
    if (gm->units)
        game_unit_list_destroy(gm->units);
    sfClock_destroy(gm->clock);
}

void destroy_game(game_t *gm)
{
    if (gm->start->menu)
        destroy_menu(gm->start->menu);
    if (gm->start->settings)
        destroy_settings(gm->start->settings, gm->sound);
    if (gm->save != NULL)
        free_array_str2d(gm->save);
    game_elements_destroy(gm);
    free(gm);
}
