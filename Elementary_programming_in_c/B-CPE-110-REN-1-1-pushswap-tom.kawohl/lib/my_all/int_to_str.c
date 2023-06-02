/*
** EPITECH PROJECT, 2022
** int_to_str
** File description:
** int_to_str
*/
#include<stdlib.h>

char *int_to_str(int nb)
{
    int j = 0;
    int nb2 = nb;
    char *str = {0};
    while (nb2 > 0){
        nb2 /= 10;
        j++;
    }
    str = malloc(sizeof(char) * (j + 1));
    str[j] = '\0';
    j--;
    while (nb > 0){
        str[j] = ((nb % 10) + '0');
        j--;
        nb /= 10;
    }
    return (str);
}
