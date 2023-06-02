/*
** EPITECH PROJECT, 2023
** game_actor
** File description:
** game_actor_add
*/
/**
 * @file game_actor_add.c
 *
 * @brief Add a game actor to a list of game actors
 *
 * @date 12/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"

static void set_sprite(game_actor_t *actor, info_actor_t info)
{
    sfVector2f pos_screen = {0, 0};

    actor->texture = sfTexture_createFromFile(info.asset, NULL);
    actor->sprite = sfSprite_create();
    sfSprite_setTexture(actor->sprite, actor->texture, sfFalse);
    sfSprite_setTextureRect(actor->sprite, actor->rect);
    pos_screen.x = actor->pos.x * TILE_SIZE;
    pos_screen.y = actor->pos.y * TILE_SIZE;
    sfSprite_setPosition(actor->sprite, pos_screen);
}

static void set_value(game_actor_t *actor, info_actor_t info)
{
    actor->solid = info.solid;
    actor->type = info.type;
    actor->anim_set = info.anim_set;
    actor->frame_rate = info.frame_rate;
    actor->nb_frame = info.nb_frame;
    actor->to_animate = info.to_animate;
    actor->frame_state = 0;
    actor->prev = NULL;
    actor->next = NULL;
    actor->is_defeat = false;
}

static void set_actor(game_actor_t *actor, info_actor_t info)
{
    actor->name = NULL;
    if (info.name != NULL)
        actor->name = str_cat(actor->name, info.name);
    actor->rect = info.rect;
    actor->is_activ = info.is_activ;
    actor->pos = info.pos;
    actor->interact = info.interact;
    actor->range = info.range;
    if (info.asset != NULL)
        set_sprite(actor, info);
    else {
        actor->sprite = NULL;
        actor->texture = NULL;
    }
    set_value(actor, info);
    if (info.to_animate == true)
        actor->clock_anim = sfClock_create();
    else
        actor->clock_anim = NULL;
    return;
}

void game_actor_add(game_actor_list_t *list, info_actor_t info)
{
    game_actor_t *actor = malloc(sizeof(*actor));

    if (!verify_malloc(actor, "game_actor_add"))
        return;
    set_actor(actor, info);
    if (list->first == NULL) {
        list->first = actor;
        list->last = actor;
        list->size++;
        return;
    }
    list->first->prev = actor;
    actor->next = list->first;
    list->first = actor;
    list->size++;
    return;
}
