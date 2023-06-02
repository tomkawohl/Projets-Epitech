/*
** EPITECH PROJECT, 2023
** set_fight_menu
** File description:
** Sets textures and sprites for fight_menu
*/

#include "fight.h"

static void set_background(fight_back_t *background, fight_menu_t *menu)
{
    background->texture = sfTexture_createFromFile(FIGHT_BACKGROUND, NULL);
    background->sprite = sfSprite_create();
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    menu->texture = sfTexture_createFromFile(FIGHT_MENU, NULL);
    menu->sprite = sfSprite_create();
    sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
    sfSprite_setPosition(menu->sprite, FIGHT_MENU_POS);
}

static void set_menu_but(sfFont *font, fight_but_t **but, sfTexture **texture)
{
    for (size_t i = 0; i < NB_FIGHT_MENU_BUT; i++) {
        but[i]->is_on_button = false;
        for (size_t j = 0; j < 3; j++) {
            but[i]->rect[j] = sfRectangleShape_create();
            sfRectangleShape_setSize(but[i]->rect[j], FIGHT_MENU_BUT_SIZE);
            sfRectangleShape_setTexture(but[i]->rect[j], texture[j], sfTrue);
            but[i]->text[j] = new_fight_menu_text(font, i, j);
        }
    }
    for (size_t i = 0; i < 3; i++) {
        sfRectangleShape_setPosition(but[FIGHT_BUT]->rect[i], FIGHT_BUT_POS);
        sfRectangleShape_setPosition(but[RUN_BUT]->rect[i], RUN_BUT_POS);
    }
}

static void set_att_but(sfFont *font, attack_but_t **but, sfTexture **texture)
{
    for (size_t i = 0; i < NB_ATTACK_BUT; i++) {
        but[i]->is_on_button = false;
        but[i]->att_frame = 0;
        but[i]->cooldown = 0;
        for (size_t j = 0; j < 3; j++) {
            but[i]->rect[j] = sfRectangleShape_create();
            sfRectangleShape_setSize(but[i]->rect[j], ATT_BUT_SIZE);
            sfRectangleShape_setTexture(but[i]->rect[j], texture[j], sfTrue);
            but[i]->text[j] = new_attack_text(font, i, j);
        }
    }
    for (size_t i = 0; i < 3; i++) {
        sfRectangleShape_setPosition(but[ATT_ONE_BUT]->rect[i], ATT_ONE_POS);
        sfRectangleShape_setPosition(but[ATT_TWO_BUT]->rect[i], ATT_TWO_POS);
        sfRectangleShape_setPosition(but[ATT_THRE_BUT]->rect[i], ATT_THRE_POS);
        sfRectangleShape_setPosition(but[ATT_FOUR_BUT]->rect[i], ATT_FOUR_POS);
        sfRectangleShape_setPosition(but[GO_BACK_BUT]->rect[i], GO_BACK_POS);
        sfRectangleShape_setSize(but[GO_BACK_BUT]->rect[i], GO_BACK_BUT_SIZE);
    }
}

static void set_attack_prop(attack_but_t **but, double pl_lvl)
{
    const double mult = 1.0 + pl_lvl * 0.07;

    but[ATT_ONE_BUT]->hp_remove = 17.5 * mult;
    but[ATT_TWO_BUT]->hp_remove = 25.0 * mult;
    but[ATT_THRE_BUT]->hp_remove = 12.2 * mult;
    but[ATT_FOUR_BUT]->hp_remove = 19.12 * mult;
    but[GO_BACK_BUT]->hp_remove = 0;
    for (size_t i = 0; i < NB_ATTACK_BUT; i++)
        but[i]->is_active = true;
}

void set_fight_menu(game_t *gm, fight_t *fight)
{
    fight->is_attacking = false;
    fight->has_pl_attacked = false;
    fight->has_charac_died = false;
    fight->is_finished = false;
    fight->has_pl_win = false;
    for (size_t i = 0; i < 4; i++)
        fight->en_att_frame[i] = 0;
    set_background(fight->background, fight->menu);
    fight->texture[0] = sfTexture_createFromFile(W_LARGE, NULL);
    fight->texture[1] = sfTexture_createFromFile(R_LARGE, NULL);
    fight->texture[2] = sfTexture_createFromFile(G_LARGE, NULL);
    set_menu_but(gm->font, fight->fbut, fight->texture);
    set_att_but(gm->font, fight->abut, fight->texture);
    set_attack_prop(fight->abut, gm->s_hud->lvl);
    set_player(fight->pl, gm->s_hud->life);
    set_enemy(gm, fight, fight->en);
}
