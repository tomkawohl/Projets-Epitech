/*
** EPITECH PROJECT, 2022
** sort_to_5
** File description:
** sort_to_5
*/
#include "my_all.h"
#include "my_printf.h"
#include "src.h"
#include "wlist.h"
#include <stdlib.h>
#include <unistd.h>

void sort_2(list_int_t *l_a)
{
    if (l_a->first->next != NULL) {
        if (l_a->first->value > l_a->first->next->value) {
            swap_first(l_a, SA);
        }
    }
}

void sort_3(list_int_t *l_a)
{
    int pos_max = stack_get_max_index(l_a);
    int pos_min = stack_get_min_index(l_a);
    if (pos_max == 2)
        sort_2(l_a);
    if (pos_max == 0 && pos_min == 2) {
        swap_first(l_a, SA);
        write(1, SPACE, 1);
        rotate_end(l_a, RRA);
    }
    if (pos_max == 0 && pos_min == 1)
        rotate_first(l_a, RA);
    if (pos_max == 1 && pos_min == 0) {
        swap_first(l_a, SA);
        write(1, SPACE, 1);
        rotate_first(l_a, RA);
    }
    if (pos_max == 1 && pos_min == 2)
        rotate_end(l_a, RRA);
}

void sort_4(list_int_t *l_a, list_int_t *l_b)
{
    int min = stack_get_min_index(l_a);
    int i = 0;
    while (i < min) {
        rotate_first(l_a, RA);
        write(1, SPACE, 1);
        i++;
    }
    push_first(l_a, l_b, PB);
    write(1, SPACE, 1);
    if (l_a != NULL) {
        if (list_is_sorted(l_a) == 0) {
            sort_3(l_a);
            write(1, SPACE, 1);
        }
    }
    push_first(l_b, l_a, PA);
}

void sort_5(list_int_t *l_a, list_int_t *l_b)
{
    int min = stack_get_min_index(l_a);
    for (int i = 0; i < min; i++){
        rotate_first(l_a, RA);
        write(1, SPACE, 1);
    }
    push_first(l_a, l_b, PB);
    min = stack_get_min_index(l_a);
    write(1, SPACE, 1);
    for (int i = 0; i < min; i++){
        rotate_first(l_a, RA);
        write(1, SPACE, 1);
    }
    push_first(l_a, l_b, PB);
    write(1, SPACE, 1);
    sort_3(l_a);
    write(1, SPACE, 1);
    push_first(l_b, l_a, PA);
    write(1, SPACE, 1);
    push_first(l_b, l_a, PA);
}

void sort_to_5(int ac, list_int_t *l_a, list_int_t *l_b)
{
    if (ac == 2)
        return;
    if (ac == 3) {
        sort_2(l_a);
    }
    if (ac == 4) {
        sort_3(l_a);
    }
    if (ac == 5) {
        sort_4(l_a, l_b);
    }
    if (ac == 6) {
        sort_5(l_a, l_b);
    }
    write(1, "\n", 1);
    return;
}
