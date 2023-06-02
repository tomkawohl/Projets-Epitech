/*
** EPITECH PROJECT, 2023
** init_game.c
** File description:
** init game
*/

#include "debug.h"
#include "src.h"
#include "menu.h"
#include "parser.h"
#include "game.h"
#include "stat_hud.h"
#include "skill_tree.h"
#include "npc.h"
#include "game_actor.h"
#include "inventory.h"

static size_t count_nb_lines(char const *buffer)
{
    size_t count = 0;

    for (size_t i = 0; buffer[i]; i++){
        if (buffer[i] == '\n')
            count++;
    }
    return count;
}

static bool game_create(game_t *gm)
{
    int fd = open(HAND_FONT, O_RDONLY);
    sfVideoMode mode = {WIDTH, HEIGHT, 32};

    if (fd == -1)
        return false;
    gm->wd = sfRenderWindow_create(mode, "My_RPG", sfResize | sfClose, NULL);
    gm->scene = MAIN_MENU_SCENE;
    gm->main_music = sfMusic_createFromFile(MAIN_MUSIC);
    gm->font = sfFont_createFromFile(HAND_FONT);
    sfRenderWindow_setFramerateLimit(gm->wd, 60);
    sfMusic_getLoop(gm->main_music);
    sfMusic_play(gm->main_music);
    sfMusic_setVolume(gm->main_music, 100);
    gm->clock = sfClock_create();
    gm->npc_clock = sfClock_create();
    gm->button_scene = 0;
    gm->view = sfView_create();
    gm->house = 0;
    gm->nihil = 0;
    return true;
}

static void create_player(game_t *gm)
{
    sfVector2f origin = {0, 0};

    gm->pl->player = ssl_new_sprite(player_asset,
    (sfVector2f){1, 1}, (sfVector2f){10, 14});
    sfIntRect rect = {0, 650, 65, 60};
    gm->pl->animation = 0;
    gm->pl->load = 0;
    gm->pl->rect = rect;
    sfSprite_setTextureRect(gm->pl->player, rect);
    origin = sfSprite_getPosition(gm->pl->player);
    sfSprite_setOrigin(gm->pl->player, origin);
    gm->nihil_song = NULL;
    gm->house_song = NULL;
    gm->pos_inv = 0;
}

static bool init_structures(game_t *gm)
{
    gm->start = malloc(sizeof(start_t));
    gm->start->menu = malloc(sizeof(menu_t) * NB_BUTTONS_START);
    gm->start->settings = malloc(sizeof(settings_t) * NB_BUTTONS_SETTINGS);
    gm->sound = malloc(sizeof(sound_t));
    gm->pl = malloc(sizeof(player_t));
    gm->m_wd = malloc(sizeof(pop_win_t) * NB_WINDOWS);
    gm->s_hud = malloc(sizeof(stat_hud_t));
    gm->skill_t = malloc(sizeof(skill_tree_t) * NB_SKILLS);
    gm->npc = malloc(sizeof(npc_t) * (NUMBER_NPCS));
    gm->ig_menu = malloc(sizeof(in_game_menu_t) * NB_BUTTONS_IG_MENU);
    gm->inv = malloc(sizeof(inventory_t));
    if (check_malloc(gm->start, "init_game.c")
    || check_malloc(gm->start->menu, "init_game.c")
    || check_malloc(gm->start->settings, "init_game.c")
    || check_malloc(gm->sound, "init_game.c")
    || check_malloc(gm->pl, "init_game.c")
    || check_malloc(gm->pl, "init_game.c")
    || check_malloc(gm->s_hud, "init_game.c"))
        return false;
    return true;
}

int init_game(game_t *gm)
{
    if (init_structures(gm) == false)
        return 84;
    if (game_create(gm) == false)
        return 84;
    create_player(gm);
    init_main_menu(gm, gm->start->menu, gm->font);
    init_settings_menu(gm, gm->font);
    init_skill_tree(gm->skill_t, gm);
    init_stat_hud(gm->s_hud, 100, 50, 100);
    init_how_to_play(gm);
    init_game_data(gm);
    init_stat_hud(gm->s_hud, 100, 0, 0);
    init_inventory(gm);
    return (0);
}
