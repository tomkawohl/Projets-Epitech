/*
** EPITECH PROJECT, 2022
** TESTS lemin
** File description:
** Unit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "src.h"

void my_redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(check_malloc, rm_last_char)
{
    char *alloc = NULL;
    int check = check_malloc(alloc, "lemin_tests.c");

    cr_assert_eq(1, check);
}

Test(check_nbr, rm_last_char)
{
    char *str = "45";
    int check = my_getnbr_int(str);

    cr_assert_eq(45, check);
}

Test(check_nbr_2, rm_last_char)
{
    char *str = "90";
    int check = my_getnbr_int(str);

    cr_assert_eq(90, check);
}
