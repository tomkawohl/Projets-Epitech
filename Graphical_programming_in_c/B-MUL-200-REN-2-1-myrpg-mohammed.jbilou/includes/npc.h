/*
** EPITECH PROJECT, 2023
** npc.h
** File description:
** npc
*/

#ifndef NPC_H_
    #define NPC_H_
    #define NUMBER_NPCS 1
    #include "src.h"
    #define SKELETON_PNG "util/ASSETS/Character_assets/skeleton_enemy.png"
    #include "game_actor.h"

struct game_actor_s;

enum jobs {
    VILLAGER,
    FIGHTHER,
    BOSS,
};

typedef struct npc_s {
    sfSprite *npc_sprite;
    double x;
    double y;
    double life;
    sfRectangleShape *detect_combat;
    sfCircleShape *detect_area;
    sfCircleShape *area_to_move;
    size_t job;
} npc_t;

/**
 * @brief events handler npc
 *
 * @param gm game_t *
 */
void events_npc(game_t *gm);

/**
 * @brief init npcs
 *
 * @param gm
 */
void init_npc(game_t *gm);

/**
 * @brief update_npc
 *
 * @param gm
 */
void update_npc(game_t *gm);

/**
 * @brief Move an npc
 *
 * @param ga game_actor_t *
 * @param pos sfVector2i
 * @return int 1 if ga arrived to destination, 0 in other case
 */
int npc_move(struct game_actor_s *ga, sfVector2i pos);

/**
 * @brief Handle exclamation of npc
 *
 * @param gm game_t *
 * @return int 1 if exclamation is terminated, 0 in other case
 */
int npc_exclamation(struct game_s *gm);

/**
 * @brief Npc move ver1 to make function npc of otherside
 *
 * @param ga game_actor_t *
 * @param pos sfVector2i
 * @return int
 */
int npc_move_ver1(game_actor_t *ga, sfVector2i pos);

#endif /* NPC_H_ */
