/*
** EPITECH PROJECT, 2023
** fight_h
** File description:
** d
*/

#ifndef FIGHT_H_
    #define FIGHT_H_
    #include <stdbool.h>
    #include "src.h"
    #include "menu.h"
    #include "collisions.h"
    #include "game_actor.h"

    static const sfColor GREY = {70, 70, 70, 255};

    #define FIGHT_BACKGROUND "util/ASSETS/fight/background.png"
    #define FIGHT_MENU "util/ASSETS/fight/menu.png"
    #define CHAR_SPRITE "util/ASSETS/Character_assets/player_assets.png"
    #define PLAYER_SPRITE "util/ASSETS/fight/player_assets.png"
    #define SKELETTON_SPRITE "util/ASSETS/fight/skeleton_enemy.png"
    #define MINOTAUR_SPRITE "util/ASSETS/fight/minotaur_enemy.png"
    #define LIFE_BAR "util/ASSETS/fight/life_bar.png"

    #define INDEX_WHITE 0
    #define INDEX_RED 1
    #define INDEX_GREY 2

    #define NB_FIGHT_MENU_BUT 2
    #define FIGHT_BUT 0
    #define RUN_BUT 1

    #define NB_ATTACK_BUT 5
    #define ATT_ONE_BUT 0
    #define ATT_TWO_BUT 1
    #define ATT_THRE_BUT 2
    #define ATT_FOUR_BUT 3
    #define GO_BACK_BUT 4

static const Vect2f FIGHT_MENU_POS = {485, 680};
static const Vect2f FIGHT_MENU_BUT_SIZE = {400, 200};
static const Vect2f FIGHT_MENU_BUT_FONT_SCALE = {1.5, 1.5};
static const Vect2f FIGHT_BUT_POS = {535, 730};
static const Vect2f FIGHT_FONT_POS = {566, 804};
static const Vect2f RUN_BUT_POS = {985, 730};
static const Vect2f RUN_FONT_POS = {1110, 804};

static const Vect2f ATT_BUT_SIZE = {425, 100};
static const Vect2f ATT_FONT_SIZE = {1, 1};
static const Vect2f GO_BACK_FONT_SIZE = {0.5, 0.5};
static const Vect2f GO_BACK_BUT_SIZE = {220, 50};
static const Vect2f ATT_ONE_POS = {525, 700};
static const Vect2f ATT_ONE_FONT_POS = {605, 733};
static const Vect2f ATT_TWO_POS = {960, 700};
static const Vect2f ATT_TWO_FONT_POS = {1075, 733};
static const Vect2f ATT_THRE_POS = {525, 810};
static const Vect2f ATT_THREE_FONT_POS = {570, 843};
static const Vect2f ATT_FOUR_POS = {960, 810};
static const Vect2f ATT_FOUR_FONT_POS = {1025, 843};
static const Vect2f GO_BACK_POS = {850, 920};
static const Vect2f GO_BACK_FONT_POS = {915, 936};

static const Vect2f PLAYER_POS = {430, 365};
static const Vect2f PLAYER_SCALE = {5, 5};
static const Vect2f PL_LIFE_HUD_POS = {450, 320};
static const Vect2f PL_LIFE_HUD_SCALE = {0.5, 0.5};
static const Vect2f PL_LIFE_BAR_POS = {480, 329};
static const int pl_sprite_left[9] = {0, 68, 136, 204, 272, 340, 408, 476,
    544};
static const int pl_attack_top[4] = {100, 150, 200, 250};

static const Vect2f ENEMY_POS = {1190, 315};
static const Vect2f ENEMY_SCALE = {5, 5};
static const Vect2f EN_LIFE_HUD_POS = {1290, 320};
static const Vect2f EN_LIFE_HUD_SCALE = {0.5, 0.5};
static const Vect2f EN_LIFE_BAR_POS = {1320, 329};
static const double en_sprite_left[12] = {0, 90, 180, 270, 360, 450, 540, 630,
    720, 810, 900, 990};
static const int en_attack_top[3] = {140, 210, 280};

typedef struct fight_background {
    sfSprite *sprite;
    sfTexture *texture;
} fight_back_t;

typedef struct fight_menu {
    sfSprite *sprite;
    sfTexture *texture;
} fight_menu_t;

typedef struct fight_but {
    bool is_on_button;
    sfRectangleShape **rect;
    sfText **text;
} fight_but_t;

typedef struct attack_but {
    bool is_on_button;
    bool is_active;
    sfRectangleShape **rect;
    sfText **text;
    size_t att_frame;
    double hp_remove;
    size_t cooldown;
} attack_but_t;

typedef struct life_bar {
    sfSprite *sprite;
    sfTexture *texture;
    sfRectangleShape *rect;
} life_bar_t;

typedef struct character {
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
    double life;
    life_bar_t *life_bar;
    size_t move_frame;
    bool is_dead;
    size_t dead_frame;
} charac_t;

typedef struct fight {
    sfEvent event;
    sfVector2i mouse;
    fight_back_t *background;
    fight_menu_t *menu;
    fight_but_t **fbut;
    attack_but_t **abut;
    sfTexture **texture;
    charac_t *pl;
    charac_t *en;
    size_t *en_att_frame;
    double *en_att_hp_remov;
    bool is_attacking;
    bool has_pl_attacked;
    bool has_charac_died;
    bool is_finished;
    bool has_pl_win;
} fight_t;

/**
 * @brief Initializes a fight
 * @param gm
 */
void init_fight(game_t *gm);

/**
 * @brief Sets the fight menu object
 * @param gm
 * @param fight
 */
void set_fight_menu(game_t *gm, fight_t *fight);

/**
 * @brief Set the fight player object
 * @param pl
 * @param pl_life
 */
void set_player(charac_t *pl, double pl_life);

/**
 * @brief Set the fight enemy object
 * @param en
 */
void set_enemy(game_t *gm, fight_t *fight, charac_t *en);

/**
 * @brief Defines a new sfText object for fight menu buttons
 * @param font
 * @param but_ind
 * @param color_ind
 * @return sfText*
 */
sfText *new_fight_menu_text(sfFont *font, size_t but_ind, size_t color_ind);

/**
 * @brief Defines a new sfText object for attack buttons
 * @param font
 * @param but_ind
 * @param color_ind
 * @return sfText*
 */
sfText *new_attack_text(sfFont *font, size_t but_ind, size_t color_ind);

/**
 * @brief Handles events when the player is in fight
 * @param gm
 * @param fight
 */
void handle_fight_events(game_t *gm, fight_t *fight);

/**
 * @brief Detects if the mouse is on a button from fight menu
 * and if the button is clicked
 * @param mouse
 * @param fight
 */
void is_mouse_on_menu_but(game_t *gm, sfVector2i mouse, fight_t *fight);

/**
 * @brief Detects if the mouse is on an attack button
 * and if the button is clicked
 * @param mouse
 * @param fight
 */
void is_mouse_on_attack_but(game_t *gm, sfVector2i mouse, fight_t *fight);

/**
 * @brief Updates the fight
 * @param gm
 * @param fight
 */
void update_fight(sfRenderWindow *wd, fight_t *fight);

/**
 * @brief Destroys and frees a fight_t object
 * @param fight
 */
void destroy_fight_menu(fight_t *fight);

/**
 * @brief Moves the player before attacking
 * @param fight
 * @param i
 */
void move_pl(fight_t *fight, size_t i);

/**
 * @brief Moves the enemy before attacking
 * @param fight
 * @param i
 */
void move_en(fight_t *fight, size_t i);

/**
 * @brief Animates player attacks
 * @param fight
 * @param i
 */
void animate_pl_attack(fight_t *fight, size_t i);

/**
 * @brief Animates enemy attacks
 * @param fight
 * @param i
 */
void animate_en_attack(fight_t *fight, size_t i);

/**
 * @brief Updates health points for player and enemy
 * @param fight
 * @param index
 * @param charac
 */
void update_hp(fight_t *fight, size_t index, size_t charac);

/**
 * @brief Updates the cooldowns for player attack
 * @param fight
 * @param index
 */
void update_attack_cooldown(fight_t *fight, size_t index);

/**
 * @brief Animates the dead of the player
 * @param fight
 */
void animate_pl_die(fight_t *fight);

/**
 * @brief Animates the dead of the enemy
 * @param fight
 */
void animate_en_die(fight_t *fight);

/**
 * @brief Ends a fight
 * @param fight
 */
void end_fight(game_t *gm, fight_t *fight);

#endif /* !FIGHT_H_ */
