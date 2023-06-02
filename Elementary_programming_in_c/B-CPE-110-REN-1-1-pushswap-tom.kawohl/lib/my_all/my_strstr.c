/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** my_strstr
*/

int is_find(char *str, char const *to_find, int *i, int *j)
{
    while (str[*i] != '\0') {
        if (str[*i] == to_find[*j]) {
            return (1);
        }
        (*i)++;
    }
    return (0);
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int j = 0;
    while (to_find[j] != '\0') {
        if (is_find(str, to_find, &i, &j) == 1) {
            return (&str[i]);
        }
        j++;
    }
    return (0);
}
