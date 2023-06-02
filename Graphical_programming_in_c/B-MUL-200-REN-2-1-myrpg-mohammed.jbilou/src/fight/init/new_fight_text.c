/*
** EPITECH PROJECT, 2023
** new_fight_text
** File description:
** Returns a sfText object for fight menu buttons
*/

#include "fight.h"

sfText *new_fight_menu_text(sfFont *font, size_t but_ind, size_t color_ind)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setScale(text, FIGHT_MENU_BUT_FONT_SCALE);
    if (but_ind == FIGHT_BUT) {
        sfText_setPosition(text, FIGHT_FONT_POS);
        sfText_setString(text, "COMBATTRE");
    }
    if (but_ind == RUN_BUT) {
        sfText_setPosition(text, RUN_FONT_POS);
        sfText_setString(text, "FUIR");
    }
    if (color_ind == INDEX_WHITE)
        sfText_setColor(text, sfWhite);
    if (color_ind == INDEX_RED)
        sfText_setColor(text, sfRed);
    if (color_ind == INDEX_GREY)
        sfText_setColor(text, GREY);
    return text;
}

static void set_attack_text(sfText *text, size_t but_ind)
{
    if (but_ind == ATT_ONE_BUT) {
        sfText_setPosition(text, ATT_ONE_FONT_POS);
        sfText_setString(text, "POING D'IRE");
    }
    if (but_ind == ATT_TWO_BUT) {
        sfText_setPosition(text, ATT_TWO_FONT_POS);
        sfText_setString(text, "FAUCH'AME");
    }
    if (but_ind == ATT_THRE_BUT) {
        sfText_setPosition(text, ATT_THREE_FONT_POS);
        sfText_setString(text, "POINT MISEREUX");
    }
    if (but_ind == ATT_FOUR_BUT) {
        sfText_setPosition(text, ATT_FOUR_FONT_POS);
        sfText_setString(text, "RECUPERATION");
    }
}

sfText *new_attack_text(sfFont *font, size_t but_ind, size_t color_ind)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    if (but_ind == GO_BACK_BUT) {
        sfText_setScale(text, GO_BACK_FONT_SIZE);
        sfText_setPosition(text, GO_BACK_FONT_POS);
        sfText_setString(text, "GO BACK");
    } else {
        sfText_setScale(text, ATT_FONT_SIZE);
        set_attack_text(text, but_ind);
    }
    if (color_ind == INDEX_WHITE)
        sfText_setColor(text, sfWhite);
    if (color_ind == INDEX_RED)
        sfText_setColor(text, sfRed);
    if (color_ind == INDEX_GREY)
        sfText_setColor(text, GREY);
    return text;
}
