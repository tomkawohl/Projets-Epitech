/*
** EPITECH PROJECT, 2022
** src.h
** File description:
** src.h
*/
#include "../lib/wlist/include/wlist.h"
#ifndef SRC_H_
    #define SRC_H_
    #define LIST_ERROR -1
    #define TRUE 1
    #define FALSE 0
    #define SPACE " "
    #define RA "ra"
    #define RB "rb"
    #define SA "sa"
    #define SB "sb"
    #define PA "pa"
    #define PB "pb"
    #define RRA "rra"
    #define RRB "rrb"

/* list_int_display */
void list_int_display(list_int_t *list);

/*handle l_a */
list_int_t *init_l_a(int ac, char **av);

/*swap */
int swap_first(list_int_t *list, char *str);

/* push */
int push_first(list_int_t *out, list_int_t *in, char *str);

/* list_sort */
int list_is_sorted(list_int_t *list);

/* sort_to_5 */
void sort_to_5(int ac, list_int_t *l_a, list_int_t *l_b);

/* push_swap */
void push_swap(list_int_t *l_a, list_int_t *l_b);

/* rotate */
int rotate_first(list_int_t *list, char *str);
int rotate_end(list_int_t *list, char *str);

/* handle_error */
int handle_error(int ac, char **av);

/* stack_get */
int stack_get_max_index(list_int_t *list);
int stack_get_min_index(list_int_t *list);

#endif /* SRC_H_ */
