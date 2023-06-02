/*
** EPITECH PROJECT, 2022
** include
** File description:
** list_texture.h
*/

#ifndef LIST_TEXTURE_H_
    #define LIST_TEXTURE_H_

typedef struct list_element_texture_s {
    struct list_element_texture_s *prev;
    struct list_element_texture_s *next;
    unsigned int index;
    unsigned int is_activ;
    sfTexture *texture;
    sfSprite *sprite;
} list_element_texture_t;

typedef struct list_texture_s {
    list_element_texture_t *first;
    list_element_texture_t *end;
    unsigned int size;
} list_texture_t;

/**
 * @brief Create a list that will contains multiple textures
 *
 * @return list_texture_t*
 */
list_texture_t *list_texture_init(void);

/**
 * @brief Add a texture and a sprite for a list_texture
 *
 * @param list_texture the list of textures concerned
 * @param width of new texture
 * @param height of new texture
 */
void list_texture_add(list_texture_t *list_texture, int width, int height);

/**
 * @brief Remove the first so last element of list_texture
 *
 * @param list_texture The list_texture concerned
 * @param protect If true, doesn't remove an element if size < 2, else remove
 * it. It's to make sure that there's at least one sprite to draw for layer
 */
void list_texture_remove(list_texture_t *list_texture, bool protect);

/**
 * @brief Destroy a list_texture
 *
 * @param list_texture The list_texture concerned
 */
void list_texture_destroy(list_texture_t *list_texture);

/**
 * @brief Find a node of list_texture and set it to activ or not
 *
 * @param list_texture list_texture_t *
 * @param activ True to set activ, and false to set to no activ
 * @param index The index of the node
 */
void list_texture_set_activ(list_texture_t *list_texture, U_INT activ,
U_INT index);

/**
 * @brief Remove all unactiv node of list_texture
 *
 * @param list_texture list_texture_t *
 */
void list_texture_remove_unactiv(list_texture_t *list_texture);

#endif /* LIST_H_TEXTURE_H */
