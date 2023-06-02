/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** my_strncpy
*/
int my_strlen(char const *);
char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int n_cpy = 0;

    if (n <= 0)
        return (dest);
    while ( src[i] != '\0') {
        dest[i] = src[i];
        i++;
        n_cpy++;
        if (n_cpy == n)
            break;
    }
    if (n < my_strlen(dest))
        dest[i] = '\0';
    return (dest);
}
