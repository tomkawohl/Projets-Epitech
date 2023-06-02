/*
** EPITECH PROJECT, 2022
** my_find_prime_sup
** File description:
** my_find_prime_sup
*/
int my_is_prime(int);
int my_find_prime_sup(int nb)
{
    while (my_is_prime(nb) != 1) {
        nb++;
            }
    return (nb);
}
