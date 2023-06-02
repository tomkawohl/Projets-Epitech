/*
** EPITECH PROJECT, 2022
** LINK
** File description:
** LINK.h
*/

#ifndef LINK_H_
    #define LINK_H_

typedef struct link_s {

    struct link_s *next;
    struct link_s *prev;
    void *data;
} link_t;

/**
 * @brief add link to end
 *
 * @param link
 * @param data
 */
void add_link_end(link_t **link, void *data);

/**
 * @brief Create a list object
 *
 * @param node
 * @param data
 * @return link_t*
 */
link_t *create_list(link_t *node, void *data);
#endif /* LINK_H_ */
