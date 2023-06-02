/*
** EPITECH PROJECT, 2023
** csl_struct
** File description:
** csl_struct
*/

#ifndef CSL_STRUCT
    #define CSL_STRUCT
typedef struct base_s{
    void *data;
    struct base_s *next;
    struct base_s *prev;
}base_t;
#endif /* !CSL_STRUCT */
