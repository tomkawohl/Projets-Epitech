/*
** EPITECH PROJECT, 2022
** my_strncmp
** File description:
** my_strncmp
*/

int my_strlen(char const *);
int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int count = 0;
    int tab_len = my_strlen(s1);
    int tab_len2 = my_strlen(s2);
    int is_equal = 0;
    while (s1[i] != '\0') {
        if (s1[i] == s2[i])
            is_equal++;
        count++;
        if (count == n)
            break;
        i++;
    }
    if (is_equal == count)
        return (0);
    if (tab_len < tab_len2) {
        return (-(s2[i]));
    } else {
        return (s1[i - 1]);
    }
}
