/*
** EPITECH PROJECT, 2023
** src_struct
** File description:
** src_struct
*/

#ifndef SRC_STRUCT
    #define SRC_STRUCT
    #define QUEST_LIST char *quest[] = {" Quete : \n Sortir de la maison \n", \
    " Quete : \n Examiner le terrain \n "\
    " Quete : \n Examiner le terrain \n", \
    " Quete : \n Trouver Caligula \n"}

    #include <stdbool.h>
    #include "tile.h"
    #include "game_unit.h"
    #include "text_list.h"
    #include "map.h"
struct game_actor_s;
struct game_actor_list_s;
struct npc_s;
struct game_s;
struct inventory_s;

enum quest {
    HOME,
    QUEST2
};

typedef struct skill_tree_s {
    sfRectangleShape **rect;
    bool C_active;
    bool BW_active;
} skill_tree_t;

typedef struct stat_hud_s {

    sfRectangleShape **bars;
    sfSprite *hud;
    double life;
    double lvl;
    double xp;

} stat_hud_t;

typedef struct inventory_s {
    bool *is_case_able;
    sfSprite **content;
    sfRectangleShape **inventory;
} inventory_t;

typedef struct pop_win_s {

    size_t index;
    size_t nb_buttons;
    sfRenderWindow *wd;
    sfRectangleShape **rects;
    sfText **text;
    char *input;
    int idx_text;
} pop_win_t;

typedef struct keyboard_s {

    int UP;
    int DOWN;
    int RIGHT;
    int LEFT;

} keyboard_t;

typedef struct parser_s {
    int type;
    char *name;
    sfVector2f pos_rect;
    sfVector2f pos_text;
    sfVector2f size;
} parser_t;

typedef struct settings_s {
    bool can_draw;
    bool is_on_button;
    sfRectangleShape **rect;
    sfText **text;
} settings_t;

typedef struct menu_s {
    bool is_on_button;
    sfRectangleShape **rect;
    sfText **text;
} menu_t;

typedef struct start_s {
    settings_t *settings;
    menu_t *menu;
} start_t;


typedef struct sound_s {
    sfCircleShape *sound;
    sfCircleShape *music;
    bool check_sound;
    bool check_music;
} sound_t;

typedef struct player_s{
    sfVector2i pos;
    sfTexture *text_player;
    sfSprite *player;
    __u_int animation;
    int load;
    sfIntRect rect;
}player_t;

typedef struct in_game_menu_s {
    bool can_draw;
    bool is_on_button;
    sfRectangleShape **rect;
    sfText **text;
} in_game_menu_t;

typedef struct game_s {
    inventory_t *inv;
    struct npc_s *npc;
    skill_tree_t *skill_t;
    sfClock *clock;
    stat_hud_t *s_hud;
    pop_win_t *m_wd;
    player_t *pl;
    sound_t *sound;
    parser_t *pars;
    sfFont *font;
    sfMusic *main_music;
    start_t *start;
    sfRenderWindow *wd;
    sfEvent event;
    sfVector2i mouse;
    size_t scene;
    void (*g_scene)(struct game_s *gm);
    size_t button_scene;
    grid_t *grid;
    struct game_actor_list_s *ga;
    game_unit_list_t *units;
    text_list_t *list_text;
    enum quest g_quest;
    bool is_skill_tree;
    void (*ga_event)(struct game_s *gm);
    struct game_actor_s *ga_current;
    sfClock *npc_clock;
    sfVector2f delta_move;
    int changing_scene;
    int current_scene;
    bool load;
    char **save;
    bool event_in_progress;
    sfView *view;
    in_game_menu_t *ig_menu;
    bool nihil;
    bool house;
    sfMusic *nihil_song;
    sfMusic *house_song;
    int pos_inv;
    sfRectangleShape *rect_to_play;
} game_t;

/***[HANDLE MAP]***/

/**
 * @brief Handle map init
 *
 * @param gm game_t *
 * @param scene_func function to init map
 */
void map_init(game_t *gm, void (*scene_func)(struct game_s *));

/**
 * @brief Handle help
 *
 */
void handle_help(void);

#endif /* !SRC_STRUCT */
