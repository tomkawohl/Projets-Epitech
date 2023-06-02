/*
** EPITECH PROJECT, 2023
** scene
** File description:
** handle_save
*/
/**
 * @file handle_save.c
 *
 * @brief Handle_save
 *
 * @date 21/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"
#include "test_area.h"

u_int save_find(char **save, char *find)
{
    u_int i = 0;

    if (save == NULL)
        return (0);
    while (save[i] != NULL) {
        if (str_find(save[i], find))
            return (i);
        i++;
    }
    return (0);
}

/* PUT A \N AT END OF TO_REPLACE*/
void replace_save_find(char **save, char *find, char *to_replace)
{
    u_int i = save_find(save, find);
    char *str = NULL;

    str = str_cat(str, find);
    str = str_cat(str, ":");
    str = str_cat(str, to_replace);
    w_printf("5\n");
    if (save[i] != NULL) {
        free(save[i]);
        save[i] = NULL;
    }
    w_printf("6\n");
    save[i] = str_cat(save[i], str);
    free(str);
    return;
}

void save_pos(game_t *gm)
{
    u_int i = 0;
    char *str = NULL;
    char *x = int_to_string(gm->pl->pos.x);
    char *y = int_to_string(gm->pl->pos.y);

    str = str_cat(str, x);
    str = str_cat(str, "/");
    str = str_cat(str, y);
    str = str_cat(str, "\n");
    w_printf("3\n");
    replace_save_find(gm->save, "POS PL", str);
    w_printf("4\n");
    w_printf("str added\n", str);
    free(str);
}
