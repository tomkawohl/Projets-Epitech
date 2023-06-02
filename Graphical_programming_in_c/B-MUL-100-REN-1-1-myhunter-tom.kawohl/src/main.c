/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
#include "my_all.h"
#include "my_printf.h"
#include "src.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac == 2) {
        description(av[1]);
        return (0);
    }
    window_t win = {0};
    init_window(&win, 800, 600, 32);
    sfRenderWindow_setFramerateLimit(win.win, 60);
    object_t *tab = init_mainmenu();
    update_mainmenu(&win, tab);
    destroy_mainmenu(&win, tab);
    return (0);
}
