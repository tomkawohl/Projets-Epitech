/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** event/map_editor_exit.c
*/
/**
 * @file map_editor_exit.c
 *
 * @brief Exit map edior
 *
 * @date 11/04/2023
*/
#include "src.h"
#include "lib_will.h"

static bool is_input_valid(char *input)
{
    if (input == NULL)
        return (false);
    if (str_cmp(input, "yes") != 0 && str_cmp(input, "no"))
        return (false);
    return (true);
}

static char *get_input(void)
{
    char *input = NULL;
    size_t len = 0;

    w_printf("Do you want to exit ?\nType\t yes or no\n");
    while (!is_input_valid(input)) {
        getline(&input, &len, stdin);
        input[str_len(input) - 1] = '\0';
        if (!is_input_valid(input)) {
            w_printf("Incorect answer, type yes or no\n");
        }
    }
    return (input);
}

bool map_editor_exit(void)
{
    return true;
}
