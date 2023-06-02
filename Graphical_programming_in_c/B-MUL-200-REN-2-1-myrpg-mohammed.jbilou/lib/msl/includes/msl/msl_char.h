/*
** EPITECH PROJECT, 2023
** msl_char
** File description:
** msl_char
*/

#ifndef MSL_CHAR
    #define MSL_CHAR
    char *msl_itoa(int nb);
    char *msl_revstr(char *str);
    char *msl_strcpy(char *str);
    char *msl_strncpy(char *str, int n);
    char *msl_strstr(char *str, char *to_find);
    char *msl_strcase(char *str, int n);
    char *msl_strcapitalize(char *str);
    char *msl_strcat(char *src, char *dest);
    char *msl_strncat(char *str, char *dest, int n);
    char **msl_str_to_word_array(char *buffer);
#endif /* !MY_CHAR */
