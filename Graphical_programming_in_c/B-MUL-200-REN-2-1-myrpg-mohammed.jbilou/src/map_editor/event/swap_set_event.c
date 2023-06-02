/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** event/swap_set_event.c
*/
/**
 * @file swap_set_event.c
 *
 * @brief Swap set in map editor
 *
 * @date 09/04/2023
*/
#include "src.h"
#include "lib_will.h"

void swap_set(map_edit_t *map_edit, int dir)
{
    if (dir == 1) {
        if (map_edit->set_nb > 0) {
            map_edit->set_nb--;
            sfSprite_setTexture(map_edit->set_sprite,
                map_edit->set[map_edit->set_nb].texture, sfFalse);
        }
    } else {
        if (map_edit->set_nb < NB_SET - 1) {
            map_edit->set_nb++;
            sfSprite_setTexture(map_edit->set_sprite,
                    map_edit->set[map_edit->set_nb].texture, sfFalse);
        }
    }
}

static void update_by_numbers(map_edit_t *map_edit, sfEvent event,
    bool *can_press)
{
    sfKeyEvent key = event.key;
    int swap = 0;

    if (key.code < 75 || key.code > 79 || (*can_press) == false)
        return;
    swap = key.code - 75;
    if (swap != 0)
        swap = (swap * 5) - 1;
    if (swap == 19)
        swap--;
    map_edit->set_nb = swap;
    sfSprite_setTexture(map_edit->set_sprite,
                    map_edit->set[map_edit->set_nb].texture, sfFalse);
}

void swap_set_event(map_edit_t *map_edit, sfEvent event, bool *can_press)
{
    if (sfKeyboard_isKeyPressed(sfKeyLeft) && *can_press) {
        if (map_edit->set_nb > 0) {
            map_edit->set_nb--;
            sfSprite_setTexture(map_edit->set_sprite,
                map_edit->set[map_edit->set_nb].texture, sfFalse);
        }
        return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) && *can_press) {
        if (map_edit->set_nb < NB_SET - 1) {
            map_edit->set_nb++;
            sfSprite_setTexture(map_edit->set_sprite,
                map_edit->set[map_edit->set_nb].texture, sfFalse);
        }
        return;
    }
    update_by_numbers(map_edit, event, can_press);
}
