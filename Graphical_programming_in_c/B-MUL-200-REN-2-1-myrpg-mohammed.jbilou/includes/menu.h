/*
** EPITECH PROJECT, 2023
** MENU
** File description:
** MENU
*/

#ifndef MENU_H
    #define MENU_H
    #define HAND_FONT "util/FONTS/Blokletters-Viltstift.ttf"
    #define NB_BUTTONS_START 7
    #define NB_BUTTONS_SETTINGS 18
    #define NB_BUTTONS_IG_MENU 4
    #define R_LARGE "util/ASSETS/Large_Buttons/Red_Large_Buttons/button.png"
    #define W_LARGE "util/ASSETS/Large_Buttons/White_Large_Buttons/button.png"
    #define G_LARGE "util/ASSETS/Large_Buttons/Grey_Large_Buttons/button.png"
    #define R_RECT "util/ASSETS/Square_Buttons/Red_rect/"
    #define W_RECT "util/ASSETS/Square_Buttons/White_rect/"
    #define W_AUDIO "util/ASSETS/Square_Buttons/White_rect/audio.png"
    #define R_AUDIO "util/ASSETS/Square_Buttons/Red_rect/audio.png"
    #define W_MUSIC "util/ASSETS/Square_Buttons/White_rect/music.png"
    #define R_MUSIC "util/ASSETS/Square_Buttons/Red_rect/music.png"

    #define MAIN_MENU_SCENE 0
    #define SETTINGS_SCENE 1
    #define IN_GAME_SCENE 2
    #define MAP_EDITOR_SCENE 3
    #define FPS_SCENE 14
    #define RES_SCENE 15
    #define CONTROL_SCENE 16
    #define HOW_TO_PLAY_SCENE 4

    #define START_BUTTON 0
    #define RESUME_BUTTON 1
    #define HELP_BUTTON 2
    #define SETTINGS_BUTTON 3
    #define EDIT_BUTTON 4
    #define HOW_TO_PLAY_BUTTON 5
    #define EXIT_BUTTON 6

    #define FPS_BUTTON 0
    #define RESOLUTION_BUTTON 1
    #define CONTROLS_BUTTON 2
    #define TABLE 3
    #define MUSIC_BUTTON 4
    #define SOUND_BUTTON 5
    #define _30_BUTTON 8
    #define _60_BUTTON 9
    #define _120_BUTTON 10
    #define _1920_1080_BUTTON 11
    #define _Fullscreen_BUTTON 12
    #define UP_BUTTON 13
    #define LEFT_BUTTON 14
    #define DOWN_BUTTON 15
    #define RIGHT_BUTTON 16
    #define BACK_BUTTON NB_BUTTONS_SETTINGS - 1

    #define BACK_MAIN 4
    #define RESUME_BUTTON_IG 0
    #define SETTING_BUTTON_IG 1
    #define SAVE_BUTTON_IG 2
    #define QUIT_BUTTON_IG 3

    #include "src_struct.h"

void set_texture_rect(sfRectangleShape *rect, char const *path);

/*----------------------------------------------------------*/
/*--------------------------[MENU]--------------------------*/
/*----------------------------------------------------------*/
/**
 * @brief inits the main menu and set all the elements
 *
 * @param menu menu_t *
 */
void init_main_menu(game_t *gm, menu_t *menu, sfFont *font);

/**
 * @brief updates all the main menu
 *
 * @param gm game_t *
 */
void update_main_menu(game_t *gm);

/**
 * @brief event in main menu
 *
 * @param gm game_t *
 */
void events_main_menu(game_t *gm);



/*--------------------------------------------------------------*/
/*--------------------------[SETTINGS]--------------------------*/
/*--------------------------------------------------------------*/
/**
 * @brief update the settings main menu
 *
 * @param gm game_t *
 */
void update_settings_menu(game_t *gm);

/**
 * @brief init all the elements in the settings menu
 *
 * @param st settings_t *st
 */
void init_settings_menu(game_t *gm, sfFont *font);

/**
 * @brief handled all the events in the events menu
 *
 * @param gm game_t *
 */
void events_settings_menu(game_t *gm);

/**
 * @brief check the scene how the (FPS, RESOLUTION, CONTROL BUTTONS)
 *
 * @param gm game_t *
 * @param st setting_s *
 */
void check_button_scene(game_t *gm, settings_t *st);

/**
 * @brief moves the circle in the bar for the sound regulator
 *
 * @param sd sound_t *
 * @param gm game_t *
 */
void move_regulator(sound_t *sd, game_t *gm);

/**
 * @brief Set the level of the sound
 *
 * @param sd sound_t *
 * @param gm game_t *
 */
void set_level_sound(sound_t *sd, game_t *gm);

/**
 * @brief check the frames that the user has clicked
 *
 * @param gm game_t *
 * @param st setting_s *
 */
void check_frames_clicked(game_t *gm, settings_t *st);

/**
 * @brief check changes of the window in the settings menu
 *
 * @param gm game_t *
 * @param st setting_s *
 */
void check_when_to_click(game_t *gm, settings_t *st);

/**
 * @brief Handle run of main menu
 *
 * @param gm game_t *
 */
void main_menu_run(struct game_s *gm);



/*--------------------------------------------------------------*/
/*----------------------[HOW TO PLAY]---------------------------*/
/*--------------------------------------------------------------*/
/**
 * @brief init the how to play and init the background
 *
 * @param gm game_t *
 */
void init_how_to_play(game_t *gm);

/**
 * @brief update all element of the how to play
 *
 * @param gm game_t *
 */
void update_how_to_play(game_t *gm);

/**
 * @brief handled the events of how to play
 */
void event_how_to_play(game_t *gm);



/*--------------------------------------------------------------*/
/*----------------------[HOW TO PLAY]---------------------------*/
/*--------------------------------------------------------------*/
/**
 * @brief init the how to play and init the background
 *
 * @param gm game_t *
 */
void init_how_to_play(game_t *gm);

/**
 * @brief update all element of the how to play
 *
 * @param gm game_t *
 */
void update_how_to_play(game_t *gm);

/**
 * @brief handled the events of how to play
 */
void event_how_to_play(game_t *gm);



/*--------------------------------------------------------------*/
/*----------------------[HOW TO PLAY]---------------------------*/
/*--------------------------------------------------------------*/
/**
 * @brief init the how to play and init the background
 *
 * @param gm game_t *
 */
void init_how_to_play(game_t *gm);

/**
 * @brief update all element of the how to play
 *
 * @param gm game_t *
 */
void update_how_to_play(game_t *gm);

/**
 * @brief handled the events of how to play
 */
void event_how_to_play(game_t *gm);


bool init_ig_menu(game_t *gm, sfFont *font);
void update_ig_menu(game_t *gm);
int events_ig_menu(game_t *gm);
#endif /* MENU_H */
