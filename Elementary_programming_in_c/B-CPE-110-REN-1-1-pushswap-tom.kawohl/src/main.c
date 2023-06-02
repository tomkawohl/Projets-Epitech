/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include "my_all.h"
#include "my_printf.h"
#include "src.h"
#include "wlist.h"
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char **av)
{
    if (ac < 2)
        return (84);
    if (handle_error(ac, av) == -1)
        return (84);
    list_int_t *l_a = init_l_a(ac, av);
    list_int_t *l_b = list_int_create();
    if (l_a == NULL || l_b == NULL)
        return (84);
    if (list_is_sorted(l_a) == 1) {
        write(1, "\n", 1);
        return (0);
    }
    if (ac < 7)
        sort_to_5(ac, l_a, l_b);
    else
        push_swap(l_a, l_b);
    list_int_clear(l_a);
    list_int_clear(l_b);
    return (0);
}
