/*
** EPITECH PROJECT, 2022
** include
** File description:
** layer.h
*/

#ifndef LAYER_H_
    #define LAYER_H_

typedef struct layer_element_s {
    list_texture_t *list_texture;
    struct layer_element_s *prev;
    struct layer_element_s *next;
    int is_activ;
} layer_element_t;

typedef struct layer_s {
    layer_element_t *first;
    layer_element_t *end;
    unsigned int size;
}layer_t ;

/**
 * @brief Init the struct layer which will contains all layers
 * The struct is initialized with one layer
 *
 * @param width of the first layer
 * @param height of the first layer
 *
 * @return layer_t* : linked list which will contains all layers
 * This linked list layer_t * contains layer_element_t *
 * A layer is a struct layer_element_t *
 */
layer_t *layer_init(int width, int height);

/**
 * @brief Add a layer to a struct layer_t *
 *
 * @param layer Struct who contains all layers
 * @param width of the new layer
 * @param height of the new layer
 */
void layer_add(layer_t *layer, int width, int height);

/**
 * @brief Remove the first element of layer_t *layer
 *
 * @param layer struct layer_t *
 * @param protect if true : can't delete if only one layer left
 * if false (when destroying layer for example), can delete the last layer
 */
void layer_remove(layer_t *layer, bool protect);

/**
 * @brief Destroy the struct layer_t *layer
 *
 * @param layer the struct layer_t * to destroy
 */
void layer_destroy(layer_t *layer);

/**
 * @brief Verify if layer changed
 *
 * @param set True to set layer changed == true, false in other case
 * @param get True to only get and not set
 * @return int True if layer has changed, false in other case
 */
int has_layer_changed(int set, int get);

#endif /* LAYER_H_ */
