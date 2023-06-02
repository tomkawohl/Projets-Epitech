/*
** EPITECH PROJECT, 2023
** update_fight
** File description:
** Updates the fight
*/

#include "fight.h"

static void update_fight_menu_but(sfRenderWindow *wd, fight_but_t **but)
{
    for (size_t i = 0; i < NB_FIGHT_MENU_BUT; i++) {
        if (but[i]->is_on_button) {
            sfRenderWindow_drawRectangleShape(wd, but[i]->rect[1], NULL);
            sfRenderWindow_drawText(wd, but[i]->text[1], NULL);
        } else {
            sfRenderWindow_drawRectangleShape(wd, but[i]->rect[0], NULL);
            sfRenderWindow_drawText(wd, but[i]->text[0], NULL);
        }
    }
}

static void toggle_but_activation(attack_but_t **but)
{
    for (size_t i = 0; i < NB_ATTACK_BUT; i++) {
        if (but[i]->cooldown > 0) {
            but[i]->is_active = false;
        } else {
            but[i]->is_active = true;
        }
    }
}

static void update_attack_but(sfRenderWindow *wd, attack_but_t **but,
    bool has_pl_attacked, bool has_charac_died)
{
    for (size_t i = 0; i < NB_ATTACK_BUT; i++) {
        if (!but[i]->is_active || has_pl_attacked || has_charac_died) {
            sfRenderWindow_drawRectangleShape(wd, but[i]->rect[2], NULL);
            sfRenderWindow_drawText(wd, but[i]->text[2], NULL);
            continue;
        }
        if (but[i]->is_on_button && but[i]->is_active) {
            sfRenderWindow_drawRectangleShape(wd, but[i]->rect[1], NULL);
            sfRenderWindow_drawText(wd, but[i]->text[1], NULL);
        }
        if (!but[i]->is_on_button && but[i]->is_active) {
            sfRenderWindow_drawRectangleShape(wd, but[i]->rect[0], NULL);
            sfRenderWindow_drawText(wd, but[i]->text[0], NULL);
        }
    }
}

static void update_life_bars(sfRenderWindow *wd, charac_t *pl, charac_t *en)
{
    double player_life = 120 * pl->life / 100;
    double enemy_life = 120 * en->life / 100;

    sfRectangleShape_setSize(pl->life_bar->rect, (Vect2f){player_life, 11});
    sfRectangleShape_setSize(en->life_bar->rect, (Vect2f){enemy_life, 11});
    sfRenderWindow_drawRectangleShape(wd, pl->life_bar->rect, NULL);
    sfRenderWindow_drawRectangleShape(wd, en->life_bar->rect, NULL);
}

void update_fight(sfRenderWindow *wd, fight_t *fight)
{
    sfRenderWindow_drawSprite(wd, fight->background->sprite, NULL);
    sfRenderWindow_drawSprite(wd, fight->menu->sprite, NULL);
    if (!fight->is_attacking) {
        update_fight_menu_but(wd, fight->fbut);
    } else {
        toggle_but_activation(fight->abut);
        update_attack_but(wd, fight->abut, fight->has_pl_attacked,
            fight->has_charac_died);
    }
    sfRenderWindow_drawSprite(wd, fight->pl->sprite, NULL);
    sfRenderWindow_drawSprite(wd, fight->pl->life_bar->sprite, NULL);
    sfRenderWindow_drawSprite(wd, fight->en->sprite, NULL);
    sfRenderWindow_drawSprite(wd, fight->en->life_bar->sprite, NULL);
    update_life_bars(wd, fight->pl, fight->en);
}
