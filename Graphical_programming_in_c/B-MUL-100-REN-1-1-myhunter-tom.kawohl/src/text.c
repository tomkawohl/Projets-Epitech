/*
** EPITECH PROJECT, 2022
** text
** File description:
** text
*/
#include "my_all.h"
#include "my_printf.h"
#include "src.h"
char *int_to_char(int nb)
{
    int j = 0;
    int nb2 = nb;
    char *str = {0};
    while (nb2 > 0){
        nb2 /= 10;
        j++;
    }
    str = malloc(sizeof(char) * (j + 1));
    str[j] = '\0';
    j--;
    while (nb > 0){
        str[j] = ((nb % 10) + '0');
        j--;
        nb /= 10;
    }
    return (str);
}

void draw_points(sfRenderWindow *win, int points, text_t score)
{
    char *buffer = int_to_char(points);
    sfText_setString(score.nbr, buffer);
    sfRenderWindow_drawText(win, score.score, NULL);
    free(buffer);
}

text_t create_text(void)
{
    text_t text = {0};
    sfVector2f pos = {105.0, 0.0};
    text.police = sfFont_createFromFile("assets/ttf/police.ttf");
    text.score = sfText_create();
    text.nbr = sfText_create();
    sfText_setPosition(text.nbr, pos);
    sfText_setFont(text.score, text.police);
    sfText_setFont(text.nbr, text.police);
    sfText_setString(text.score, "Score: ");
    return (text);
}

void draw_text(sfRenderWindow *win, text_t score)
{
    sfRenderWindow_drawText(win, score.score, NULL);
    sfRenderWindow_drawText(win, score.nbr, NULL);
}
