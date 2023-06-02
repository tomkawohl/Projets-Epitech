/*
** EPITECH PROJECT, 2023
** events_inventory.c
** File description:
** events_inventory
*/

#include "inventory.h"

static sfRectangleShape **inv(sfRectangleShape **inventory, int i,
sfColor grey, int data)
{
    sfRectangleShape_setOutlineThickness(inventory[i], 2);
    sfRectangleShape_setOutlineColor(inventory[i], sfWhite);
    sfRectangleShape_setOutlineThickness(inventory[i + data], 3);
    sfRectangleShape_setOutlineColor(inventory[i + data], grey);
    return inventory;
}

static void check_case_inv(game_t *gm, int i)
{
    if (i == 0 && sfKeyboard_isKeyPressed(sfKeyF)
    && gm->inv->is_case_able[0] == true && gm->s_hud->life + 30 <= 100) {
        gm->inv->is_case_able[0] = false;
        gm->s_hud->life += 30;
    }
    if (i == 1 && sfKeyboard_isKeyPressed(sfKeyF)
    && gm->inv->is_case_able[1] == true && gm->s_hud->life + 30 <= 100) {
        gm->inv->is_case_able[1] = false;
        gm->s_hud->life += 30;
    }
    if (i == 2 && sfKeyboard_isKeyPressed(sfKeyF)
    && gm->inv->is_case_able[2] == true && gm->s_hud->life + 30 <= 100) {
        gm->inv->is_case_able[2] = false;
        gm->s_hud->life += 30;
    }
    if (i == 3 && sfKeyboard_isKeyPressed(sfKeyF)
    && gm->inv->is_case_able[3] == true && gm->s_hud->life + 30 <= 100) {
        gm->inv->is_case_able[2] = false;
        gm->s_hud->life += 30;
    }
}

static void check_consomation(game_t *gm)
{
    size_t i = 0;
    sfColor color;

    for ( ;i < 4; i++){
        color = sfRectangleShape_getOutlineColor(gm->inv->inventory[i]);
        if (color.r == 80 && color.g == 80 && color.b == 80)
            break;
    }
    check_case_inv(gm, i);
}

static void update_pos_inv(int data, game_t *gm)
{
    u_int i = 0;
    u_int check = 0;
    sfColor grey = sfColor_fromRGB(80, 80, 80);

    for (; i < 4; i++) {
        check = sfRectangleShape_getOutlineThickness(gm->inv->inventory[i]);
        if (check == 3)
            break;
    }

    if (data == 1 && i == 3) {
        gm->inv->inventory = inv(gm->inv->inventory, i, grey, -3);
        return;
    }
    if (data == -1 && i == 0){
        gm->inv->inventory = inv(gm->inv->inventory, i, grey, 3);
        return;
    }
    gm->inv->inventory = inv(gm->inv->inventory, i, grey, data);
}

bool events_inventory(game_t *gm)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        update_pos_inv(1, gm);
        return true;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        update_pos_inv(-1, gm);
        return true;
    }
    check_consomation(gm);
    return false;
}
