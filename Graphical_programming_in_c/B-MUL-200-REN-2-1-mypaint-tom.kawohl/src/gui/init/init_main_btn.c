/*
** EPITECH PROJECT, 2023
** src/gui/init/init_main_btn
** File description:
** this will initialize the main button from the drop down buttons
*/

#include "my_paint.h"
/*
unsigned int add_text(main_btn_t *btn, char *title, float start_x)
{
    btn->font = sfFont_createFromFile(FONT_BASIC);
    btn->text = sfText_create();
    sfText_setFont(btn->text, btn->font);
    sfText_setColor(btn->text, sfWhite);
    sfText_setString(btn->text, title);
    sfText_setPosition(btn->text, (sfVector2f){start_x, 3.0f});
    sfText_setCharacterSize(btn->text, CHAR_SIZE);
    return (unsigned int) my_strlen(title) * (CHAR_SIZE - 10);
}

void add_rect(main_btn_t *btn, unsigned int dim, float start_x)
{
    btn->rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(btn->rect, TOP_BG);
    sfRectangleShape_setPosition(btn->rect, (sfVector2f){start_x, 0.0f});
    sfRectangleShape_setSize(btn->rect, (sfVector2f){(float) dim,
        (float) TOPBAR_HEIGHT});
}

main_btn_t add_main_btn_cut(topbar_t *topbar, char *title)
{
    main_btn_t *btn = malloc(sizeof(struct main_btn_t));
    unsigned int dim = add_text(btn, title, topbar->curr_left);
    perimiter_t *perim = malloc(sizeof(struct perimiter_t));
    perimiter_t *initial_perim = malloc(sizeof(struct perimiter_t));

    btn->perim = perim;
    btn->initial_perim = initial_perim;
    btn->perim->left = topbar->curr_left;
    btn->perim->top = 0.0;
    btn->perim->width = (float) dim;
    btn->initial_perim->width = (float) dim;
    btn->perim->height = (float) TOPBAR_HEIGHT;
    add_rect(btn, dim, topbar->curr_left);
    topbar->curr_left = topbar->curr_left + (float) dim;
    return *btn;
}

void add_main_btn(topbar_t *topbar, int index, char *title)
{
    dropdown_btn_t *dropdown_btn = malloc(sizeof(dropdown_btn_t));

    dropdown_btn->main_btn = add_main_btn_cut(topbar, title);
    topbar->dropdown_btn[index] = *dropdown_btn;
}
*/
