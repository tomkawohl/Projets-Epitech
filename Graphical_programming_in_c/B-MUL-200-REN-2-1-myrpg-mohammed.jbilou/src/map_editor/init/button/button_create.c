/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** button/button_create
*/
/**
 * @file button_create.c
 *
 * @brief Create a button for map edit
 *
 * @date 06/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "menu.h"

static void set_text_pos(button_edit_t *button, char *name)
{
    for (size_t i = 0; i < 2; i++) {
        button->text[i] = sfText_create();
        sfText_setFont(button->text[i], button->font);
        sfText_setString(button->text[i], name);
        sfText_setCharacterSize(button->text[i], 20);
    }
    sfText_setFillColor(button->text[0], sfWhite);
    sfText_setFillColor(button->text[1], sfRed);
}

static void set_text(button_edit_t *button, char *name, sfVector2f pos,
    sfVector2f size)
{
    sfFloatRect text_bound = {0};
    sfVector2f text_pos = {0};

    button->font = NULL;
    if (name == NULL) {
        button->text = NULL;
        return;
    }
    button->text[0] = sfText_create();
    button->text[1] = sfText_create();
    button->font = sfFont_createFromFile(HAND_FONT);
    set_text_pos(button, name);
    text_bound = sfText_getGlobalBounds(button->text[0]);
    text_pos = (sfVector2f) { pos.x + (size.x - text_bound.width) / 2,
        pos.y + (size.y - text_bound.height) / 2
    };
    sfText_setPosition(button->text[0], text_pos);
    sfText_setPosition(button->text[1], text_pos);
}

button_edit_t e_button_create(button_edit_t button, sfVector2f pos,
sfVector2f size, char *name)
{
    if (button.rect == NULL)
        return button;
    button.rect[0] = sfRectangleShape_create();
    button.rect[1] = sfRectangleShape_create();
    sfRectangleShape_setSize(button.rect[0], size);
    sfRectangleShape_setSize(button.rect[1], size);
    sfRectangleShape_setPosition(button.rect[0], pos);
    sfRectangleShape_setPosition(button.rect[1], pos);
    sfRectangleShape_setFillColor(button.rect[0], sfBlack);
    sfRectangleShape_setFillColor(button.rect[1], sfBlack);
    set_text(&button, name, pos, size);
    return (button);
}
