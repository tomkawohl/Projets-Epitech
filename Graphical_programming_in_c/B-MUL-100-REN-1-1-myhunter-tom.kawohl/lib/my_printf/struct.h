/*
** EPITECH PROJECT, 2022
** struct_h
** File description:
** struct_h
*/

#include <stdarg.h>
#ifndef STRUCT_H
    #define STRUCT_H
struct precision_s {
    char precision;
    int (*ptr_fp)(va_list list, int nb1, int nb2, int *count);
};
typedef struct precision_s precision_t;
struct length_s {
    char length;
    int (*ptr_fl)(va_list list, const char *format, int *i, int *count);
};
typedef struct length_s length_t;

struct conversion_s {
    char type;
    int (*ptr_f)(va_list list, const char *format, int i, int *count);
};
typedef struct conversion_s conversion_t;

#endif /* STRUCT_H */
