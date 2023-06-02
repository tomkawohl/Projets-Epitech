/*
** EPITECH PROJECT, 2022
** wlist.h
** File description:
** wlist.h
*/

#ifndef WLIST_H_
    #define WLIST_H_
typedef struct element_int_s {
    int value;
    struct element_int_s *prev;
    struct element_int_s *next;
} element_int_t;

typedef struct list_int_s {
    element_int_t *first;
    element_int_t *end;
    unsigned int size;
} list_int_t;

/* list_int_create */
list_int_t *list_int_create(void);

/* list_int_add */
void list_int_add(list_int_t *list, int x);
void list_int_add_end(list_int_t *list, int x);

/* list_int_remove */
void list_int_remove(list_int_t *list);
void list_int_clear(list_int_t *list);
void list_int_remove_end(list_int_t *list);

/* list_int_get */
int list_get_value(list_int_t *list, int index);

#endif /* WLIST_H_ */
