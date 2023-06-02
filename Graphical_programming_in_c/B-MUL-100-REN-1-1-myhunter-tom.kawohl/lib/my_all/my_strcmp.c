/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** my_strcmp
*/

int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int j = 0;
    int tab_len = my_strlen(s1);
    int tab_len2 = my_strlen(s2);
    int is_equal = 0;

    while (s1[i] != '\0') {
        if (s1[i] == s2[i]) {
            is_equal++;
        }
        i++;
    }
    if (is_equal == tab_len && is_equal == tab_len2) {
        return (0);
    }
    if (tab_len < tab_len2) {
        return (-(s2[i]));
    } else {
        return (s1[i - 1]);
    }
}
