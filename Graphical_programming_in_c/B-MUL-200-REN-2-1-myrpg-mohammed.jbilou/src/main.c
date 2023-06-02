/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "src.h"
#include <stdio.h>
#include "lib_will.h"
#include "game.h"
#include "debug.h"
#include "destroy.h"
#include "fight.h"
#include "test_area.h"

static void my_rpg(void)
{
    game_t *gm = malloc(sizeof(game_t));

    if (check_malloc(gm, "main.c") == true)
        return;
    if (init_game(gm) == 84) {
        my_printf("https://youtu.be/dQw4w9WgXcQ\n");
        return;
    }
    gm->g_scene(gm);
    destroy_game(gm);
    reset_current_save();
}

int main(int ac, const char **av)
{
    if (ac > 1) {
        if (my_strcmp(av[1], "-h") == 0) {
            handle_help();
            return (0);
        }
    }
    my_rpg();
    return 0;
}
