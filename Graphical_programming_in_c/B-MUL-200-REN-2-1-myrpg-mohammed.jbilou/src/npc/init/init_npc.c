/*
** EPITECH PROJECT, 2023
** init_npc
** File description:
** init_npc
*/

#include "src.h"
#include "npc.h"


static sfCircleShape *create_area(sfVector2f pos, float rad)
{
    sfCircleShape *area = sfCircleShape_create();

    sfCircleShape_setRadius(area, rad);
    sfCircleShape_setFillColor(area, sfTransparent);
    sfCircleShape_setOutlineThickness(area, 2);
    sfCircleShape_setOutlineColor(area, sfWhite);
    sfCircleShape_setOrigin(area, (Vect2f){pos.x / 2, pos.y / 2});
    sfCircleShape_setPosition(area, (Vect2f){pos.x, pos.y});

    return area;
}

static sfRectangleShape *create_rect_collision(sfVector2f pos)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, (Vect2f){40, 40});
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineThickness(rect, 2);
    sfRectangleShape_setOutlineColor(rect, sfWhite);
    sfRectangleShape_setPosition(rect, pos);
    return rect;
}

static npc_t npc_create(npc_t npc, char *filepath, sfVector2f pos)
{
    npc.npc_sprite = ssl_new_sprite(filepath, (Vect2f){1.7, 1.7}, pos);
    npc.area_to_move = create_area(pos, 140);
    npc.detect_area = create_area(pos, 90);
    npc.detect_combat = create_rect_collision(pos);

    return npc;
}

void init_npc(game_t *gm)
{
    for (size_t i = 0; i < NUMBER_NPCS; i++)
        gm->npc[i] = npc_create(gm->npc[i], SKELETON_PNG, (Vect2f){400, 150});
}
