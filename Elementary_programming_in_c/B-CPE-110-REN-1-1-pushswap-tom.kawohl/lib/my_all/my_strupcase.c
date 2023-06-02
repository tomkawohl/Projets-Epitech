/*
** EPITECH PROJECT, 2022
** my_strupcase
** File description:
** my_strupcase
*/

char *my_strupcase(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] > 96 && str[i] < 123) {
            str[i] -= 32;
        }
        i++;
    }
    return (str);
}
