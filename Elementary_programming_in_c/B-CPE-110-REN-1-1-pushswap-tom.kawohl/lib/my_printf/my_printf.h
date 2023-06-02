/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/
#ifndef MY_H
    #define MY_H
    #include <stdarg.h>
int conv_e2(double nb);

int my_put_nbr2(unsigned int nb);

int my_put_u(va_list list, const char * format, int i, int count);

int idec(int n);

int conversion(va_list, const char *, int, int *);

int my_printf(const char *, ...);

int my_put_nbr(int nb);

void my_putchar(char c);

int my_putstr(char const *);

int my_strlen(char const *str);

int is_num(char);

int is_negativ(char const *, int, int);

int add_result(char const *, int);

int my_getnbr(char const *);

void display_hex(int, int *);

int my_put_nbr_hex(int, int, int *);

int my_put_nbr_base(int, char const *, int *);

void display_base(int, int, int *);

int my_put_nbr_float(double, int *);

int my_put_nbr2(unsigned int);

int my_put_nbr_float_e(double);

void check_double(double *, int *, int *);

int count_nbr(int);

int my_itoa(long);

int my_put_nbr_no_negativ(int, int *);

int conv_c(va_list, const char *, int, int *);

int conv_d(va_list, const char *, int, int *);

int conv_i(va_list, const char *, int, int *);

int conv_o(va_list, const char *, int, int *);

int conv_percent(va_list, const char *, int, int *);

int conv_s(va_list, const char *, int, int *);

int conv_smaj(va_list, const char *, int, int *);

int conv_x(va_list, const char *, int, int *);

int conv_xmaj(va_list, const char *, int, int *);

int conv_u(va_list, const char *, int, int *);

int conv_f(va_list, const char *, int, int *);

int conv_e(va_list, const char *, int, int *);

int conv_emaj(va_list, const char *, int, int *);

int conv_b(va_list, const char *, int, int *);

int conv_p(va_list, const char *, int, int *);

int conv_g(va_list, const char *, int, int *);

int conv_n(va_list, const char *, int, int *);

int length_l(va_list, const char *, int *, int *);

int count_nbr_ld(unsigned long int);

int my_put_nbr_ld(unsigned long int);

int my_put_nbr_p(unsigned long int);

void display_hex_p(unsigned long int);

int my_put_nbr_hex_p(unsigned long int, int);

int lengthl_i(va_list, const char *, int *, int *);

int lengthl_d(va_list, const char *, int *, int *);

int lengthl_o(va_list, const char *, int *, int *);

int lengthl_u(va_list, const char *, int *, int *);

int lengthl_x(va_list, const char *, int *, int *);

int lengthl_xmaj(va_list, const char *, int *, int *);

int precision(va_list, const char *, int *, int *);

int precision_d(va_list, int, int, int *count);

#endif
