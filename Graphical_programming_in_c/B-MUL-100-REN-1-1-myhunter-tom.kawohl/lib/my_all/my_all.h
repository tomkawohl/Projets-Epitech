/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** my.h
*/
#ifndef MY_ALL_H
    #define MY_ALL_H
void my_putchar(char);
int is_num(char);
int is_negativ(char const *, int, int);
int my_all_add_result(char const *, int *);
int my_getnbr(char const *);
int my_isneg(int);
int my_put_nbr(int);
void my_all_putstr(char const *);
int my_strlen(char const *);
void my_swap(int *, int*);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
int is_find(char *, char const *, int *, int *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *str);
char *my_strcat(char *, char const *);
char **my_str_to_word_array(char const *);
#endif
