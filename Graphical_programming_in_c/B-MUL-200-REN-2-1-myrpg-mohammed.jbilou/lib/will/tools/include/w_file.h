/*
** EPITECH PROJECT, 2022
** include
** File description:
** w_file
*/

#ifndef W_FILE_H_
    #define W_FILE_H_
char *file_to_str_stat(const char *file_name);
/* like file_to_str_stat but with getline, fopen and fread */
char *file_to_str_getline(const char *filename);
#endif /* W_FILE_H_ */
