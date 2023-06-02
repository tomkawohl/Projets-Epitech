/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** my_pustr
*/

void my_putchar(char);
void my_all_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
}
