/*
** EPITECH PROJECT, 2022
** test1
** File description:
** test %d, i, h, c, e, emaj, f, g
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../my.h"
void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std) {
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, count_simple_string) {
    int i = my_printf("hello world");
    cr_assert_eq(i, 11);
}

Test(my_printf, conv_d, .init = redirect_all_std) {
    my_printf("%d", 15);
    cr_assert_stdout_eq_str("15");
}

Test(my_printf, negativ_conv_d, .init = redirect_all_std) {
    my_printf("%d", -15);
    cr_assert_stdout_eq_str("-15");
}

Test(my_printf, conv_d_addition, .init = redirect_all_std) {
    my_printf("%d", 2 + 2);
    cr_assert_stdout_eq_str("4");
}

Test(my_printf, conv_d_twice, .init = redirect_all_std) {
    my_printf("%d%d", 15, 2000);
    cr_assert_stdout_eq_str("152000");
}

Test(my_printf, conv_d_with_char, .init = redirect_all_std) {
    my_printf("%d", 'a');
    cr_assert_stdout_eq_str("97");
}

Test(my_printf, count_conv_d) {
    int i = my_printf("%d", 12345);
    cr_assert_eq(i, 5);
}

Test(my_printf, conv_i, .init = redirect_all_std) {
    my_printf("%i", 15);
    cr_assert_stdout_eq_str("15");
}

Test(my_printf, negativ_conv_i, .init = redirect_all_std) {
    my_printf("%i", -15);
    cr_assert_stdout_eq_str("-15");
}

Test(my_printf, conv_i_addition, .init = redirect_all_std) {
    my_printf("%i", 2 + 2);
    cr_assert_stdout_eq_str("4");
}

Test(my_printf, conv_i_twice, .init = redirect_all_std) {
    my_printf("%i%i", 15, 2000);
    cr_assert_stdout_eq_str("152000");
}

Test(my_printf, conv_i_with_char, .init = redirect_all_std) {
    my_printf("%i", 'a');
    cr_assert_stdout_eq_str("97");
}

Test(my_printf, count_conv_i) {
    int i = my_printf("%i", 12345);
    cr_assert_eq(i, 5);
}

Test(my_printf, conv_b, .init = redirect_all_std) {
    my_printf("%b", 670);
    cr_assert_stdout_eq_str("1010011110");
}

Test(my_printf, conv_b_negativ, .init = redirect_all_std) {
    my_printf("%b", -670);
    cr_assert_stdout_eq_str("11111111111111111111110101100010");
}

Test(my_printf, conv_b_zero, .init = redirect_all_std) {
    my_printf("%b", 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf, conv_b_high_value, .init = redirect_all_std) {
    my_printf("%b", 99999999);
    cr_assert_stdout_eq_str("101111101011110000011111111");
}

Test(my_printf, count_conv_b_simple) {
    int i = my_printf("%b", 670);
    cr_assert_eq(i, 10);
}

Test(my_printf, count_conv_b_high_value) {
    int i = my_printf("%b", 99999999);
    cr_assert_eq(i, 27);
}

Test(my_printf, count_conv_b) {
    int i = my_printf("%b", -670);
    cr_assert_eq(i, 32);
}

Test(my_printf, conv_c, .init = redirect_all_std) {
    my_printf("%c", 'a');
    cr_assert_stdout_eq_str("a");
}

Test(my_printf, conv_c_ascii, .init = redirect_all_std) {
    my_printf("%c", 97);
    cr_assert_stdout_eq_str("a");
}

Test(my_printf, conv_c_twice, .init = redirect_all_std) {
    my_printf("%c%c", 'a', 'b');
    cr_assert_stdout_eq_str("ab");
}

Test(my_printf, count_conv_c) {
    int i = my_printf("%c", 'a');
    cr_assert_eq(i, 1);
}

Test(my_printf, count_conv_c_twice) {
    int i = my_printf("%c%c", 'a', 'b');
    cr_assert_eq(i, 2);
}

Test(my_printf, conv_e, .init = redirect_all_std) {
    my_printf("%e", 670.0);
    cr_assert_stdout_eq_str("6.700000e+02");
}

Test(my_printf, conv_e_inf_1, .init = redirect_all_std) {
    my_printf("%e", 0.005);
    cr_assert_stdout_eq_str("5.000000e-03");
}

Test(my_printf, conv_e_high_value, .init = redirect_all_std) {
    my_printf("%e", 999999.9);
    cr_assert_stdout_eq_str("9.999999e+05");
}

Test(my_printf, conv_e_high_value_inf_1, .init = redirect_all_std) {
    my_printf("%e", 0.00000009);
    cr_assert_stdout_eq_str("9.000000e-08");
}

Test(my_printf, conv_e_twice, .init = redirect_all_std) {
    my_printf("%e%e", 670.0, 0.05);
    cr_assert_stdout_eq_str("6.700000e+025.000000e-02");
}

Test(my_printf, count_conv_e) {
    int i = my_printf("%e", 670.0);
    cr_assert_eq(i, 12);
}

Test(my_printf, conv_emaj, .init = redirect_all_std) {
    my_printf("%E", 670.0);
    cr_assert_stdout_eq_str("6.700000E+02");
}

Test(my_printf, conv_emaj_inf_1, .init = redirect_all_std) {
    my_printf("%E", 0.005);
    cr_assert_stdout_eq_str("5.000000E-03");
}

Test(my_printf, conv_emaj_high_value, .init = redirect_all_std) {
    my_printf("%E", 999999.9);
    cr_assert_stdout_eq_str("9.999999E+05");
}

Test(my_printf, conv_emaj_high_value_inf_1, .init = redirect_all_std) {
    my_printf("%E", 0.00000009);
    cr_assert_stdout_eq_str("9.000000E-08");
}

Test(my_printf, conv_emaj_twice, .init = redirect_all_std) {
    my_printf("%E%E", 670.0, 0.05);
    cr_assert_stdout_eq_str("6.700000E+025.000000E-02");
}

Test(my_printf, count_conv_emaj) {
    int i = my_printf("%E", 670.0);
    cr_assert_eq(i, 12);
}

Test(my_printf, conv_f, .init = redirect_all_std) {
    my_printf("%f", 752.523);
    cr_assert_stdout_eq_str("752.523000");
}

Test(my_printf, conv_f_high_value, .init = redirect_all_std) {
    my_printf("%f", 99999.999);
    cr_assert_stdout_eq_str("99999.999");
}

Test(my_printf, conv_f_negativ, .init = redirect_all_std) {
    my_printf("%f", -752.523);
    cr_assert_stdout_eq_str("-752.523000");
}

Test(my_printf, conv_f_addition, .init = redirect_all_std) {
    my_printf("%f", 52.3 + 45.6);
    cr_assert_stdout_eq_str("97.900000");
}

Test(my_printf, count_conv_f) {
    int i = my_printf("%f", 55.623);
    cr_assert_eq(i, 9);
}

Test(my_printf, conv_g, .init = redirect_all_std) {
    my_printf("%g", 752.571);
    cr_assert_stdout_eq_str("752.571");
}

Test(my_printf, conv_g_high_value, .init = redirect_all_std) {
    my_printf("%g", 1100000.05);
    cr_assert_stdout_eq_str("1.1e+06");
}

Test(my_printf, conv_g_zero, .init = redirect_all_std) {
    my_printf("%g", 0.0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf, conv_g_negativ, .init = redirect_all_std) {
    my_printf("%g", -15.5);
    cr_assert_stdout_eq_str("-15.5");
}

Test(my_printf, count_conv_g) {
    int i = my_printf("%g", 752.523);
    cr_assert_eq(i, 7);
}

Test(my_printf, conv_n, .init = redirect_all_std) {
    int i = 0;
    my_printf("does it %nwork", &i);
    cr_assert_eq(i, 8);
}

Test(my_printf, conv_n_with_d, .init = redirect_all_std) {
    int i = 0;
    my_printf("does it %d%nwork", 1500, &i);
    cr_assert_eq(i, 12);
}

Test(my_printf, count_conv_n) {
    int i = 0;
    int j = my_printf("does it %nwork", &i);
    cr_assert_eq(j, 12);
}

Test(my_printf, count_conv_n_with_g) {
    int i = 0;
    int j = my_printf("does it %d%nwork", 1500, &i);
    cr_assert_eq(j, 16);
}

Test(my_printf, conv_o, .init = redirect_all_std) {
    my_printf("%o", 670);
    cr_assert_stdout_eq_str("1236");
}

Test(my_printf, conv_o_negativ, .init = redirect_all_std) {
    my_printf("%o", -670);
    cr_assert_stdout_eq_str("-1236");
}

Test(my_printf, conv_o_twice, .init = redirect_all_std) {
    my_printf("%o%o", 670, 852);
    cr_assert_stdout_eq_str("12361524");
}

Test(my_printf, conv_o_high_value, .init = redirect_all_std) {
    my_printf("%o", 9999999);
    cr_assert_stdout_eq_str("46113177");
}

Test(my_printf, count_conv_o) {
    int i = my_printf("%o", 9999999);
    cr_assert_eq(i, 8);
}

Test(my_printf, count_conv_p, .init = redirect_all_std) {
    int i = 5;
    int *ptr = &i;
    int j = my_printf("%p", ptr);
    cr_assert_eq(j, 14);
}

Test(my_printf, conv_percent_twice, .init = redirect_all_std) {
    my_printf("%%");
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, three_conv_percent, .init = redirect_all_std) {
    my_printf("%%%", 2 + 2);
    cr_assert_stdout_eq_str("%");
}

Test(my_printf, conv_s, .init = redirect_all_std) {
    my_printf("%s", "does it work");
    cr_assert_stdout_eq_str("does it work");
}

Test(my_printf, conv_s_twice, .init = redirect_all_std) {
    my_printf("%s%s", "does it ", "work");
    cr_assert_stdout_eq_str("does it work");
}

Test(my_printf, count_conv_s, .init = redirect_all_std) {
    int i = my_printf("%s", "does it work");
    cr_assert_eq(i, 12);
}
Test(my_printf, conv_smaj, .init = redirect_all_std) {
    my_printf("%S", "does,it!work");
    cr_assert_stdout_eq_str("does\\54it\\41work");
}

Test(my_printf, count_conv_smaj) {
    int i = my_printf("%S", "does,it!work");
    cr_assert_eq(i, 16);
}

Test(my_printf, conv_u, .init = redirect_all_std) {
    my_printf("%u", 670);
    cr_assert_stdout_eq_str("670");
}

Test(my_printf, conv_u_negativ, .init = redirect_all_std) {
    my_printf("%u", -670);
    cr_assert_stdout_eq_str("4294966626");
}

Test(my_printf, conv_u_twice, .init = redirect_all_std) {
    my_printf("%u%u", 670, 670);
    cr_assert_stdout_eq_str("670670");
}

Test(my_printf, count_conv_u) {
    int i = my_printf("%u", 5500);
    cr_assert_eq(i, 4);
}

Test(my_printf, conv_x, .init = redirect_all_std) {
    my_printf("%x", 670);
    cr_assert_stdout_eq_str("29e");
}

Test(my_printf, conv_x_negativ, .init = redirect_all_std) {
    my_printf("%x", -670);
    cr_assert_stdout_eq_str("fffffd62");
}

Test(my_printf, conv_x_twice, .init = redirect_all_std) {
    my_printf("%x%x", 670, 9999);
    cr_assert_stdout_eq_str("29e270f");
}

Test(my_printf, conv_x_high_value, .init = redirect_all_std) {
    my_printf("%x", 9999999999);
    cr_assert_stdout_eq_str("540be3ff");
}

Test(my_printf, count_conv_x) {
    int i = my_printf("%x", 670);
    cr_assert_eq(i, 3);
}

Test(my_printf, conv_xmaj, .init = redirect_all_std) {
    my_printf("%X", 670);
    cr_assert_stdout_eq_str("29E");
}

Test(my_printf, conv_xmaj_negativ, .init = redirect_all_std) {
    my_printf("%X", -670);
    cr_assert_stdout_eq_str("FFFFFD62");
}

Test(my_printf, conv_xmaj_twice, .init = redirect_all_std) {
    my_printf("%X%X", 670, 9999);
    cr_assert_stdout_eq_str("29E270F");
}

Test(my_printf, conv_xmaj_high_value, .init = redirect_all_std) {
    my_printf("%X", 9999999999);
    cr_assert_stdout_eq_str("540BE3FF");
}

Test(my_printf, count_conv_xmaj) {
    int i = my_printf("%X", 670);
    cr_assert_eq(i, 3);
}

Test(my_printf, conv_ld, .init = redirect_all_std) {
    my_printf("%ld", 4294967295);
    cr_assert_stdout_eq_str("4294967295");
}

Test(my_printf, conv_ld_negativ, .init = redirect_all_std) {
    my_printf("%ld", -4294967295);
    cr_assert_stdout_eq_str("-4294967295");
}

Test(my_printf, conv_ld_with_others_conv, .init = redirect_all_std) {
    my_printf("does it %ld %s", 4294967295, "work");
    cr_assert_stdout_eq_str("does it 4294967295 work");
}

Test(my_printf, count_conv_ld) {
    int i = my_printf("does it %ld %s", 4294967295, "work");
    cr_assert_eq(i, 23);
}

Test(my_printf, conv_li, .init = redirect_all_std) {
    my_printf("%li", 4294967295);
    cr_assert_stdout_eq_str("4294967295");
}

Test(my_printf, conv_li_negativ, .init = redirect_all_std) {
    my_printf("%li", -4294967295);
    cr_assert_stdout_eq_str("-4294967295");
}

Test(my_printf, conv_li_with_others_conv, .init = redirect_all_std) {
    my_printf("does it %li %s", 4294967295, "work");
    cr_assert_stdout_eq_str("does it 4294967295 work");
}

Test(my_printf, count_conv_li) {
    int i = my_printf("does it %li %s", 4294967295, "work");
    cr_assert_eq(i, 23);
}

Test(my_printf, conv_lo, .init = redirect_all_std) {
    my_printf("%lo", 4294967295);
    cr_assert_stdout_eq_str("37777777777");
}

Test(my_printf, conv_lo_negativ, .init = redirect_all_std) {
    my_printf("%lo", -4294967295);
    cr_assert_stdout_eq_str("1777777777740000000001");
}

Test(my_printf, conv_lo_with_others_conv, .init = redirect_all_std) {
    my_printf("does it %lo %s", 4294967295, "work");
    cr_assert_stdout_eq_str("does it 37777777777 work");
}

Test(my_printf, count_conv_lo) {
    int i = my_printf("does it %lo %s", 4294967295, "work");
    cr_assert_eq(i, 24);
}

Test(my_printf, conv_lu, .init = redirect_all_std) {
    my_printf("%lu", 4294967295);
    cr_assert_stdout_eq_str("4294967295");
}

Test(my_printf, conv_lu_negativ, .init = redirect_all_std) {
    my_printf("%lo", -4294967295);
    cr_assert_stdout_eq_str("18446744069414584321");
}

Test(my_printf, conv_lu_with_others_conv, .init = redirect_all_std) {
    my_printf("does it %lu %s", 4294967295, "work");
    cr_assert_stdout_eq_str("does it 4294967295 work");
}

Test(my_printf, count_conv_lu) {
    int i = my_printf("does it %lu %s", 4294967295, "work");
    cr_assert_eq(i, 23);
}

Test(my_printf, conv_lx, .init = redirect_all_std) {
    my_printf("%lx", 4294967295);
    cr_assert_stdout_eq_str("ffffffff");
}

Test(my_printf, conv_lx_negativ, .init = redirect_all_std) {
    my_printf("%lx", -4294967295);
    cr_assert_stdout_eq_str("ffffffff00000001");
}

Test(my_printf, conv_lx_with_others_conv, .init = redirect_all_std) {
    my_printf("does it %lx %s", 4294967295, "work");
    cr_assert_stdout_eq_str("does it ffffffff work");
}

Test(my_printf, count_conv_lx) {
    int i = my_printf("does it %lx %s", 4294967295, "work");
    cr_assert_eq(i, 21);
}

Test(my_printf, conv_lxmaj, .init = redirect_all_std) {
    my_printf("%lX", 4294967295);
    cr_assert_stdout_eq_str("FFFFFFFF");
}

Test(my_printf, conv_lxmaj_negativ, .init = redirect_all_std) {
    my_printf("%lX", -4294967295);
    cr_assert_stdout_eq_str("FFFFFFFF00000001");
}

Test(my_printf, conv_lxmaj_with_others_conv, .init = redirect_all_std) {
    my_printf("does it %lX %s", 4294967295, "work");
    cr_assert_stdout_eq_str("does it FFFFFFFF work");
}

Test(my_printf, count_conv_lxmaj) {
    int i = my_printf("does it %lX %s", 4294967295, "work");
    cr_assert_eq(i, 21);
}
