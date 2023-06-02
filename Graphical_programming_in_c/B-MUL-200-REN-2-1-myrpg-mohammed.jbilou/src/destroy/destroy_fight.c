/*
** EPITECH PROJECT, 2023
** destroy_fight
** File description:
** Destroys and frees the fight_t object
*/

#include "fight.h"

static void free_buttons(fight_t *fight)
{
    for (size_t i = 0; i < NB_FIGHT_MENU_BUT; i++) {
        free(fight->fbut[i]->rect);
        free(fight->fbut[i]->text);
        free(fight->fbut[i]);
    }
    free(fight->fbut);
    for (size_t i = 0; i < NB_ATTACK_BUT; i++) {
        free(fight->abut[i]->rect);
        free(fight->abut[i]->text);
        free(fight->abut[i]);
    }
    free(fight->abut);
}

static void free_fight_t(fight_t *fight)
{
    free(fight->background);
    free(fight->menu);
    free(fight->texture);
    free(fight->pl->life_bar);
    free(fight->pl);
    free(fight->en->life_bar);
    free(fight->en);
    free(fight->en_att_frame);
    free(fight->en_att_hp_remov);
    free(fight);
}

static void destroy_buttons(fight_t *fight)
{
    for (size_t i = 0; i < NB_FIGHT_MENU_BUT; i++) {
        for (size_t j = 0; j < 3; j++) {
            sfRectangleShape_destroy(fight->fbut[i]->rect[j]);
            sfText_destroy(fight->fbut[i]->text[j]);
        }
    }
    for (size_t i = 0; i < NB_ATTACK_BUT; i++) {
        for (size_t j = 0; j < 3; j++) {
            sfRectangleShape_destroy(fight->abut[i]->rect[j]);
            sfText_destroy(fight->abut[i]->text[j]);
        }
    }
    free_buttons(fight);
}

void destroy_fight_menu(fight_t *fight)
{
    sfTexture_destroy(fight->background->texture);
    sfSprite_destroy(fight->background->sprite);
    sfTexture_destroy(fight->menu->texture);
    sfSprite_destroy(fight->menu->sprite);
    sfSprite_destroy(fight->pl->sprite);
    sfTexture_destroy(fight->pl->texture);
    sfSprite_destroy(fight->pl->life_bar->sprite);
    sfTexture_destroy(fight->pl->life_bar->texture);
    sfRectangleShape_destroy(fight->pl->life_bar->rect);
    sfSprite_destroy(fight->en->sprite);
    sfTexture_destroy(fight->en->texture);
    sfSprite_destroy(fight->en->life_bar->sprite);
    sfTexture_destroy(fight->en->life_bar->texture);
    sfRectangleShape_destroy(fight->en->life_bar->rect);
    destroy_buttons(fight);
    for (size_t i = 0; i < 3; i++)
        sfTexture_destroy(fight->texture[i]);
    free_fight_t(fight);
}
