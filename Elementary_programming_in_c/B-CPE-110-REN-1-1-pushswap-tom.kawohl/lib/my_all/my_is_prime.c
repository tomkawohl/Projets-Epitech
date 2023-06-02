/*
** EPITECH PROJECT, 2022
** my_is_prime
** File description:
** my_is_prime
*/

int my_is_prime(int nb)
{
    int i = 1;
    int j = nb;
    int divisor = 0;

    if (nb <= 0) {
        return (0);
    }
    while (j > 0) {
        if (nb % i == 0) {
            divisor++;
        }
        i++;
        j--;
    }
    if (divisor == 2) {
        return (1);
    } else {
    return (0);
    }
}
