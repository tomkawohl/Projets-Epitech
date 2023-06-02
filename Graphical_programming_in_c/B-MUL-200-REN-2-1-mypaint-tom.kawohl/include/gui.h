/*
** EPITECH PROJECT, 2023
** include/gui
** File description:
** gui components for paint header file
*/

#ifndef __GUI_H__
    #define __GUI_H__

    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System.h>
    #include <SFML/System/Clock.h>

    #include "my_bool.h"

    #define FONT_BASIC "assets/button/fonts/roboto.ttf"

    #define TOP_BG sfColor_fromRGB(84, 84, 84)
    #define TOP_HVR sfColor_fromRGB(44, 44, 44)
    #define BTN_LIGHT sfColor_fromRGB(124, 124, 124)
    #define SETTING_CLR sfColor_fromRGB(108, 117, 125)

    #define TOPBTN_LEN 2

    #define CHAR_SIZE 20

    #define TOPBAR_HEIGHT 40

    #define NONE 0
    #define HOVER 1
    #define CLICKED 2
    #define PRESSED 3 // so active button

typedef struct perimiter_t {
    float left;
    float top;
    float width;
    float height;
} perimiter_t;

typedef struct main_btn_t {
    my_bool is_active;
    sfRectangleShape *rect;
    sfText *text;
    sfFont *font;
    my_bool active;
    struct perimiter_t *perim;
    struct perimiter_t *initial_perim;
    int state;
} main_btn_t;

typedef struct dropdown_btn_t {
    sfFloatRect coords;
    int options_len;
    struct main_btn_t main_btn;
    struct options_t *options;
} dropdown_btn_t;

/*
typedef struct topbar_t {
    sfRectangleShape *background;
    sfVector2f startpos;
    float curr_left;
    struct dropdown_btn_t *dropdown_btn;
    int ddbtn_len;
} topbar_t;
*/
typedef struct gui_t {
//    struct toolbar_t toolbar;
    struct topbar_t *topbar;
//    struct inspector_t inspector;
} gui_t;

#endif /* __GUI_H__ */
