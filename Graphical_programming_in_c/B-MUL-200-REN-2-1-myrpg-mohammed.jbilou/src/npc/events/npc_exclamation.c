/*
** EPITECH PROJECT, 2023
** npc
** File description:
** npc_exclamation
*/
/**
 * @file npc_exclamation.c
 *
 * @brief Display and exclamation of a npc
 *
 * @date 22/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"

static void handle_exclam(game_t *gm, bool *add)
{
    text_list_add(gm->list_text, (text_info_t){"exclam", (sfVector2i){
        gm->ga_current->pos.x, gm->ga_current->pos.y - 1}, " ! \n ", 18,
        GUI_ASSET, TEXT_SQUARE, T_DEF});
    sfText_setStyle(gm->list_text->first->text, sfTextBold);
    sfText_setCharacterSize(gm->list_text->first->text, 25);
    sfText_setPosition(gm->list_text->first->text, (sfVector2f){
        gm->list_text->first->text_pos.x - 5,
        gm->list_text->first->text_pos.y - 4});
    (*add) = true;
}

int npc_exclamation(game_t *gm)
{
    static sfClock *clock = NULL;
    static bool add = false;
    sfTime elapsed_time;

    if (clock == NULL)
        clock = sfClock_create();
    if (add == false)
        handle_exclam(gm, &add);
    elapsed_time = sfClock_getElapsedTime(clock);
    if (elapsed_time.microseconds >= 2000000.0f) {
        text_list_find_remove(gm->list_text, "exclam");
        sfClock_destroy(clock);
        clock = NULL;
        add = false;
        return (1);
    }
    return (0);
}
