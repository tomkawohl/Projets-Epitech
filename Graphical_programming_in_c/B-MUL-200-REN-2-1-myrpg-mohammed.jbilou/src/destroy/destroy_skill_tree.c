/*
** EPITECH PROJECT, 2023
** destroy_settings.c
** File description:
** destroy_settings
*/

#include "src.h"
#include "skill_tree.h"

void destroy_skill_tree(skill_tree_t *skill_t)
{
    for (size_t i = 0; i < NB_SKILLS; i++) {
        sfRectangleShape_destroy(skill_t[i].rect[0]);
        sfRectangleShape_destroy(skill_t[i].rect[1]);
    }
}
