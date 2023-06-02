/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** my_getnbr
*/

int is_num(char c)
{
    if (c > 47 && c < 58) {
        return (1);
    } else {
        return (0);
    }
}

int is_negativ(char const *str, int i_n, int result)
{
    int operator = 0;
    while ( i_n >= 0) {
        if (str[i_n] == 45) {
            operator++;
        }
        i_n--;
    }
    if (operator % 2 == 0) {
        return (result);
    } else {
        return (-result);
    }
}

int my_all_add_result(char const *str, int *i_a)
{
    long result = 0;
    while (is_num(str[*i_a]) != 0) {
        result += str[*i_a] - 48;
        result *= 10;
        if (result > 2147483647) {
            return (0);
        }
        (*i_a)++;
        if (is_num(str[*i_a]) == 0) {
            (*i_a)--;
            result /= 10;
            return (is_negativ(str, *i_a, result));
        }
    }
}

int my_getnbr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] != 45 && str[i] != 43 && is_num(str[i]) == 0) {
            return (0);
        }
        if (is_num(str[i]) == 1) {
            return (my_all_add_result(str, &i));
        }
        i++;
    }
    return (0);
}
