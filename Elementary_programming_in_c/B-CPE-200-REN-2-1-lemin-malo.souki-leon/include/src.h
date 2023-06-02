/*
** EPITECH PROJECT, 2022
** include
** File description:
** src.h
*/
/**
 * @file src.h
 *
 * @brief Has .h of libs, principales functions and macros about the project
 *
 * @date 28/03/2023
*/
#ifndef SRC_H_
    #define SRC_H_
    #define BOOL unsigned char
    #define true 1
    #define false 0
    #define my_printf z_printf
    typedef unsigned int u_int;

    #include <limits.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include "../lib/tools/include/tools.h"
    #include "../lib/w_printf/include/w_printf.h"
    #include "parser.h"
    #include "graph.h"
    #include "errors.h"
    #include "handle_ants.h"
    #include "handle_lem_in.h"

#endif /* SRC_H_ */
