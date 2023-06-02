/*
** EPITECH PROJECT, 2022
** src
** File description:
** init_element
*/
#include "src.h"

/* calcul_angle in commentary, i need to update collision's calcul */
void init_plane(object_t **planes, int i, char **map_info, int *j)
{
    while (map_info[*j][0] != 'A' && map_info[*j] != NULL) {
        (*j)++;
    }
    int *plane_info = str_to_int_array(map_info[*j]);
    planes[i]->dep.x = plane_info[0];
    planes[i]->dep.y = plane_info[1];
    planes[i]->arr.x = plane_info[2];
    planes[i]->arr.y = plane_info[3];
    planes[i]->speed = (float)plane_info[4];
    planes[i]->speed *= 0.1;
    planes[i]->delay = plane_info[5];
    sfSprite_setPosition(planes[i]->sprite, planes[i]->dep);
    planes[i]->hitbox = (sfIntRect){0, 0, 20, 20};
    obj_hitbox_t airplane_hitbox = obj_get_hitbox(planes[i]);
    planes[i]->hitbox_r = hitbox_rect(airplane_hitbox);
    planes[i]->is_crashed = FALSE;
    planes[i]->has_landed = FALSE;
    init_direction(planes, i, planes[i]->dep, planes[i]->arr);
    free(plane_info);
}

void init_planes(char **map_info, object_t **planes, int nb_plane)
{
    int j = 0;
    for (int i = 0; i < nb_plane; i++) {
        planes[i] = obj_sprite_create("assets/sprites/plane.png");
        init_plane(planes, i, map_info, &j);
        j++;
    }
    planes[nb_plane] = NULL;
}

/* radius_tower *= 19.2 because the greatest side of the screen is 1920 */
void init_tower(object_t **towers, int i, char **map_info, int *j)
{
    float radius_tower = 0.0;
    while (map_info[*j][0] != 'T' && map_info[*j] != NULL) {
        (*j)++;
    }
    int *tower_info = str_to_int_array(map_info[*j]);
    towers[i]->dep.x = tower_info[0];
    towers[i]->dep.y = tower_info[1];
    radius_tower = (float)tower_info[2];
    radius_tower *= 19.2;
    towers[i]->radius = radius_tower;
    towers[i]->hitbox = (sfIntRect){0, 0, 35, 35};
    sfSprite_setPosition(towers[i]->sprite, towers[i]->dep);
    towers[i]->hitbox_c = hitbox_circle(towers[i], towers[i]->radius);
    free(tower_info);
}

void init_towers(char **map_info, object_t **towers, int nb_tower)
{
    int j = 0;
    for (int i = 0; i < nb_tower; i++) {
        towers[i] = obj_sprite_create("assets/sprites/tower.png");
        init_tower(towers, i, map_info, &j);
        j++;
    }
    towers[nb_tower] = NULL;
}
