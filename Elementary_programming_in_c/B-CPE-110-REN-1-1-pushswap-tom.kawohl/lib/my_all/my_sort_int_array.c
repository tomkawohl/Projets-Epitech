/*
** EPITECH PROJECT, 2022
** my_sort_int_array
** File description:
** my_sort_int_array
*/
void my_swap(int *, int *);
void my_sort_int_array(int *tab, int size)
{
    int i = 0;
    int j = 0;
    int original = 0;

    while (i < size - 1) {
        if (tab[i] > tab[i + 1]) {
            my_swap(&(tab[i]), &(tab[i + 1]));
            i = 0;
        } else {
            i++;
        }
    }
}
