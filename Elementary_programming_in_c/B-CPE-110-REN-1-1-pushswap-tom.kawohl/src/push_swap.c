/*
** EPITECH PROJECT, 2022
** push_swap
** File description:
** push_swap
*/
#include "my_all.h"
#include "my_printf.h"
#include "src.h"
#include "wlist.h"
#include <stdlib.h>
#include <unistd.h>

void push_swap(list_int_t *l_a, list_int_t *l_b)
{
    int min = 0;
    while (l_a->first) {
        min = stack_get_min_index(l_a);
        for (int i = 0; i < min; i++){
            rotate_first(l_a, RA);
            write(1, SPACE, 1);
        }
        push_first(l_a, l_b, PB);
        write(1, SPACE, 1);
    }
    while (l_b->first) {
        push_first(l_b, l_a, PA);
        if (l_b->size != 0)
            write(1, SPACE, 1);
    }
    write(1, "\n", 1);
}
