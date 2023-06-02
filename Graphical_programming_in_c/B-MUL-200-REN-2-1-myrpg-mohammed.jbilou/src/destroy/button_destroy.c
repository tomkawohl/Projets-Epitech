/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** button/button_destroy
*/
/**
 * @file button_destroy.c
 *
 * @brief Destroy a button of map_edit
 *
 * @date 06/04/2023
*/
#include "src.h"
#include "lib_will.h"

void e_button_destroy(button_edit_t button)
{
    if (button.font != NULL)
        sfFont_destroy(button.font);
    if (button.text != NULL) {
        sfText_destroy(button.text[0]);
        sfText_destroy(button.text[1]);
    }
    if (button.rect != NULL) {
        sfRectangleShape_destroy(button.rect[0]);
        sfRectangleShape_destroy(button.rect[1]);
    }
}

void e_button_destroy_all(button_edit_t *button, u_int limit)
{
    if (button == NULL)
        return;
    for (u_int i = 0; i < limit; i++) {
        e_button_destroy(button[i]);
    }
    free(button);
}
