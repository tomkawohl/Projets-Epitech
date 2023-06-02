/*
** EPITECH PROJECT, 2022
** src
** File description:
** main
*/
#include "src.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return (84);
    if (my_strcmp(av[1], "-h") == 0) {
            description("src/description_text.txt");
            return (0);
    }
    if (my_strcmp(av[1], "-d") == 0) {
        debug();
        return (0);
    }
    char **map_info = parse_file(av[1]);
    if (map_info == NULL) {
        msg_wrong_file();
        return (84);
    }
    if (radar(map_info) == -1)
        return (84);
    free_array_str2d(map_info);
    return (0);
}
