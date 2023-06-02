/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** my_revstr
*/

int my_strlen(char const *);
char *my_revstr(char *str)
{
    int i = 0;
    int tab_len = my_strlen(str);
    int n = tab_len - 1;

    while (i < tab_len / 2) {
        char c = str[i];
        str[i] = str[n];
        str[n] = c;
        n--;
        i++;
    }
    return (str);
}
