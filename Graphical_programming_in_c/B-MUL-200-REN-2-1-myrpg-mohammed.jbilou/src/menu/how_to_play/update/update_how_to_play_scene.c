/*
** EPITECH PROJECT, 2023
** B-MUL-200-REN-2-1-myrpg-mohammed.jbilou
** File description:
** update_how_to_play_scene
*/

#include "src.h"

void init_how_to_play(game_t *gm)
{
    gm->rect_to_play = ssl_new_rect((Vect2f){1920, 1080}, sfWhite,
        (Vect2f){0, 0});
    sfTexture *texture =
    sfTexture_createFromFile("wiki/how_to_play_background.jpg", NULL);
    sfRectangleShape_setTexture(gm->rect_to_play, texture, sfTrue);
}

void event_how_to_play(game_t *gm)
{
    if (gm->scene != HOW_TO_PLAY_SCENE)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyEscape)
        && gm->scene == HOW_TO_PLAY_SCENE)
        gm->scene = MAIN_MENU_SCENE;
}

void update_how_to_play(game_t *gm)
{
    if (gm->scene != HOW_TO_PLAY_SCENE)
        return;
    sfRenderWindow_drawRectangleShape(gm->wd, gm->rect_to_play, NULL);
}
