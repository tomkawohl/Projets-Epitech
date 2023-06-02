/*
** EPITECH PROJECT, 2023
** include
** File description:
** map_editor.h
*/

#ifndef MAP_EDITOR_H_
    #define MAP_EDITOR_H_
    #include <SFML/Graphics.h>
    #include "asset.h"
    #include "tile.h"
    #include "tile_coord_set.h"
    #include "text_list.h"
    #include "game_unit.h"
    #define CURSOR_ASSET "util/ASSETS/cursor/cursor.png"

    #define E_B_COLOR 84, 84, 84
    #define E_B_HOVER 44, 44, 44
    #define NB_WINDOWS 3


    #define CURSOR_SELECTED (sfIntRect){    \
        32, 48, 16, 16  \
        }
    #define CURSOR_TILE (sfIntRect){    \
        0, 48, 16, 16   \
        }
    #define COLISION_EDIT (sfIntRect){  \
        64, 32, 16, 16  \
        }
    #define NB_BUTTON_EDIT 9
    #define NB_SET 19
    #define SET_POS_Y 35
    #define GRID_X 30
    #define GRID_Y 17
    #define CANVA_X 385
    #define CANVA_Y 35
    #define COORD_DEL "/"
    #define COORD_DEL_CHAR '/'
    #define TILE_DEL ";"
    #define TILE_DEL_CHAR ';'
    #define COL_DEL ":"
    #define COL_DEL_CHAR ':'
    #define ENTRY "\n"
    #define C_SIZE_X (TILE_SIZE * GRID_X)
    #define C_SIZE_Y (TILE_SIZE * GRID_Y)

struct map_edit_s;
enum map_edit_state {
    DEFAULT,
    ADD,
    COLLISION,
    DELETE,
    NEW,
    OPEN,
    SAVE,
    UNIT,
    UNIT_DELETE,
    EXIT
};

typedef struct button_edit_s {
    bool mouseOn;
    sfRectangleShape **rect;
    sfText **text;
    sfFont *font;
    sfColor color;
    void (*pressed_left)(struct map_edit_s *);
} button_edit_t ;

typedef struct edit_object_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2i pos;
    struct edit_object_s *next;
} edit_object_t ;

typedef struct list_edit_obj_s {
    edit_object_t *first;
    u_int size;
} list_edit_obj_t;

typedef struct set_s {
    sfTexture *texture;
} set_t;

typedef struct tile_pos_set_s {
    char **tile_pos;
} tile_pos_set_t;

typedef struct map_edit_s {
    char *file_to_open;
    grid_t *grid;
    set_t *set;
    u_int set_nb;
    sfSprite *set_sprite;
    button_edit_t *buttons;
    enum map_edit_state state;
    edit_object_t selected;
    edit_object_t tile_place;
    bool set_is_activ;
    sfVector2i tile_coord_select;
    list_edit_obj_t *list_col;
    tile_pos_set_t *tiles_pos_set;
    sfVector2f delta_move;
    text_list_t *list_text;
    game_unit_list_t *units;
} map_edit_t;

/**
 * @brief Handle map editor
 *
 * @param win gm->wd
 */
void map_editor(sfRenderWindow* win, game_t *gm);

/**
 * @brief Init the struct for the map editor
 *
 * @return map_edit_t*
 */
map_edit_t *map_editor_init(void);

/**
 * @brief Draw all element of map_editor
 *
 * @param win sfRenderWindow *win
 * @param map_edit map_edit_t *
 */
void map_editor_draw(sfRenderWindow *win, map_edit_t *map_edit);

/**
 * @brief Destroy the struct map_edit
 *
 * @param map_edit map_edit_t *
 */
void map_edit_destroy(map_edit_t *map_edit);

/**
 * @brief Create a simple button for map edit
 *
 * @param pos Of the button
 * @param size Of the button
 * @param name Of the button
 * @return button_edit_t
 */
button_edit_t e_button_create(button_edit_t button, sfVector2f pos,
sfVector2f size, char *name);

/**
 * @brief Destroy all buttons of map edit
 *
 * @param button button_edit_t *
 * @param limit The nb of button of map edit
 */
void e_button_destroy_all(button_edit_t *button, u_int limit);

/**
 * @brief Draw all button of map_editor
 *
 * @param win sfRenderWindow *win
 * @param buttons button_edit_t *buttons
 */
void e_button_draw_all(sfRenderWindow *win, button_edit_t *buttons);

/**
 * @brief handle event for map_editor
 *
 * @param win
 * @param event
 * @param map_edit
 */
void map_editor_handle_event(game_t *gm, map_edit_t *map_edit);

/**
 * @brief Place a tile if user click on canva
 *
 * @param map_edit map_edit_t *
 * @param mouse sfMouseButtonEvent
 */
void map_editor_update_grid(map_edit_t *map_edit, sfMouseButtonEvent *mouse);

/**
 * @brief Save a map
 *
 * @param map_edit map_edit_t * which contains info of map
 * @param name the name of the tile to save
 */
void map_editor_save_grid(map_edit_t *map_edit, char *name);

/**
 * @brief If ctrl + s is pressed, do save_grid
 *
 * @param map_edit map_edit_t *
 * @param event sfEvent
 * @param can_press bool *
 */
void save_grid_event(map_edit_t *map_edit, sfEvent event, bool *can_press);

/**
 * @brief Create a list edit_object_t *
 *
 * @return list_edit_obj_t*
 */
list_edit_obj_t *edit_obj_create(void);

/**
 * @brief Add an element edit_object_t to a list
 *
 * @param list list_edit_obj_t *
 * @param coord of the new element, it's the tile's grid pos
 * @param area should be COLISION_EDIT
 * @param map_edit map_edit_t * to recup delta if user moved canva
 */
void edit_obj_add(list_edit_obj_t *list, sfVector2i coord, sfIntRect area,
    map_edit_t *map_edit);

/**
 * @brief Find a object_edit_t element by his pos
 *
 * @param list list_edit_obj_t *
 * @param coord Of the tile's grid concerned
 * @return edit_object_t*
 */
edit_object_t *edit_obj_get(list_edit_obj_t *list, sfVector2i coord);

/**
 * @brief Remove the last element of list
 *
 * @param list list_edit_obj_t *
 */
void edit_obj_remove(list_edit_obj_t *list);

/**
 * @brief Remove a edit obj find by his pos
 *
 * @param list list_edit_obj_t *
 * @param coord sfVector2i
 */
void edit_obj_remove_get(list_edit_obj_t *list, sfVector2i coord);

/**
 * @brief Draw all element of a list edit_obj
 *
 * @param win sfRenderWindow *win
 * @param list list_edit_obj_t
 */
void edit_obj_draw(sfRenderWindow *win, list_edit_obj_t *list);

/**
 * @brief Destroy a list of edit_obj
 *
 * @param list list_edit_obj_t
 */
void edit_obj_destroy(list_edit_obj_t *list);

/**
 * @brief Clear a list of edit_obj
 *
 * @param list list_edit_obj_t *
 */
void edit_obj_clear(list_edit_obj_t *list);

/**
 * @brief Add colision to a tile
 *
 * @param map_edit map_edit
 * @param coord sfVector2i
 */
void m_e_tile_add_colision(map_edit_t *map_edit, sfVector2i coord);

/**
 * @brief Handle event of colision in map_edit
 *
 * @param map_edit map_edit_t *
 * @param mouse sfMouseButtonEvent *
 */
void map_editor_col_event(map_edit_t *map_edit, sfMouseButtonEvent *mouse);

/**
 * @brief Update tools selection, A for ADD, C for COLISSION
 *
 * @param map_edit map_edit_t *
 * @param event sfEvent
 * @param can_press bool *
 */
void update_tools_selection(map_edit_t *map_edit, sfEvent event,
    bool *can_press);

/**
 * @brief Get the map data object when open a map
 *
 * @param file const char *
 * @return char**
 */
char **get_map_data(const char *file);

/**
 * @brief Create a map from a txt.map file
 *
 * @param file txt.map
 * @return grid_t*
 */
grid_t *file_to_map(const char *file, bool is_map_editor);

/**
 * @brief Handle event open
 *
 * @param map ma_edit_t *
 * @param event sfEvent event
 * @param can_press bool *
 */
void open_file_map_event(map_edit_t *map, sfEvent event, bool *can_press);

/**
 * @brief Get input for save and open event
 *
 * @param is_open_event Say true if it's an open event (verify extension .map)
 * @return char*
 */
char *file_get_input(bool is_open_event);

/**
 * @brief Open a file in map_editor func
 *
 * @param map_edit map_edit_t *
 * @return grid_t* give it to map_edit->grid
 */
grid_t *open_file_map(map_edit_t *map_edit);

/**
 * @brief Update colision of a map open
 *
 * @param map_edit map_edit_t *
 */
void update_colision(map_edit_t *map_edit);

/**
 * @brief Swap the set of tile when user use arrow or num
 *
 * @param map_edit map_edit_t *
 * @param event sfEvent
 * @param can_press bool *
 */
void swap_set_event(map_edit_t *map_edit, sfEvent event, bool *can_press);

/**
 * @brief Init tile_pos_set : is the coord of texture in a set.
 *
 * @param limit sfVector2i, limit of the grid
 * @return tile_pos_set_t*
 */
tile_pos_set_t *tile_pos_set_init(sfVector2i limit);

/**
 * @brief Add information to tile_pos_set : call this when use tile_set func
 *
 * @param tile struct tile_pos_set_t
 * @param info coord of tile in set, nb set
 * @param pos pos of the tile in grid
 * @param limit limit of grid
 */
void tile_pos_set_add(tile_pos_set_t *tile, info_tile_t info,
sfVector2i pos, sfVector2i limit);

/**
 * @brief Update idx arg, is a helper for file_to_map
 *
 * @param str char *
 * @param idx_arg u_int *
 */
void update_idx_arg(char *str, u_int *idx_arg);

/**
 * @brief Get limit of a grid checking map_data info
 *
 * @param map_data char **
 * @return sfVector2i limit
 */
sfVector2i get_limit(char **map_data);

/**
 * @brief Destroy a tile_pos_set struct
 *
 * @param tile_pos tile_pos_set_t *
 * @param limit sfVector2i
 */
void destroy_tile_pos_set(tile_pos_set_t *tile_pos, sfVector2i limit);

/**
 * @brief Update tile_pos_set when open a new map
 * note : it update also canvas
 *
 * @param prev current tile_pos_set
 * @param file file_name
 * @param limit limit of current grid
 * @param map_edit_t *, it also update canva size
 * @return tile_pos_set_t*
 */
tile_pos_set_t *tile_pos_set_update(tile_pos_set_t *prev, const char *file,
    sfVector2i limit, map_edit_t *map_edit);

/**
 * @brief Delete a tile when user click on it
 *
 * @param map_edit map_edit *
 * @param mouse sfMouseButtonEvent
 */
void delete_event(map_edit_t *map_edit, sfMouseButtonEvent *mouse);

/**
 * @brief Update the place of the tile on screen
 *
 * @param map_edit map_edit_t *
 * @param mouse sfMouseMoveEvent *
 */
void update_tile_place(map_edit_t *map_edit, sfMouseMoveEvent *mouse);

/**
 * @brief Hide set on the screen
 *
 * @param map_edit map_edit_t *
 * @param event sfEvent
 * @param can_press bool *
 */
void hide_set(map_edit_t *map_edit, sfEvent event, bool *can_press);

/**
 * @brief Update tile selected on set
 *
 * @param map_edit map_edit_t *
 * @param mouse sfMouseButtonEvent *
 */
void update_selected(map_edit_t *map_edit, sfMouseButtonEvent *mouse);

/**
 * @brief Update map edit when open a new map
 *
 * @param map_edit map_edit_t *
 * @param input char *
 */
void update_map_edit_open(map_edit_t *map_edit, char *input);

/**
 * @brief Handle screen for map_editor
 *
 * @param win sfRenderWindow *
 * @param map_edit map_edit_t *
 */
void map_editor_handle_screen(sfRenderWindow *win, map_edit_t *map_edit);

/**
 * @brief Ask user if he really want to quit
 *
 * @return true if he type yes
 * @return false if he type no
 */
bool map_editor_exit(void);

/**
 * @brief Create a new grid, user choose dimensions
 *
 * @param map_edit map_edit_t *
 * @param can_press bool *
 */
void new_grid_event(map_edit_t *map_edit, bool *can_press);

/**
 * @brief Move view when user use z q s d
 *
 * @param map_edit map_edit_t *
 * @param can_press bool *
 */
void handle_view_event(map_edit_t *map_edit, bool *can_press);


/**
 * @brief init window when we click on any map editor button
 *
 * @param name char const *
 * @param nb_buttons size_t
 * @param size sfVecot2u
 * @return pop_win_t
 */
pop_win_t init_info_pop_win(pop_win_t m_wd , char const *name,
                            size_t nb_buttons, sfVector2u size);

/**
 * @brief Create a new window object
 *
 * @param gm game_t *
 * @param m_wd pop_win_t
 * @param filepath char const *
 */
void create_new_window(game_t *gm, pop_win_t m_wd, char const *filepath,
                        map_edit_t *map_edit);

/**
 * @brief events for the windows popup
 *
 * @param m_wd pop_win_t
 * @param event sfEvent
 */
pop_win_t events_pop_up(pop_win_t m_wd, sfEvent event, map_edit_t *map_edit);

/**
 * @brief update buttons
 *
 * @param m_wd
 */
void update_buttons_window(pop_win_t m_wd);

/**
 * @brief init buttons to click on map editor
 *
 * @return button_edit_t*
 */
button_edit_t *map_editor_button_init(void);

/**
 * @brief Init list text for map edit
 *
 * @return text_list_t*
 */
text_list_t *map_edit_list_text_init(void);

/**
 * @brief Change the state of map_edit
 *
 * @param map_edit map_edit_t *
 * @param state state desired
 */
void map_edit_change_state(map_edit_t *map_edit, int state);

/**
 * @brief Swap set of tile set
 *
 * @param map_edit map_edit_t *
 * @param dir 1 to swap set on left, other number than 1 in other case
 */
void swap_set(map_edit_t *map_edit, int dir);

/**
 * @brief Handle map_edit_unit event : foreground sprites
 *
 * @param map_edit map_edit_t *
 * @param mouse sfMouseButtonEvent *
 */
void map_edit_unit_event(map_edit_t *map_edit, sfMouseButtonEvent *mouse);

/**
 * @brief Add data of a foreground sprite to map_edit->unit_pos_set
 *
 * @param info game_unit_info_t
 *
 * @return char *, git it to map_edit->unit_pos_set
 */
char *unit_pos_set_add(game_unit_info_t info);

/**
 * @brief Handle delete a game_unit_t * event
 *
 * @param map_edit map_edit_t *
 * @param mouse sfMouseButtonEvent *
 */
void map_edit_unit_delete_event(map_edit_t *map_edit,
    sfMouseButtonEvent *mouse);

/**
 * @brief Init game_unit_list by a file.map
 *
 * @param file example file.map
 * @return game_unit_list_t*
 */
game_unit_list_t *file_to_map_unit(const char *file);

/**
 * @brief Destroy prev ressource when open a map
 *
 * @param map_edit map_edit_t *
 */
void open_destroy_ressources(map_edit_t *map_edit);


/**
 * @brief creates and new grid
 *
 * @param map_edit
 */
void new_grid(map_edit_t *map_edit, char *input);



/**
 * @brief get click bool
 *
 * @param win
 * @param mouse
 * @param can_write
 * @return true
 * @return false
 */
bool get_click(pop_win_t win, sfVector2i mouse, bool can_write);

/**
 * @brief text handled for pop up windows
 *
 * @param win
 * @param event
 * @return pop_win_t
 */
pop_win_t text_handler(pop_win_t win, sfEvent event);

/**
 * @brief check if file exists so the window can close
 *
 * @param edit
 * @return true
 * @return false
 */
bool can_close_open_window(map_edit_t *edit);

/**
 * @brief Init tile set of map editor
 *
 * @return set_t*
 */
set_t *map_editor_init_set(void);

#endif /* MAP_EDITOR_H_ */
