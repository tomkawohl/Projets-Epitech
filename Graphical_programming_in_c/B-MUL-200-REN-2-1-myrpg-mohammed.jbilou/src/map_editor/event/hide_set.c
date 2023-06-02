/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** hide_set
*/
/**
 * @file hide_set.c
 *
 * @brief Handle editor event
 *
 * @date 10/04/2023
*/
#include "src.h"
#include "lib_will.h"

void hide_set(map_edit_t *map_edit, sfEvent event, bool *can_press)
{
    if (sfKeyboard_isKeyPressed(sfKeyH) && *can_press) {
        if (map_edit->set_is_activ)
            map_edit->set_is_activ = false;
        else
            map_edit->set_is_activ = true;
    }
}
