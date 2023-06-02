/*
** EPITECH PROJECT, 2023
** set_characters
** File description:
** Sets player and enemy struct for fight
*/

#include "fight.h"

static void set_charac_not_dead(charac_t *charac)
{
    charac->move_frame = 0;
    charac->is_dead = false;
    charac->dead_frame = 0;
}

void set_player(charac_t *pl, double pl_life)
{
    pl->life = pl_life;
    pl->rect.left = 0;
    pl->rect.top = 0;
    pl->rect.width = 68;
    pl->rect.height = 50;
    pl->sprite = sfSprite_create();
    pl->texture = sfTexture_createFromFile(PLAYER_SPRITE, NULL);
    set_charac_not_dead(pl);
    sfSprite_setTexture(pl->sprite, pl->texture, sfTrue);
    sfSprite_setTextureRect(pl->sprite, pl->rect);
    sfSprite_setPosition(pl->sprite, PLAYER_POS);
    sfSprite_setScale(pl->sprite, PLAYER_SCALE);
    pl->life_bar->sprite = sfSprite_create();
    pl->life_bar->texture = sfTexture_createFromFile(LIFE_BAR, NULL);
    pl->life_bar->rect = sfRectangleShape_create();
    sfSprite_setTexture(pl->life_bar->sprite, pl->life_bar->texture, sfTrue);
    sfSprite_setPosition(pl->life_bar->sprite, PL_LIFE_HUD_POS);
    sfSprite_setScale(pl->life_bar->sprite, PL_LIFE_HUD_SCALE);
    sfRectangleShape_setFillColor(pl->life_bar->rect, sfRed);
    sfRectangleShape_setPosition(pl->life_bar->rect, PL_LIFE_BAR_POS);
}

static void set_en_attack(fight_t *fight, double pl_lvl, size_t enemy)
{
    double mult = 1 + 0.04 * pl_lvl;

    if (enemy == 0) {
        fight->en_att_hp_remov[0] = 14.5 - mult;
        fight->en_att_hp_remov[1] = 11.19 - mult;
        fight->en_att_hp_remov[2] = 26.34;
    } else {
        fight->en_att_hp_remov[0] = 20.0 - mult;
        fight->en_att_hp_remov[1] = 16.93 - mult;
        fight->en_att_hp_remov[2] = 14.74;
    }
}

static void choose_enemy(game_t *gm, fight_t *fight, charac_t *en)
{
    const char name[10] = "skeletton";
    size_t i = 0;
    bool is_skeletton = true;

    while (i < 10 && gm->ga_current->name[i] != '\0') {
        if (name[i] != gm->ga_current->name[i]) {
            is_skeletton = false;
            break;
        }
        i++;
    }
    if (is_skeletton) {
        en->texture = sfTexture_createFromFile(SKELETTON_SPRITE, NULL);
        set_en_attack(fight, gm->s_hud->lvl, 0);
    } else {
        en->texture = sfTexture_createFromFile(MINOTAUR_SPRITE, NULL);
        set_en_attack(fight, gm->s_hud->lvl, 1);
    }
}

void set_enemy(game_t *gm, fight_t *fight, charac_t *en)
{
    en->life = 100;
    en->rect.left = 0;
    en->rect.top = 0;
    en->rect.width = 90;
    en->rect.height = 70;
    en->sprite = sfSprite_create();
    choose_enemy(gm, fight, en);
    set_charac_not_dead(en);
    sfSprite_setTexture(en->sprite, en->texture, sfTrue);
    sfSprite_setTextureRect(en->sprite, en->rect);
    sfSprite_setPosition(en->sprite, ENEMY_POS);
    sfSprite_setScale(en->sprite, ENEMY_SCALE);
    en->life_bar->sprite = sfSprite_create();
    en->life_bar->texture = sfTexture_createFromFile(LIFE_BAR, NULL);
    en->life_bar->rect = sfRectangleShape_create();
    sfSprite_setTexture(en->life_bar->sprite, en->life_bar->texture, sfTrue);
    sfSprite_setPosition(en->life_bar->sprite, EN_LIFE_HUD_POS);
    sfSprite_setScale(en->life_bar->sprite, EN_LIFE_HUD_SCALE);
    sfRectangleShape_setFillColor(en->life_bar->rect, sfRed);
    sfRectangleShape_setPosition(en->life_bar->rect, EN_LIFE_BAR_POS);
}
