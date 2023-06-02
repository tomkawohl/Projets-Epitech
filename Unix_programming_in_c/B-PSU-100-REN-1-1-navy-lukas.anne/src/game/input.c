/*
** EPITECH PROJECT, 2022
** game
** File description:
** input
*/
#include "src.h"

int check_input(char *input)
{
    char *letter_valid = "ABCDEFGH";
    char *number_valid = "12345678";
    int valid = 0;
    if (!input) return (FALSE);
    if (my_strlen(input) != 2) return (FALSE);
    for (int i = 0; letter_valid[i] != '\0'; i++) {
        if (letter_valid[i] == input[0]) {
            valid++;
            break;
        }
    }
    for (int i = 0; number_valid[i] != '\0'; i++) {
        if (number_valid[i] == input[1]) {
            valid++;
            break;
        }
    }
    if (valid == 2)
        return (TRUE);
    return (FALSE);
}

coord_t get_input_host(game_info_t *game_info)
{
    char *input = NULL;
    size_t size = 3;
    int is_input_valid = FALSE;
    coord_t coord = {0, 0};
    input = malloc(sizeof(char) * size);
    w_printf("attack: ");
        if (!input)
            return (coord);
    while (is_input_valid == FALSE) {
        getline(&input, &size, stdin);
        input[2] = '\0';
        w_printf("%s\n", input);
        if (check_input(input) == TRUE)
            break;
        w_printf("wrong position\n");
    }
    coord = send_sig_to_enemy(input, game_info);
    free(input);
    return (coord);
}

int get_input_enemy(game_info_t *game_info)
{
    char *input = NULL;
    size_t size = 3;
    int is_input_valid = FALSE;
    input = malloc(sizeof(char) * size);
    w_printf("attack: ");
        if (!input)
            return (-1);
    while (is_input_valid == FALSE) {
        getline(&input, &size, stdin);
        input[2] = '\0';
        w_printf("%s\n", input);
        if (check_input(input) == TRUE)
            break;
        w_printf("wrong position\n");
    }
    send_sig_to_host(input, game_info);
    free(input);
    return (0);
}
