/*
** EPITECH PROJECT, 2022
** include
** File description:
** button.h
*/

#ifndef BUTTON_H_
    #define BUTTON_H_
    #define GRAY sfColor_fromRGB(52, 58, 64)
    #define FONT_SIZE 25
    #define TOPBAR_HEIGHT_BTN 35.0
    #define FILE 1
    #define EDIT 2
    #define HELP 3

    #include <SFML/Graphics.h>
struct paint_t;

typedef struct button_state_s {
    bool hover;
    bool pressed_left;
    bool released;
} button_state_t;

typedef struct button_s {
    bool is_active;
    bool display;
    sfRectangleShape *rect;
    sfText *text;
    sfFont *font;
    sfColor color;
    button_state_t state;
    sfFloatRect hitbox;
    sfFloatRect text_hitbox;
    void (*pressed_left)(struct paint_t *);
    void (*hover)(struct paint_t *);
} button_t;

/* ================================================================
 * src/button/button_init.c
 * ================================================================
 */
/**
 * @brief Init a button with default settings
 *
 * @param pos Of the button
 * @param size Of the button
 * @param color Of the button
 * @return button_t*
 */
button_t *button_init(sfVector2f pos, sfVector2f size, sfColor color);

/**
 * @brief Destroy a button
 *
 * @param button button_t *
 */
void button_destroy(button_t *button);

/* ========================================================================
 * src/button/button_set_text.c
 * ========================================================================
 */
/**
 * @brief Set a text for a button
 *
 * @param button button_t *
 * @param text A string that will be the text of the button
 * @param font_size The size of the font desired
 * @param ttf Police of characters, by default FONT_SIZE
 */
void button_set_text(button_t *button, char *text, U_INT font_size, char *ttf);

/**
 * @brief Destroy an array 2d of buttons
 *
 * @param buttons button_t **
 */
void button_destroy_all(button_t **buttons);

/* =================================================
 * src/button/topbar_init.c
 * =================================================
 */
/**
 * @brief Init the topbar
 *
 * @return button_t**
 */
button_t **topbar_init(void);

/**
 * @brief Init all the buttons of file button
 *
 * @return button_t**
 */
button_t **file_btn_init(void);

/**
 * @brief When mouse moved, check if is hover a button
 *
 * @param button button_t *
 * @param mouse sfMouseMoveEvent *
 * @return true If is hover
 * @return false If isn't hover
 */
bool button_is_mouse_hover_moved(button_t *button,
    sfMouseMoveEvent *mouse);

/**
 * @brief init Edit down btn
 *
 * @return button_t**
 */
button_t **edit_btn_init(void);

/**
 * @brief Init Help down btn
 *
 * @return button_t**
 */
button_t **help_btn_init(void);

/**
 * @brief When a click is detected, check if the mouse is hover a button
 *
 * @param button button_t *
 * @param mouse sfMouseButtonEvent *
 * @return true If mouse is hover
 * @return false If mouse isn't hover
 */
bool button_is_mouse_hover(button_t *button, sfMouseButtonEvent *mouse);

/**
 * @brief init pencil setting for right bar
 *
 * @return button_t**
 */
button_t **init_pencil_setting(void);

/**
 * @brief init eraser setting for right bar
 *
 * @return button_t**
 */
button_t **init_eraser_setting(void);

#endif /* BUTTON_H_ */
