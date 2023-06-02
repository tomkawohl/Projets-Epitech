/*
** EPITECH PROJECT, 2022
** src
** File description:
** text
*/
#include "src.h"

text_t text_create(void)
{
    text_t timer = {0};
    timer.text = sfText_create();
    timer.font = sfFont_createFromFile("assets/ttf/police.ttf");
    sfText_setPosition(timer.text, (sfVector2f){1650.0, 50.0});
    sfText_setFont(timer.text, timer.font);
    sfText_setColor(timer.text, sfBlack);
    sfText_setCharacterSize(timer.text, 25);
    sfText_setString(timer.text, "Timer:");
    return (timer);
}

void text_destroy(text_t *text)
{
    if (!text)
        return;
    if (text->font)
        sfFont_destroy(text->font);
    if (text->text)
        sfText_destroy(text->text);
}

void draw_text(sfRenderWindow *win, text_t timer, w_clock_t *w_clock)
{
    char *minute = int_to_string(w_clock->minute);
    char *second = int_to_string(w_clock->second);
    char *buffer = my_strdup("Timer : ");
    buffer = str_recat(buffer, minute);
    buffer = str_recat(buffer, " : ");
    buffer = str_recat(buffer, second);
    sfText_setString(timer.text, buffer);
    sfRenderWindow_drawText(win, timer.text, NULL);
    free (minute);
    free (second);
    free (buffer);
    return;
}
