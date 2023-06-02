/*
** EPITECH PROJECT, 2023
** include/my_paint.h
** File description:
** The main header file for the my_paint project
*/

#ifndef __MY_PAINT_H__
    #define __MY_PAINT_H__
    #define U_INT unsigned int

    #include <stdbool.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/System.h>
    #include <SFML/System/Clock.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>
    #include <stdio.h>
    #include <unistd.h>

    #include "my.h"
    #include "list_texture.h"
    #include "layer.h"
    #include "my_paint_tools.h"
    #include "gui.h"
    #include "button.h"
    #include "gui_info.h"

    #define UNUSED __attribute__((unused))

    #define MAIN_MENU_ 1
    #define PANTING 2

    #define RUN 0
    #define TERMINATE 1

    #define WIDTH 1500
    #define HEIGHT 845

    #define CANVAS_W 800
    #define CANVAS_H 400
    #define CANVAS_START_X 400.0
    #define CANVAS_START_Y 200.0

    #define FPS 60

    #define ZOOM 1
    #define RESIZE 2

    #define RIGHT_WIDTH 300.0

enum state {
    MAIN_MENU,
    PAINTING
};

typedef struct canvas_t {
    struct perimiter_t *perim;
    sfRectangleShape *rect;
} canvas_t;

typedef struct save_t {
    char *filename;
    sfTexture *texture;
    sfImage *image;
} save_t;

typedef struct paint_t {
    enum state state;
    gui_info_t *gui;
    sfRenderWindow *window;
    sfEvent event;
    layer_t *layer;
    tool_t *tools;
    int selected_tool;
    int running;
    sfVector2u window_size;
    float window_zoom;
    struct canvas_t *canvas;
    int origin_status;
    struct save_t save;
    my_bool move;
    sfVector2f moved;
} paint_t;

typedef struct options_t {
    struct perimiter_t perim;
    sfRectangleShape *rect;
    sfText *text;
    sfFont *font;
    void (*funct)(paint_t *info);
} options_t;

/* ==========================================================
 * src/init/init.c
 * =========================================================
 */
/*
 * @brief main function
 * @param argc int
 * @param argv char**
 * @return int return value of executable
 */
int main(UNUSED int argc, UNUSED char **argv);

/* ==========================================================
 * src/init/init.c
 * =========================================================
 */
/*
 * @brief init the window
 * @param info paint_t *
 * @return void
 */
void init_window(paint_t *info);
/*
 * @brief init the whole struct and project
 * @param info paint_t *
 * @return void
 */
void init(paint_t *info);

/* ==========================================================
 * src/run/run.c
 * =========================================================
 */
/*
 * @brief init the window
 * @param info paint_t *
 * @return void
 */
void run(paint_t *info);

/* ==========================================================
 * src/event/handle_event.c
 * =========================================================
 */
/*
 * @brief init the window
 * @param info paint_t *
 * @return void
 */
void handle_event(paint_t *info);
/*
 * @brief zoom event
 * @param sfEvent
 * @param info paint_t *
 * @return void
 */
void zoom_event(sfEvent event, paint_t *info);
/*
 * @brief init the window
 * @param info paint_t *
 * @return void
 */
void move_event(paint_t *info);

/* ==========================================================
 * src/event/save_file_event.c
 * =========================================================
 */
/*
 * @brief init the window
 * @param info paint_t *
 * @return void
 */
void save_file_event(sfEvent event, paint_t *info);


/* ==========================================================
 * src/run/run_draw.c
 * =========================================================
 */
void run_window_draw(paint_t *info);

/**
 * ==========================================================
 * src/tools/tool_init
 * ==========================================================
 */
/* @brief Init all tools of info->tools
 *
 * @param info struct pain_t which contains tools
 */
void tool_init(paint_t *info);

/**
 * ==========================================================
 * src/info/info_destroy
 * ==========================================================
 */
/* @brief Destroy pain_t struct
 *
 * @param info is the struct pain_t to destroy
 */
void info_destroy(paint_t *info);

/* ================================================
 * src/gui/gui_top_init.c
 * ================================================
 */
/*
 * @brief initialzes the top bar of the screen
 * @param info *paint_t
 * @return void
 */
void gui_top_init(paint_t *info);

/* ================================================
 * src/tools/pencil/pencil_draw
 * ================================================
 */
/**
 * @brief Draw all textures and layer if their display is activ
 *
 * @param info *paint_t
 */
void pencil_draw(paint_t *info);

/* ================================================
 * src/gui/init_main_btn.c
 * ================================================
 */
/**
 * @brief Draw all textures and layer if their display is activ
 *
 * @param info *paint_t
 */
//dropdown_btn_t *init_dd_btn(paint_t *info, topbar_t *topbar);

/* ================================================
 * src/layer/layer_event
 * ================================================
 */
/**
 * @brief Handle layer_event, add layer or remove or set activ
 *
 * @param info paint_t *
 * @param event sfEvent
 */
void layer_event(paint_t *info, sfEvent event);

/* ================================================
 * src/layer/layer_draw
 * ================================================
 */
/**
 * @brief Draw all layers activ
 *
 * @param info paint_t *
 */
void layer_draw(paint_t *info);

/* ================================================
 * src/helper/get.c
 * ================================================
 */
/**
 * @brief get scale in coefficient needs to be called for each coordinate
 * @param ori float original size at init
 * @param new_window float new window size after resize
 * @param window float original window size metric for that coordinate
 * @return float value to scale by
 */
float get_scale(float ori, float new_window, float window);
/**
 * @brief gets if coordinate given is in a perimiter
 * @param y int coordinate y
 * @param x int coordinate x
 * @param perim perimiter_t to test
 * @return my_bool true if yes andvoid set_hover(main_btn_t btn)
 false if no
 */
my_bool get_is_in_perimiter(int y, int x, perimiter_t *perim, int size);
int get_arrlen(char **arr);
sfVector2f get_origin(paint_t *info);
my_bool get_input(paint_t *info);

/* ================================================
 * src/gui/event/gui_event.c
 * ================================================
 */
/**
 * @brief handles the event when a drop down button is
 * active and needs to show all its opitons
 * @param btn dropdown_btn_t
 * @param window sfRenderWindow*
 * @return void
 */
//void show_dropdown(dropdown_btn_t btn, sfRenderWindow *window);
/**
 * @brief handles events pertaining to gui events
 * @param event sfEvent
 * @param info paint_t* struct for the project
 * @return void
 */
void gui_event(sfEvent event, paint_t *info);

/* ================================================
 * src/helper/set1.c
 * =======================-========================
 */
/**
 * @brief sets main_btn_t to hover mode
 * @param btn main_btn_t
 * @return void
 */
void set_hover(main_btn_t btn);
/**
 * @brief sets main_btn_t to hover mode
 * @param btn main_btn_t
 * @return void
 */
void set_none(main_btn_t btn);
/**
 * @brief sets main_btn_t to hover mode
 * @param btn main_btn_t
 * @return void
 */
void set_active(dropdown_btn_t btn, sfRenderWindow *window);
/**
 * @brief sets main_btn_t to hover mode
 * @param btn main_btn_t
 * @return void
 */
void set_inactive_all(dropdown_btn_t *btn);

/* ================================================
 * src/tool/tool_event.c
 * ================================================
 */
/**
 * @brief Check if user has changed his tool
 *
 * @param event sfEvent to get input of user
 * @param info paint_t *
 */
void tool_event(sfEvent event, paint_t *info);

/* ================================================
 * src/tool/pencil_event.c
 * ================================================
 */
/**
 * @brief Manage event for pencil, check if pencil is activ,
 * do behaviour of pencil if Mouse has moved.
 * Just add in the loop of event while (sfRenderWindow_pollEvent)
 *
 * @param event Event variable
 * @param pencil Struct of pencil tool
 */
void pencil_event(paint_t *info, sfEvent event, pencil_t *pencil);

/* ================================================
 * src/gui_info/gui_info_draw
 * ================================================
 */
/**
 * @brief Draw all activ element of gui
 *
 * @param info pain_t *
 */
void gui_info_draw(paint_t *info);

/**
 * @brief Manage event for gui
 *
 * @param event sfEvent
 * @param info paint_t *
 */
void gui_info_event(sfEvent event, paint_t *info);

/**
 * @brief Manage click event for gui
 *
 * @param event sfEvent
 * @param info paint_t *
 */
void check_gui_click(sfEvent event, paint_t *info);

/**
 * @brief Handle help press left
 *
 * @param info paint_t *
 */
void help_press_left(paint_t *info);

/**
 * @brief Draw all button priority
 *
 * @param prio Stack priority_button_t *
 * @param info paint_t *
 */
void priority_button_draw(priority_button_t *prio, paint_t *info);

/**
 * @brief In helper, for str_car
 *
 * @param str const char *str
 * @return unsigned int Size of the str
 */
unsigned int str_len(const char *str);

/**
 * @brief Duplicate a str into a new one
 *
 * @param str Const char *to copy
 * @return char*
 */
char *str_dup(const char *str);

/**
 * @brief Concatenate two string
 *
 * @param dest Char * destination
 * @param src Char * to add to destination
 * @return char* The new string
 */
char *str_cat(char *dest, const char *src);

/**
 * @brief Manage event of priority button
 *
 * @param event sfEvent
 * @param info paint_t *
 */
void priority_button_event(sfEvent event, paint_t *info);

/**
 * @brief Do click for a button
 *
 * @param button button_t *
 * @param info paint_t *
 */
void do_click(button_t *button, paint_t *info);

/**
 * @brief Set activ pencil via button pencil of edit
 *
 * @param info paint_t *info
 */
void pencil_btn_press_left(paint_t *info);

/**
 * @brief Set activ eraser via button eraser of edit
 *
 * @param info paint_t *
 */
void eraser_btn_press_left(paint_t *info);

/**
 * @brief Set the rightbar object to true
 *
 * @param info pain_t *info
 * @param tool_activ Which tool to set activ
 */
void set_rightbar(paint_t *info, int tool_activ);

/**
 * @brief Resize text when user resize window
 *
 * @param text sfText *to_resize
 * @param original_rect sfFloatRect original size at init
 * @param info paint_t *
 */
void update_resize_text(sfText *text, sfFloatRect original_rect,
    paint_t *info);

/**
 * @brief Resize rect when user resize window
 *
 * @param rect sfRectangleShape *to_resize
 * @param original_rect sfFloatRect original size at init
 * @param info paint_t *
 */
void update_resize_rect(sfRectangleShape *rect, sfFloatRect original_rect,
    paint_t *info);

/**
 * @brief Resize right corner rect for settings when user resize window
 *
 * @param rect sfRectangleShape *rect
 * @param original_rect sfFloatRect
 * @param info paint_t *
 */
void update_resize_rect_right(sfRectangleShape *rect, sfFloatRect original_rect,
    paint_t *info);

void update_resize_text_right(sfText *rect, sfFloatRect original_rect,
    paint_t *info);

void update_resize_text_right_middle(sfText *rect, sfFloatRect original_rect,
    paint_t *info);

void update_resize_rect_right_middle(sfRectangleShape *rect,
    sfFloatRect original_rect, paint_t *info);

/* ================================================
 * src/save_img/init_texture.c
 * ================================================
 */
/**
 * @brief initializes the texture that is used for screenshotting
 * @param info pain_t *
 */
void init_screenshot(paint_t *info);

/* ================================================
 * src/save_img/update_texture_size.c
 * ================================================
 */
/**
 * @brief updates the texture to the size of the canvas
 * in reality frees it and reinitializes it
 * @param info pain_t *
 */
void update_screenshot(paint_t *info);

/* ================================================
 * src/save_img/save_img.c
 * ================================================
 */
/**
 * @brief updates the texture to the size of the canvas
 * in reality frees it and reinitializes it
 * @param info pain_t *
 */
void save_file(paint_t *info);

/**
 * @brief Init a button more centered
 *
 * @param pos sfVector2f pos
 * @param size sfVector2f size
 * @param color sfColor color
 * @return button_t*
 */
button_t *button_init_center(sfVector2f pos, sfVector2f size, sfColor color);

/**
 * @brief Function press left to change size of pencil
 *
 * @param info
 */
void click_size1(paint_t *info);

/**
 * @brief Function press left to change size of pencil
 *
 * @param info
 */
void click_size2(paint_t *info);

/**
 * @brief Function press left to change size of pencil
 *
 * @param info
 */
void click_size3(paint_t *info);

/**
 * @brief Set circle form on pencil's form
 *
 * @param info paint_t *
 */
void click_circle_form(paint_t *info);

/**
 * @brief Set square form on pencil's form
 *
 * @param info paint_t *
 */
void click_square_form(paint_t *info);

/**
 * @brief Remove all layer but keep one
 *
 * @param layer layer_t *layer
 */
void layer_remove_all(layer_t *layer);

/**
 * @brief When clik on new file, delete all layer and create a new one
 *
 * @param info paint_t *
 */
void new_file_press_left(paint_t *info);

/**
 * @brief Open a file
 *
 * @param info paint_t *
 */
void open_file(paint_t *info);

void rightbar_display(paint_t *info);
void gui_button_draw(button_main_t *button, paint_t *info);

#endif /* __MY_PAINT_H__ */
