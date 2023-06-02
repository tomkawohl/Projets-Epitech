/*
** EPITECH PROJECT, 2022
** handle_l_a
** File description:
** handle_l_a
*/
#include "my_all.h"
#include "my_printf.h"
#include "src.h"
#include "wlist.h"
#include <stdlib.h>

list_int_t *init_l_a(int ac, char **av)
{
    list_int_t *l_a = list_int_create();
    int tmp = 0;
    for (int i = 1; i < ac; i++) {
        tmp = my_getnbr(av[i]);
        list_int_add_end(l_a, tmp);
    }
    return (l_a);
}
