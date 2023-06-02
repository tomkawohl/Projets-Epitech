/*
** EPITECH PROJECT, 2023
** msl_int
** File description:
** msl_int
*/

#ifndef MSL_INT
    #define MSL_INT
    int msl_isneg(int nb);
    int msl_put_nbr(int nb);
    int msl_putstr(char const *str);
    int msl_strlen(char const *str);
    int msl_getnbr(char *str);
    int msl_my_atoi(char *str);
    int msl_overflow(char *str);
    int msl_strcmp(char const *src, char *dest);
    int msl_nbr_len(int nb);
    int msl_compute_power_rec(int nb, int power);
    int msl_compute_square_root(int nb);
    int msl_isprime(int nb);
    int msl_find_prime(int nb, int act);
    int msl_strncmp(char *src, char *dest, int n);
    int msl_str_isalpha(char *str);
    int msl_str_islower(char *str);
    int msl_str_isnum(char *str);
    int msl_str_isupper(char *str);
    int msl_str_isprintable(char *str);
    int msl_charisalpha(char c);
    int msl_charisnum(char c);
    int msl_strcnmp(char *src, char *dest, int n);
    int msl_convert_base(int number, char *base);
#endif /* !MY_INT */
