/*
** EPITECH PROJECT, 2023
** update_pnc
** File description:
** update_pnc
*/

#include "src.h"
#include "npc.h"

static sfSprite *move_sprite(sfSprite *sp, int state)
{
    sfIntRect rect;
    rect.height = 60;
    rect.left = 65 * state;
    rect.top = 180;
    rect.width = 60;
    sfSprite_setTextureRect(sp, rect);
    return sp;
}

static void update_position(sfSprite *sp)
{
    sfVector2f pos = sfSprite_getPosition(sp);
    int randX = rand() % 15;
    int randY = rand() % 20;
    pos.x -= randX;
    pos.y -= randY;
    sfSprite_setPosition(sp,  pos);
}

void update_npc(game_t *gm)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(gm->wd);
    float time = sfTime_asSeconds(sfClock_getElapsedTime(gm->npc_clock));
    static int state = 0;

    if (state > 3)
        state = 0;
        gm->npc[0].npc_sprite = move_sprite(gm->npc[0].npc_sprite, state);
    if (time > 0.18){
        sfClock_restart(gm->npc_clock);
        state++;
        update_position(gm->npc[0].npc_sprite);
    }
    for (size_t i = 0; i < NUMBER_NPCS; i++){
        sfRenderWindow_drawSprite(gm->wd, gm->npc[i].npc_sprite, NULL);
        sfRenderWindow_drawCircleShape(gm->wd, gm->npc[i].area_to_move, NULL);
        sfRenderWindow_drawRectangleShape(gm->wd,
        gm->npc[i].detect_combat, NULL);
    }
}
