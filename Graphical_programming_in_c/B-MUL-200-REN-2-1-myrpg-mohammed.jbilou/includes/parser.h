/*
** EPITECH PROJECT, 2023
** MENU
** File description:
** MENU
*/

#ifndef PARSER_H
    #define PARSER_H
    #define player_asset "util/ASSETS/Character_assets/player_assets.png"
    #include "src.h"

/**
 * @brief parse the file and set all the informations in the structure
 * @brief separator = -> ;
 * @brief file -> [type];[name]; rect->[X][Y]; text->[X][Y]; size->[X][Y]
 * @param gm game_t *
 * @param filepath
 */
void init_parser(game_t *gm, char const *filepath);

/**
 * @brief function to split a str and transform it in an array
 *
 * @param str
 * @param c1
 * @param c2
 * @return char**
 */
char **str_to_array_separator(char const *str, char const c1, char const c2);

/**
 * @brief Get the nb of a str and returns it
 *
 * @param str
 * @return int
 */
int my_atoi(char const *str);

/**
 * @brief Getting content of text file
 *
 * @param filepath
 * @return char*
 */
char *init_buffer(char const *filepath);
#endif /* PARSER_H */
