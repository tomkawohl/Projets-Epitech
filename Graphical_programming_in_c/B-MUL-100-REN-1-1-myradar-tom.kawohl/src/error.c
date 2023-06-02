/*
** EPITECH PROJECT, 2022
** src
** File description:
** error
*/
#include "src.h"

void msg_wrong_file(void)
{
    char *str1 = "./myradar: error: file incorrect\n";
    char *str2 = "rerun with -h to see program's usage\n";
    write(2, str1, my_strlen(str1));
    write(2, str2, my_strlen(str2));
}
