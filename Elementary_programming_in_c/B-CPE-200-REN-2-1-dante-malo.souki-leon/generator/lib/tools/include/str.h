/*
** EPITECH PROJECT, 2022
** array
** File description:
** str.h
*/

#ifndef STR_H_
    #define STR_H_
    #define TRUE 1
    #define FALSE 0

/* src/str */
int my_strlen(const char *str);
void my_putstr(const char *str);
int my_getnbr_int(const char *str);
char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, const char *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, const char *to_find);
char *my_strdup(const char *str);
// use if it's the first cat
char *str_cat(char *dest, const char *src);
// use after the first cat of a same string
char *str_recat(char *dest, const char *src);
// a line end by '\n'
unsigned int str_get_nbline(const char *str);
// a column end by '\n'
unsigned int str_get_column_size(const char *str, int i);
char **str_to_word_array(char const *str);
int *str_to_int_array(const char *str);
unsigned int str_count_int(const char *str);
// return TRUE if str contains only num or ' ' or '\n'
int str_is_num(const char *str);
// return TRUE if str contains only alpha or ' ' or '\n'
int str_is_alpha(const char *str);
/* is different from the original function :
return 0 if s1 == s2 by n, 1 if s2 is less than s1, 1 in the other case
and return -2 if s1 or s2 == NULL or if n <= 0 */
int my_strncmp(const char *s1, const char *s2, int n);
/* is different from the original function :
return 0 like strcmp, return -1 or 1 like strcmp
but also return -2 if one str is NULL and -3 if they haven't the same length
*/
int my_strcmp(const char *s1, const char *s2);
// don't handle overflow and isn't so precise
float my_getnbr_float(const char *str);
#endif /* STR_H_ */
