/*
** EPITECH PROJECT, 2022
** src
** File description:
** is_file_valid
*/
#include "src.h"

int is_char_valid(char c)
{
    char *letters = "ABCDEFGH";
    for (int i = 0; letters[i] != '\0'; i++) {
        if (c == letters[i])
            return (TRUE);
    }
    return (FALSE);
}

int check_nb(int nb1, int nb2)
{
    if (nb1 <= 0 || nb1 > 8)
        return (FALSE);
    if (nb2 <= 0 || nb2 > 8)
        return (FALSE);
    return (TRUE);
}

int are_numbers_valid(char *check_file, int i)
{
    int nb1 = (check_file[3] - 48);
    int nb2 = (check_file[6] - 48);
    int dif = int_abs(nb1 - nb2);
    int dif_letter = int_abs(check_file[2] - check_file[5]);
    dif += 1;
    dif_letter += 1;
    if (check_nb(nb1, nb2) == FALSE)
        return (FALSE);
    if (check_file[2] == check_file[5]) {
        if (dif != i)
            return (FALSE);
    }
    if (check_file[2] != check_file[5]) {
        if (dif_letter != i)
            return (FALSE);
        if (nb1 != nb2)
            return (FALSE);
    }
    return (TRUE);
}

int is_line_valid(char *check_file, int i)
{
    i += 2;
    if (my_strlen(check_file) != 8)
        return (FALSE);
    if (check_file[0] != (i + '0'))
        return (FALSE);
    if (check_file[1] != ':' || check_file[4] != ':')
        return (FALSE);
    if (is_char_valid(check_file[2]) == FALSE ||
    is_char_valid(check_file[5]) == FALSE)
        return (FALSE);
    if (are_numbers_valid(check_file, i) == FALSE)
        return (FALSE);
    return (TRUE);
}

int is_file_valid(char *file)
{
    char **check_file = NULL;
    if (str_get_nbline(file) != 4)
        return (FALSE);
    check_file = str1d_to_str2d(file);
    if (!check_file)
        return (FALSE);
    for (int i = 0; check_file[i] != NULL; i++) {
        if (is_line_valid(check_file[i], i) == FALSE) {
            free_array_str2d(check_file);
            return (FALSE);
        }
    }
    free_array_str2d(check_file);
    return (TRUE);
}
