/*
** EPITECH PROJECT, 2022
** priority_button
** File description:
** priority_button_add
*/
#include "my_paint.h"

button_t *button_init_center(sfVector2f pos, sfVector2f size, sfColor color)
{
    button_t *button = malloc(sizeof(*button));

    button->font = NULL;
    button->text = NULL;
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setOrigin(button->rect, (sfVector2f){size.x / 2,
        size.y / 2});
    sfRectangleShape_setFillColor(button->rect, color);
    sfRectangleShape_setPosition(button->rect, pos);
    button->state = (button_state_t){false, false, false};
    button->color = color;
    button->is_active = true;
    button->display = true;
    button->hitbox = sfRectangleShape_getGlobalBounds(button->rect);
    button->pressed_left = NULL;
    button->hover = NULL;
    return (button);
}

void position_text_center(button_t *button)
{
    sfVector2f position = {0.0, 0.0};
    button->text_hitbox = sfText_getGlobalBounds(button->text);
    position.x = button->hitbox.left + button->hitbox.width / 2.0f;
    position.y = button->hitbox.top + button->hitbox.height / 2.0f;
    position.y -= 2;
    sfText_setOrigin(button->text, (sfVector2f){button->text_hitbox.width / 2,
        button->text_hitbox.height / 2});
    sfText_setPosition(button->text, position);
}

void button_set_text_center(button_t *button, char *text, U_INT font_size,
    char *ttf)
{
    if (text == NULL || button == NULL)
        return;
    button->text = sfText_create();
    button->font = sfFont_createFromFile(ttf);
    sfText_setFont(button->text, button->font);
    sfText_setColor(button->text, sfWhite);
    sfText_setString(button->text, text);
    sfText_setCharacterSize(button->text, font_size);
    position_text_center(button);
}

void set_to_add(priority_button_element_t *to_add, priority_button_t *prio)
{
    if (prio->first == NULL) {
        prio->first = to_add;
        prio->end = to_add;
        return;
    }
    prio->first->prev = to_add;
    to_add->next = prio->first;
    prio->first = to_add;
}

void priority_button_add(priority_button_t *prio, button_info_t info)
{
    priority_button_element_t *to_add = malloc(sizeof(*to_add));
    if (to_add == NULL) return;
    to_add->prev = NULL;
    to_add->next = NULL;
    to_add->button = button_init_center(info.pos, info.size, info.color);
    if (info.text != NULL)
        button_set_text_center(to_add->button, info.text, info.font_size,
            FONT_BASIC);
    if (info.pressed_left != NULL)
        to_add->button->pressed_left = info.pressed_left;
    if (info.hover != NULL)
        to_add->button->hover = info.hover;
    to_add->button->is_active = info.is_activ;
    prio->size++;
    set_to_add(to_add, prio);
}
