/*
** EPITECH PROJECT, 2023
** text_list
** File description:
** text_list_display
*/
/**
 * @file text_list_display.c
 *
 * @brief Display a list of text_t
 *
 * @date 15/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "text_list.h"

void text_list_display(sfRenderWindow *win, text_list_t *list)
{
    text_t *text = NULL;

    if (!list)
        return;
    if (!list->first)
        return;
    text = list->first;
    while (text) {
        if (text->sprite != NULL)
            sfRenderWindow_drawSprite(win, text->sprite, NULL);
        if (text->text != NULL) {
            sfRenderWindow_drawText(win, text->text, NULL);
        }
        text = text->next;
    }
    return;
}
