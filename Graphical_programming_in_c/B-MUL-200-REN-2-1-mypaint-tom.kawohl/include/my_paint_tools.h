/*
** EPITECH PROJECT, 2022
** include
** File description:
** my_paint_tools.h
*/

#ifndef MY_PAINT_TOOLS_H_
    #define MY_PAINT_TOOLS_H_
    #define U_INT unsigned int
    #define SQUARE 1
    #define CIRCLE 2

    #include <stdbool.h>
    #include "layer.h"

/**
 * @brief Struct for pencil tool
 *
 */
typedef struct pencil_s {
    sfUint8 *pixels;
    layer_element_t *current_layer;
    sfVector2f pos;
    sfVector2i limit;
    sfVertex vertex;
    sfVertexArray *lines;
    sfColor color;
    int size;
    bool is_activ;
    bool is_drawing;
    int is_eraser;
    U_INT form;
} pencil_t;

typedef struct tool_s {
    pencil_t *pencil;
} tool_t;

/**
 * @brief Init the tool pencil
 *
 * @param width Is the max width where user can use pencil
 * @param height Is the max height where user can use pencil
 * @param layer Must have at least one layer to be usable
 * @return pencil_t struct
 */
pencil_t *pencil_init(U_INT width, U_INT height, layer_t *layer);

/**
 * @brief Destroy the tool pencil, should do when program is finished
 *
 * @param pencil The struct of the tool pencil
 */
void pencil_destroy(pencil_t *pencil);

/**
 * @brief Update textures of pencil when mouse button is released
 *
 * @param event To check if button is released
 * @param pencil pencil_t *
 */
void pencil_update_release(sfEvent event, pencil_t *pencil);

/**
 * @brief Update if undo : last draw and update texture of pencil
 *
 * @param pencil pencil_t *
 * @param undo To know nb of undo done
 * @param can_undo True if it can undo, false if not
 */
void pencil_undo(pencil_t *pencil, int *undo, int *can_undo);

/**
 * @brief Update if redo : last undo is cancelled
 *
 * @param pencil pencil_t *pencil
 * @param undo Who has to be canceled
 * @param can_redo True if it can redo, false if not
 */
void pencil_redo(pencil_t *pencil, int *undo, int *can_redo);

/**
 * @brief Pencil draw in circle form
 *
 * @param pencil pencil_t *
 * @param i index line to draw
 */
void pencil_add_vertex_circle(pencil_t *pencil, int i);


#endif /* MY_PAINT_TOOL_H_ */
