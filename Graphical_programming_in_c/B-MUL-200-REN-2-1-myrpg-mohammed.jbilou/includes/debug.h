/*
** EPITECH PROJECT, 2023
** DEBUG
** File description:
** DEBUG
*/

#ifndef DEBUG_H
    #define DEBUG_H

/**
 * @brief checks if a malloc has failed
 *
 * @param alloc element to check
 * @param filename filepath of the file where the element is been alloc'd
 * @return int 1 is NULL 0 it worked
 */
int check_malloc(void *alloc, char const *filename);
#endif /* !DEBUG_H */
