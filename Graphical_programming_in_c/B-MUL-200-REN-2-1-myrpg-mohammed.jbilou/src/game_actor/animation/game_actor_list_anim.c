/*
** EPITECH PROJECT, 2023
** game_actor/animation
** File description:
** game_actor_list_anim
*/
/**
 * @file game_actor_list_anim.c
 *
 * @brief Anim all game_actors which are to animate
 *
 * @date 17/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"

void update_animate(game_actor_t *ga)
{
    if (ga->to_animate == 2) {
        ga->to_animate = false;
        return;
    }
    ga->frame_state = 0;
    ga->rect.left -= ga->anim_set.x * ga->nb_frame;
    ga->rect.top -= ga->anim_set.y * ga->nb_frame;
    sfSprite_setTextureRect(ga->sprite, ga->rect);
}

void game_actor_animate(game_actor_t *ga)
{
    sfTime elapsed_time = sfClock_getElapsedTime(ga->clock_anim);
    int frame_index = 0;

    if (sfTime_asSeconds(elapsed_time) >= ga->frame_rate) {
        if (ga->frame_state == ga->nb_frame) {
            update_animate(ga);
        } else {
            ga->rect.left += ga->anim_set.x;
            ga->rect.top += ga->anim_set.y;
            sfSprite_setTextureRect(ga->sprite, ga->rect);
            ga->frame_state++;
        }
        sfClock_restart(ga->clock_anim);
    }
    return;
}

void game_actor_list_anim(game_t *gm)
{
    game_actor_t *ga = NULL;

    if (gm->ga == NULL)
        return;
    if (gm->ga->first == NULL)
        return;
    ga = gm->ga->first;
    while (ga) {
        if (ga->to_animate > 0)
            game_actor_animate(ga);
        ga = ga->next;
    }
    return;
}
