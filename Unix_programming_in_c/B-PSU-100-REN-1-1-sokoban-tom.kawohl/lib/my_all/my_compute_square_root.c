/*
** EPITECH PROJECT, 2022
** my_compute_square_root
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    int nb2 = 0;
    int nb3 = 0;
    if (nb <= 0) {
        return (0);
    }
    while (nb2 != nb && nb2 < nb) {
        nb3++;
        nb2 = nb3 * nb3;
    }
    if (nb2 != nb) {
        return (0);
    } else {
        return (nb3);
    }
}
