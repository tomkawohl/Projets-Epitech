/*
** EPITECH PROJECT, 2023
** init_fight
** File description:
** Initialize the fight
*/

#include "fight.h"
#include "src_struct.h"
#include "game_actor.h"

static void malloc_buttons(fight_t *fight)
{
    for (size_t i = 0; i < NB_FIGHT_MENU_BUT; i++) {
        fight->fbut[i] = malloc(sizeof(fight_but_t));
        fight->fbut[i]->rect = malloc(sizeof(sfRectangleShape*) * 3);
        fight->fbut[i]->text = malloc(sizeof(sfText*) * 3);
    }
    for (size_t i = 0; i < NB_ATTACK_BUT; i++) {
        fight->abut[i] = malloc(sizeof(attack_but_t));
        fight->abut[i]->rect = malloc(sizeof(sfRectangleShape*) * 3);
        fight->abut[i]->text = malloc(sizeof(sfText*) * 3);
    }
}

static void malloc_fight_t(fight_t *fight)
{
    fight->background = malloc(sizeof(fight_back_t));
    fight->menu = malloc(sizeof(fight_menu_t));
    fight->fbut = malloc(sizeof(fight_but_t) * NB_FIGHT_MENU_BUT);
    fight->abut = malloc(sizeof(attack_but_t) * NB_ATTACK_BUT);
    fight->texture = malloc(sizeof(sfTexture*) * 3);
    fight->pl = malloc(sizeof(charac_t));
    fight->pl->life_bar = malloc(sizeof(life_bar_t));
    fight->en = malloc(sizeof(charac_t));
    fight->en->life_bar = malloc(sizeof(life_bar_t));
    fight->en_att_frame = malloc(sizeof(size_t) * 4);
    fight->en_att_hp_remov = malloc(sizeof(double) * 3);
    malloc_buttons(fight);
}

static void check_give_item(game_t *gm)
{
    for (size_t i = 0; i < 4; i++){
        if (gm->inv->is_case_able[i] == false){
            gm->inv->is_case_able[i] = true;
            return;
        }
    }
}

void init_fight(game_t *gm)
{
    fight_t *fight = malloc(sizeof(fight_t));
    sfVideoMode mode = {1920, 1080, 32};

    malloc_fight_t(fight);
    set_fight_menu(gm, fight);
    sfView_setCenter(gm->view, (sfVector2f){WIDTH / 2, HEIGHT / 2});
    sfRenderWindow_setView(gm->wd, gm->view);
    while (sfRenderWindow_isOpen(gm->wd)) {
        sfRenderWindow_clear(gm->wd, sfBlack);
        handle_fight_events( gm, fight);
        update_fight(gm->wd, fight);
        sfRenderWindow_display(gm->wd);
        if (fight->is_finished){
            end_fight(gm, fight);
            break;
        }
    }
    check_give_item(gm);
    gm->ga_current->is_activ = false;
    destroy_fight_menu(fight);
}
