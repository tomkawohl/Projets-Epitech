/*
** EPITECH PROJECT, 2022
** list.h
** File description:
** list.h
*/

#ifndef LIST_H_
    #define LIST_H_

typedef struct list_s {
    void *value;
    struct list_s *next;
} list_t;

#endif /* LIST_H_ */
