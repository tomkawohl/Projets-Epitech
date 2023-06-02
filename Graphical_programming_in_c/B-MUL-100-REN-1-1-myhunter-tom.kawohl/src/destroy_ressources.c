/*
** EPITECH PROJECT, 2022
** destroy_ressources
** File description:
** destroy_ressources
*/
#include "my_all.h"
#include "my_printf.h"
#include "src.h"

void destroy_ressources(object_t *tab)
{
    int i = 0;
    while (tab[i].tab_end != 1) {
        destroy_object(&tab[i]);
        i++;
    }
}
