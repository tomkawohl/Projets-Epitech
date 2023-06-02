/*
** EPITECH PROJECT, 2023
** include
** File description:
** map.h
*/

#ifndef MAP_H_
    #define MAP_H_

    #define SCENE_MAP const char *scene_map[] = {"map/house/room.txt",\
        "map/house/room2.txt", "map/house/midlayer.txt",\
        "map/house/undergr.txt", "map/house/outside.txt",\
        "map/nihil/nihil.txt", NULL}

    #define DEFAULT_SCENE const char *default_map[] = {\
        "save/map_default/room_save.txt", "save/map_default/room2_save.txt",\
        "save/map_default/midlayer_save.txt",\
        "save/map_default/undergr_save.txt",\
        "save/map_default/outside_save.txt", \
        "save/map_default/nihil_save.txt", NULL}

    #define CURRENT_SCENE const char *current_map[] = {\
        "save/map_current/room_save.txt", "save/map_current/room2_save.txt",\
        "save/map_current/midlayer_save.txt",\
        "save/map_current/undergr_save.txt",\
        "save/map_current/outside_save.txt",\
        "save/map_current/nihil_save.txt", NULL}

    #define SCENE_SAVE const char *save_map[] = {"save/map/room_save.txt",\
        "save/map/room2_save.txt", "save/map/midlayer_save.txt",\
        "save/map/undergr_save.txt", "save/map/outside_save.txt",\
        "save/map/nihil_save.txt", NULL}

    typedef void (*scene_func)(struct game_s *);
    #define SCENE_FUNCTIONS scene_func handle_scene[] = {room_init, room2_init,\
        midlayer_init, undergr_init, outside_init, nihil_init}

    #define ROOM 0
    #define ROOM2 1
    #define MIDLAYER 2
    #define UNDERGR 3
    #define OUTSIDE 4
    #define NIHIL 5

    #include <SFML/Graphics.h>
struct game_s;

/**
 * @brief change  a scene
 *
 * @param gm game_t *
 */
void scene_change(struct game_s *gm);

/**
 * @brief Handle event of a map
 *
 * @param gm game_t *gm
 * @param event sfEvent
 */
bool map_event(struct game_s *gm, sfEvent event);

/**
 * @brief Run a map
 *
 * @param gm game_t *
 */
void map_run(struct game_s *gm);

/**
 * @brief Update data of a map
 *
 * @param gm game_t *
 */
void map_update(struct game_s *gm);

/**
 * @brief Draw a map
 *
 * @param gm game_t *
 */
void map_draw(struct game_s *gm);

/**
 * @brief Init room map
 *
 * @param gm game_t *
 * @param events char **events of the map
 */
void room_init(struct game_s *gm);

/**
 * @brief Init room2
 *
 * @param gm game_t *
 * @param events char **
 */
void room2_init(struct game_s *gm);

/**
 * @brief Handle interaction of book for room2
 *
 * @param gm struct game_s
 */
void room2_interact_book(struct game_s *gm);

/**
 * @brief Reset data of current scène.
 *
 */
void reset_current_save(void);

/**
 * @brief Replace data on a line of a current scene
 *
 * @param save char **save of gm->save
 * @param find the line of data to replace
 * @param to_replace the new data to give, ADD \n at end of replace!
 */
void replace_save_find(char **save, char *find, char *to_replace);

/**
 * @brief Save pos on the player when leaving a scène
 *
 * @param gm game_t *
 */
void save_pos(struct game_s *gm);

/**
 * @brief Get position of player in gm->save
 *
 * @param save char **save of gm->save
 * @param find The line of data to get
 * @return u_int
 */
u_int save_find(char **save, char *find);

/**
 * @brief Update idx title, go to arguments
 *
 * @param str char *
 * @param i u_int *, is the idx concerned
 */
void update_idx_title(char *str, u_int *i);

/**
 * @brief Get the pos destined to the player with save map
 *
 * @param gm game_t *gm
 */
void handle_save_pos(struct game_s *gm);

/**
 * @brief Hande chest interact to room2
 *
 * @param gm game_t *gm
 */
void room2_interact_chest(struct game_s *gm);

/**
 * @brief Init midlayer
 *
 * @param gm game_t *
 */
void midlayer_init(struct game_s *gm);

/**
 * @brief Handle event for midlayer
 *
 * @param gm game_t *
 */
void midlayer_event(struct game_s *gm);

/**
 * @brief Handle interaction to go to midlayer
 *
 * @param gm game_t *gm
 */
void room_interact_go_midlayer(struct game_s *gm);

/**
 * @brief Init undergr room
 *
 * @param gm game_t *
 */
void undergr_init(struct game_s *gm);

/**
 * @brief Handl event for undergr
 *
 * @param gm game_t *
 */
void undergr_event(struct game_s *gm);

/**
 * @brief Handle interact to go to undergr
 *
 * @param gm game_t *
 */
void midlayer_interact_go_undergr(struct game_s *gm);

/**
 * @brief Handle interact to go to midlayer
 *
 * @param gm game_t *
 */
void undergr_interact_go_midlayer(struct game_s *gm);

/**
 * @brief Handle interact to go to room
 *
 * @param gm game_t *
 */
void midlayer_interact_go_room(struct game_s *gm);

/**
 * @brief Handle interact to go to outside
 *
 * @param gm game_t *
 */
void midlayer_interact_go_outside(struct game_s *gm);

/**
 * @brief Handle event for outisde
 *
 * @param gm game_t *
 */
void outside_event(struct game_s *gm);

/**
 * @brief Init outside
 *
 * @param gm game_t *
 */
void outside_init(struct game_s *gm);

/**
 * @brief Handle interaction to go to outside
 *
 * @param gm game_t *
 */
void outside_interact_go_midlayer(struct game_s *gm);

/**
 * @brief Handle npc of outside
 *
 * @param gm game_t *
 */
void outside_interact_npc(struct game_s *gm);

/**
 * @brief Handle event for nihil
 *
 * @param gm game_t *
 */
void nihil_event(struct game_s *gm);

/**
 * @brief Init nihil
 *
 * @param gm game_t *
 */
void nihil_init(struct game_s *gm);

/**
 * @brief Handle interaction to go to nihil
 *
 * @param gm game_t *
 */
void outside_interact_go_nihil(struct game_s *gm);

/**
 * @brief Handle interact for nihil book
 *
 * @param gm game_t *
 */
void nihil_interact_book(struct game_s *gm);

/**
 * @brief Handle interact for npc in nihil
 *
 * @param gm game_t *
 */
void nihil_interact_npc(struct game_s *gm);

#endif /* MAP_H_ */
