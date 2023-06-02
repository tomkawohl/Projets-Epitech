/*
** EPITECH PROJECT, 2022
** my_compute_power_rec
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    int power = 0;
    power = nb;
    if (p == 0) {
        return (1);
    }
    if (p > 1) {
        return (power *= my_compute_power_rec(power, p - 1));
    }
}
