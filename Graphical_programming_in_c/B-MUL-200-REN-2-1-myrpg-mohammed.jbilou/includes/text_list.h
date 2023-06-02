/*
** EPITECH PROJECT, 2023
** include
** File description:
** text_list.h
*/

#ifndef TEXT_LIST_H_
    #define TEXT_LIST_H_
    #define TEXT_FONT "util/FONTS/text_list.ttf"
    #define GUI_ASSET "util/ASSETS/text_list/gui.png"
    #define QUEST_POS_X 17
    #define QUEST_POS_Y 5
    #define QUEST_POS {\
        gm->pl->pos.x - QUEST_POS_X, gm->pl->pos.y - QUEST_POS_Y\
        }
    #define TEXT_SQUARE {\
        145, 81, 46, 14 \
    }
    #include <SFML/Graphics.h>

struct game_s;

enum text_type {
    T_DEF,
    T_INTERACT
};

typedef struct text_info_s {
    char *name;
    sfVector2i coord;
    char *text;
    u_int size;
    char *tile_asset;
    sfIntRect asset;
    enum text_type type;
} text_info_t;

typedef struct text_s {
    char *name;
    sfTexture *texture;
    sfSprite *sprite;
    sfFont *font;
    sfText *text;
    sfVector2i pos_tile;
    sfVector2f sprite_pos;
    sfVector2f text_pos;
    char *tile_asset;
    sfIntRect asset;
    enum text_type type;
    u_int size;
    struct text_s *next;
    struct text_s *prev;
} text_t;

typedef struct text_list_s {
    text_t *first;
    text_t *end;
    unsigned int size;
} text_list_t;

/**
 * @brief Create a list of text
 *
 * @return text_list_t*
 */
text_list_t *text_list_create(void);

/**
 * @brief Add a element text_t * to a list text_list_t *
 *
 * @param list text_list_t *
 * @param info text_info_t of the new text
 */
void text_list_add(text_list_t *list, text_info_t info);

/**
 * @brief Remove the last element of text_list_t *
 *
 * @param list text_list_t *
 */
void text_list_remove(text_list_t *list);

/**
 * @brief Destroy a text_list_t *
 *
 * @param list text_list_t *
 */
void text_list_destroy(text_list_t *list);

/**
 * @brief Display a text_list_t *
 *
 * @param win sfRenderWindow *
 * @param list text_list_t *
 */
void text_list_display(sfRenderWindow *win, text_list_t *list);

/**
 * @brief Change the text of text_list_t *
 *
 * @param gm game_t *
 * @param text char * desired
 * @param name is the name of the text you want to modify, example : quete
 */
void text_list_change(struct game_s *gm, char *text, char *name);

/**
 * @brief Find a text_t in a list of text_t by his name
 *
 * @param list text_list_t *
 * @param name of the text_t, example : quete
 * @return text_t*
 */
text_t *text_list_find(text_list_t *list, char *name);

/**
 * @brief Destroy a text_t *
 *
 * @param text text_t *
 */
void text_t_destroy(text_t *text);

/**
 * @brief Find a text_t in a list by his name and remove it
 *
 * @param list text_list_t *
 * @param name char *, name of the text, example : quete
 */
void text_list_find_remove(text_list_t *list, char *name);

/**
 * @brief Update the position of text quest
 *
 * @param gm game_t *
 */
void update_quest_pos(struct game_s *gm);

/**
 * @brief Set a positon to a text_t from a text_list_t *
 *
 * @param list text_list_t *
 * @param name char *name of the text_t researched
 * @param pos new pos
 */
void text_set_pos(text_list_t *list, char *name, sfVector2i pos);

#endif /*TEXT_LIST_H_ */
