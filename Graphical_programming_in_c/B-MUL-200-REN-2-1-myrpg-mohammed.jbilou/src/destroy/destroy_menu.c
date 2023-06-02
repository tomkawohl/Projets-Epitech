/*
** EPITECH PROJECT, 2023
** destroy_menu.c
** File description:
** Free and destroy all the elements in the menu
*/

#include "src.h"
#include "menu.h"

static void destroy_rect(menu_t *menu)
{
    for (size_t i = 0; i < NB_BUTTONS_START; i++){
        sfRectangleShape_destroy(menu[i].rect[0]);
        sfRectangleShape_destroy(menu[i].rect[1]);
    }
}

static void destroy_text(menu_t *menu)
{
    for (size_t i = 0; i < NB_BUTTONS_START; i++){
        if (menu[i].text[0])
            sfText_destroy(menu[i].text[0]);
        if (menu[i].text[1])
            sfText_destroy(menu[i].text[1]);
    }
}

void destroy_menu(menu_t *menu)
{
    destroy_rect(menu);
    destroy_text(menu);
    free(menu);
}
