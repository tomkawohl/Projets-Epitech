/*
** EPITECH PROJECT, 2022
** tools/pencil
** File description:
** button_set_text
*/
#include "my_paint.h"

void position_text(button_t *button, U_INT font_size)
{
    sfVector2f position = {0.0, 0.0};
    button->text_hitbox = sfText_getGlobalBounds(button->text);
    position.x = button->hitbox.left + button->hitbox.width / 2.0f -
        button->text_hitbox.width / 2.0f;
    position.y = button->hitbox.top + button->hitbox.height / 2.0 -
        sfFont_getLineSpacing(button->font, font_size) / 2.0f;
    position.y -= 2;
    sfText_setPosition(button->text, position);
    button->text_hitbox = sfText_getGlobalBounds(button->text);
}

void button_set_text(button_t *button, char *text, U_INT font_size, char *ttf)
{
    if (text == NULL || button == NULL)
        return;
    button->text = sfText_create();
    button->font = sfFont_createFromFile(ttf);
    sfText_setFont(button->text, button->font);
    sfText_setColor(button->text, sfWhite);
    sfText_setString(button->text, text);
    sfText_setCharacterSize(button->text, font_size);
    position_text(button, font_size);
}
