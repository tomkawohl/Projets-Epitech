/*
** EPITECH PROJECT, 2023
** src_struct
** File description:
** src_struct
*/

#ifndef SRC_STRUCT
    #define SRC_STRUCT
    #include "csl_struct.h"
typedef struct compteur_s{
    int x;
    int y;
    int mcase;
    char **av;
    int ac;
    int **map;
    int check;
}compteur_t;

typedef struct src_s{
    base_t *ch;
    compteur_t *cp;
}src_t;
#endif /* !SRC_STRUCT */
