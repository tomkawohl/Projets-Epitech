/*
** EPITECH PROJECT, 2023
** text_list
** File description:
** text_list_remove
*/
/**
 * @file text_list_remove.c
 *
 * @brief Remove a text_t to a list of text
 *
 * @date 14/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "text_list.h"

static void delete_data_str(text_t *text)
{
    if (text->name != NULL) {
        free(text->name);
        text->name = NULL;
    }
    if (text->tile_asset != NULL) {
        free(text->tile_asset);
        text->tile_asset = NULL;
    }
}

static void delete_data(text_t *text)
{
    if (text->font) {
        sfFont_destroy(text->font);
        text->font = NULL;
    }
    if (text->sprite) {
        sfSprite_destroy(text->sprite);
        text->sprite = NULL;
    }
    if (text->texture) {
        sfTexture_destroy(text->texture);
        text->texture = NULL;
    }
    if (text->text) {
        sfText_destroy(text->text);
        text->text = NULL;
    }
}

void text_t_destroy(text_t *text)
{
    if (!text)
        return;
    delete_data_str(text);
    delete_data(text);
    text->next = NULL;
    text->prev = NULL;
    free(text);
    text = NULL;
}

void text_list_remove(text_list_t *list)
{
    text_t *to_remove;

    if (!list)
        return;
    if (!list->first)
        return;
    to_remove = list->first;
    list->first = list->first->next;
    text_t_destroy(to_remove);
    list->size--;
}

void text_list_find_remove(text_list_t *list, char *name)
{
    text_t *to_remove = text_list_find(list, name);

    if (to_remove == NULL)
        return;
    if (list->first == to_remove)
        list->first = to_remove->next;
    if (list->end == to_remove)
        list->end = to_remove->prev;
    if (to_remove->prev != NULL)
        to_remove->prev->next = to_remove->next;
    if (to_remove->next != NULL)
        to_remove->next->prev = to_remove->prev;
    to_remove->next = NULL;
    to_remove->prev = NULL;
    text_t_destroy(to_remove);
    return;
}
