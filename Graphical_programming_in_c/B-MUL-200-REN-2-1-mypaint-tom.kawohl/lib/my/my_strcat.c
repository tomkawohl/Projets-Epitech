/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** Day 06 task not done
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int dest_len = my_strlen(dest);
    unsigned int i;

    for ( i = 0 ; src[i] != '\0' ; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';

    return dest;

}
