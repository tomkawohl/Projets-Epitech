/*
** EPITECH PROJECT, 2022
** include
** File description:
** w_printf.h
*/

/* add the number of characters printed ? */
#ifndef W_PRINTF_H_
    #define W_PRINTF_H_
    #include "../../tools/include/tools.h"
    #include <stdarg.h>
    #include <unistd.h>

typedef struct conversion_s {
    char conv;
    void (*ptr_f)(va_list list, const char *format, int *i);
} conversion_t;

void w_printf(const char *format, ...);

/* conv */
void conversion_exec(va_list list, const char *format, int *i);
void conv_c(va_list list, const char *format, int *i);
void conv_d(va_list list, const char *format, int *i);
void conv_s(va_list list, const char *format, int *i);
#endif /* W_PRINTF_H_ */
