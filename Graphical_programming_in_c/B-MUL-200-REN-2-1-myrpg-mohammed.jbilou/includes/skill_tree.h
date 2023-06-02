/*
** EPITECH PROJECT, 2023
** skill_tree.h
** File description:
** skill_tree
*/

#ifndef SKILL_TREE
    #define SKILL_TREE
    #define C_ASSET "util/ASSETS/STATS/COLOR/"
    #define BW_ASSET "util/ASSETS/STATS/BW/"
    #define NB_SKILLS 6
    #include "src.h"

/**
 * @brief init the skill tree values
 *
 * @param sk
 */
void init_skill_tree(skill_tree_t *sk, game_t *gm);

/**
 * @brief skill tree draw rectangles
 *
 * @param gm game_t *
 */
void skill_tree_update(game_t *gm);

/**
 * @brief skill tree events handler
 *
 * @param gm game_t *
 */
void skill_tree_events(game_t *gm);

void set_pos_skills(game_t *gm);
#endif /* !SKILL_TREE */
