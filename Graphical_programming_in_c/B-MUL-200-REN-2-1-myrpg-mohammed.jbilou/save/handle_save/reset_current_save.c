/*
** EPITECH PROJECT, 2023
** save
** File description:
** reset_current_save
*/
/**
 * @file reset_current_save.c
 *
 * @brief Reset current data of the game
 *
 * @date 21/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"
#include "src_struct.h"
#include "map.h"
#include "player.h"
#include <dirent.h>


void reset_current_save(void)
{
    CURRENT_SCENE;
    int fd = 0;
    char *str = "CURRENT : NO\n";

    for (u_int i = 0; current_map[i] != NULL; i++) {
        fd = open(current_map[i], O_WRONLY | O_CREAT | O_TRUNC, 0777);
        if (fd != -1) {
            write(fd, str, str_len(str));
            close(fd);
        }
    }
}
