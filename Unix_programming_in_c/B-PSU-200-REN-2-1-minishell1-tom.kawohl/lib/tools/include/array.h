/*
** EPITECH PROJECT, 2022
** array
** File description:
** array.h
*/

#ifndef ARRAY_H_
    #define ARRAY_H_
    #define TRUE 1
    #define FALSE 0

/* src/array */
char **str1d_to_str2d(const char *str);
void free_array_str2d(char **str);
void print_int1d(int *int1d, int column_size);
void print_int2d(int **int2d, int line, int column_size);
void print_str2d(char **str);
void free_array_int2d(int **int2d, int line);
#endif /* ARRAY_H_ */
