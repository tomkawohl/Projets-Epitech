/*
** EPITECH PROJECT, 2022
** src
** File description:
** verify_name_var
*/
#include "src.h"

void display_error_char(void)
{
    char *error_char = NULL;
    char *error_1 = "setenv: Variable name must contain alphanumeric";
    char *error_2 = " characters.\n";
    error_char = str_recat(error_char, error_1);
    error_char = str_recat(error_char, error_2);
    write(2, error_char, my_strlen(error_char));
    free(error_char);
}

int verify_name_var(char *name)
{
    char *error_begin = "setenv: Variable name must begin with a letter.\n";
    int error = 1;
    if (!name)
        return (FALSE);
    if (char_is_alpha(name[0]) != TRUE || (char_is_num(name[0]) == TRUE)) {
        get_return(&error);
        write(2, error_begin, my_strlen(error_begin));
        return (FALSE);
    }
    for (int i = 0; name[i] != '\0'; i++) {
        if (char_is_alpha(name[i]) != TRUE && char_is_num(name[i]) != TRUE) {
            get_return(&error);
            display_error_char();
            return (FALSE);
        }
    }
    return (TRUE);
}
