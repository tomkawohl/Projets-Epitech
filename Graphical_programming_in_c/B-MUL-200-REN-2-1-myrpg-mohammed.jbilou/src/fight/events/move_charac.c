/*
** EPITECH PROJECT, 2023
** move_charac
** File description:
** Moves a character before attacking
*/

#include "fight.h"

void move_pl(fight_t *fight, size_t i)
{
    double mult = 60 * (1 + fight->pl->move_frame);
    Vect2f pl_pos = {PLAYER_POS.x + mult, PLAYER_POS.y};
    Vect2f hud_pos = {PL_LIFE_HUD_POS.x + mult, PL_LIFE_HUD_POS.y};
    Vect2f life_pos = {PL_LIFE_BAR_POS.x + mult, PL_LIFE_BAR_POS.y};

    if (fight->pl->move_frame < 9) {
        fight->pl->rect.left = pl_sprite_left[fight->pl->move_frame];
        fight->pl->rect.top = 50;
        fight->pl->move_frame++;
    } else {
        fight->pl->rect.left = 0;
        fight->pl->rect.top = 0;
        fight->pl->move_frame = 0;
        fight->abut[i]->att_frame = 1;
    }
    sfSprite_setPosition(fight->pl->sprite, pl_pos);
    sfSprite_setPosition(fight->pl->life_bar->sprite, hud_pos);
    sfRectangleShape_setPosition(fight->pl->life_bar->rect, life_pos);
}

void move_en(fight_t *fight, size_t i)
{
    double mult = 45 * (1 + fight->en->move_frame);
    Vect2f en_pos = {ENEMY_POS.x - mult, ENEMY_POS.y};
    Vect2f hud_pos = {EN_LIFE_HUD_POS.x - mult, EN_LIFE_HUD_POS.y};
    Vect2f life_pos = {EN_LIFE_BAR_POS.x - mult, EN_LIFE_BAR_POS.y};

    if (fight->en->move_frame < 12) {
        fight->en->rect.left = en_sprite_left[fight->en->move_frame];
        fight->en->rect.top = 70;
        fight->en->move_frame++;
    } else {
        fight->en->rect.left = 0;
        fight->en->rect.top = 0;
        fight->en->move_frame = 0;
        fight->en_att_frame[i] = 1;
    }
    sfSprite_setPosition(fight->en->sprite, en_pos);
    sfSprite_setPosition(fight->en->life_bar->sprite, hud_pos);
    sfRectangleShape_setPosition(fight->en->life_bar->rect, life_pos);
}
