/*
** EPITECH PROJECT, 2023
** player_events.c
** File description:
** player_events
*/

#include "src.h"
#include "skill_tree.h"
#include "menu.h"

static void check_unpressed_tab(game_t *gm, skill_tree_t *sk, sfVector2f pos)
{
    if (gm->event.type == sfEvtKeyPressed && gm->is_skill_tree == true
    && gm->event.text.unicode == sfKeyTab) {
        for (size_t i = 0; i < NB_SKILLS; i++) {
            pos = sfRectangleShape_getPosition(sk[i].rect[0]);
            pos.x -= 600;
            sfRectangleShape_setPosition(sk[i].rect[0], pos);
            sfRectangleShape_setPosition(sk[i].rect[1], pos);
        }
        gm->is_skill_tree = false;
        return;
    }
}

void skill_tree_events(game_t *gm)
{
    sfVector2f pos;
    skill_tree_t *sk = gm->skill_t;
    sfVector2f limit;

    if (gm->event.type == sfEvtKeyPressed && gm->is_skill_tree == false
    && gm->event.text.unicode == sfKeyTab) {
        for (size_t i = 0; i < NB_SKILLS; i++) {
            pos = sfRectangleShape_getPosition(sk[i].rect[0]);
            pos.x += 600;
            sfRectangleShape_setPosition(sk[i].rect[0], pos);
            sfRectangleShape_setPosition(sk[i].rect[1], pos);
        }
        gm->is_skill_tree = true;
        return;
    }
    check_unpressed_tab(gm, sk, pos);
}
