/*
** EPITECH PROJECT, 2022
** include
** File description:
** gui_info.h
*/

#ifndef GUI_INFO_H_
    #define GUI_INFO_H_

    #include "button.h"

typedef struct button_main_s {
    button_t *main;
    button_t **down;
    bool main_activ;
    bool main_display;
    bool down_activ;
    bool down_display;
} button_main_t;

typedef struct button_info_s {
    sfVector2f pos;
    sfVector2f size;
    sfColor color;
    char *text;
    int is_activ;
    void (*pressed_left)(struct paint_t *);
    void (*hover)(struct paint_t *);
    U_INT font_size;
} button_info_t;

typedef struct priority_button_element_s {
    struct priority_button_element_s *prev;
    struct priority_button_element_s *next;
    button_t *button;
} priority_button_element_t;

typedef struct priority_button_s {
    struct priority_button_element_s *first;
    struct priority_button_element_s *end;
    unsigned int size;
} priority_button_t;

typedef struct gui_info_s {
    button_main_t **topbar;
    button_main_t **rightbar;
    bool topbar_display;
    bool topbar_activ;
    bool rightbar_display;
    bool rightbar_activ;
    priority_button_t *prio;
} gui_info_t;

/* ===============================================
 * src/gui_info/gui_info_init.c
 * ===============================================
 */
/**
 * @brief Init gui_info
 *
 * @return gui_info_t*
 */
gui_info_t *gui_info_init(void);

/**
 * @brief Delete the gui, should be when programm is finished
 *
 * @param gui_info gui_info_t *
 */
void gui_info_destroy(gui_info_t *gui_info);

/**
 * @brief init stack of priority
 *
 * @return priority_button_t*
 */
priority_button_t *priority_button_init(void);

/**
 * @brief remove one element of stack priority
 *
 * @param prio priority_button_t *
 */
void priority_button_remove(priority_button_t *prio);

/**
 * @brief Drestroy a priority stack
 *
 * @param prio priority_button_t *
 */
void priority_button_destroy(priority_button_t *prio);

/**
 * @brief add a buton to the stack prio
 *
 * @param prio priority_button_t *prio
 * @param info button_info_t to give the info of the button to add
 */
void priority_button_add(priority_button_t *prio, button_info_t info);

/**
 * @brief Remove of all element of priority but doesn't free prio
 *
 * @param prio priority_button_t *
 */
void priority_button_remove_all(priority_button_t *prio);

/**
 * @brief Init a button main by default setting
 *
 * @param pos Pos of the button
 * @param size Size of the button
 * @param color Color of the button
 * @return button_main_t*
 */
button_main_t *init_button_main(sfVector2f pos, sfVector2f size,
    sfColor color);

/**
 * @brief Init rightbar
 *
 * @return button_main_t**
 */
button_main_t **rightbar_init(void);

#endif /* GUI_INFO_H_ */
