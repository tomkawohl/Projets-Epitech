/*
** EPITECH PROJECT, 2023
** init_inventory.c
** File description:
** init_inventory
*/

#include "inventory.h"
#include "src.h"

void init_inventory(game_t *gm)
{
    char *path = "util/ASSETS/POTION.png";
    sfVector2f size = {40, 40};
    sfVector2f pos = {620, 880};
    gm->inv->inventory = malloc(sizeof(sfRectangleShape *) * 4);
    gm->inv->content = malloc(sizeof(sfSprite *) * 4);
    gm->inv->is_case_able = malloc(sizeof(bool) * 4);
    for (int i = 0; i != 4; i++, pos.x += 43){
        gm->inv->inventory[i] = ssl_new_rect(size, sfTransparent, pos);
        gm->inv->content[i] = ssl_new_sprite(path, (sfVector2f){0.07, 0.07},
        (sfVector2f){pos.x + 25, pos.y + 3});
        sfRectangleShape_setOutlineThickness(gm->inv->inventory[i], 2);
        sfRectangleShape_setOutlineColor(gm->inv->inventory[i], sfWhite);
        gm->inv->is_case_able[i] = false;
    }
    sfRectangleShape_setOutlineThickness(gm->inv->inventory[0], 3);
    sfRectangleShape_setOutlineColor(gm->inv->inventory[0],
    sfColor_fromRGB(80, 80, 80));
}
