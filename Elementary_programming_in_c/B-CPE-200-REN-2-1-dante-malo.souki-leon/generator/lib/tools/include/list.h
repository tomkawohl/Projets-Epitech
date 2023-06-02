/*
** EPITECH PROJECT, 2022
** list
** File description:
** list.h
*/

#ifndef LIST_H_
    #define LIST_H_

/* note: make it doubly circular */

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

typedef struct element_s {
    void *data;
    struct element_s *prev;
    struct element_s *next;
} element_t;

typedef struct list_s {
    element_t *first;
    element_t *end;
    unsigned int size;
} list_t;

/* list_create */
list_t *list_create(void);

/* list_add */
void list_add(list_t *list, void *value);
void list_add_end(list_t *list, void *value);

/* list_remove */
void list_clear(list_t *list);
void list_remove(list_t *list);
void list_remove_end(list_t *list);

/* list_int_create */
list_int_t *list_int_create(void);

/* list_int_add */
void list_int_add(list_int_t *list, int x);
void list_int_add_end(list_int_t *list, int x);

/* list_int_remove */
void list_int_clear(list_int_t *list);
void list_int_remove(list_int_t *list);
void list_int_remove_end(list_int_t *list);

/* list_int_display */
void list_int_display(list_int_t *list);

/* list_int_get */
int list_int_get_value(list_int_t *list, unsigned int index);
#endif /* LIST_H_ */
