/*
** EPITECH PROJECT, 2022
** src
** File description:
** attack_map
*/
#include "src.h"

void check_number(int *number, int *letter)
{
    if (*number <= 0)
        (*number) = 1;
    if (*number > 8)
        (*number) = 8;
    if (*letter <= 0)
        (*letter) = 1;
    if (*letter > 8)
        (*letter) = 8;
    (*number) += 1;
}

void check_dot(char c, int *letters_count)
{
    char *letters = "ABCDEFGH";
    for (int i = 0; letters[i] != '\0'; i++) {
        if (c == letters[i]) {
            (*letters_count)++;
            return;
        }
    }
}

int attack_map(int number, int letter, char **map)
{
    int i = 0;
    int letters_count = 0;
    int is_touched = FALSE;
    check_number(&number, &letter);
    while (map[0][i] != '\0') {
        check_dot(map[0][i], &letters_count);
        if (letters_count == letter)
            break;
        i++;
    }
    if (char_is_num(map[number][i]) == TRUE) {
        is_touched = TRUE;
        char_is_num(map[number][i] = HIT);
    } else {
        char_is_num(map[number][i] = MISS);
    }
    return (is_touched);
}
