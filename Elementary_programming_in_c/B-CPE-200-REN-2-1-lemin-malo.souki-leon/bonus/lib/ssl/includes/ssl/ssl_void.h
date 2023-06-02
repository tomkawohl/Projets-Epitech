/*
** EPITECH PROJECT, 2023
** ssl_void
** File description:
** ssl_void
*/

#ifndef SSL_VOID
    #define SSL_VOID
    #include "msl.h"
    #define Vect2f sfVector2f

    sfSprite *ssl_new_sprite(char const *path, Vect2f scale, Vect2f pos);
    sfRectangleShape *ssl_new_rect(Vect2f size, sfColor color, Vect2f pos);
    sfText *ssl_new_text(sfFont *font, Vect2f scale, Vect2f pos, char *str);
    sfCircleShape *ssl_new_cirle(Vect2f pos, float rad, sfColor color);
#endif /* !SSL_VOID */
