/*
** EPITECH PROJECT, 2023
** collisions.h
** File description:
** collisions
*/

#ifndef COLLISION_H
    #define COLLISION_H


/**
 * @brief checks if mouse is on circle
 *
 * @param circle sfCircleShape *
 * @param mouse sfVector2i mouse
 * @return true
 * @return false
 */
bool mouse_over_circle(sfCircleShape *circle, sfVector2i mouse);

/**
 * @brief  checks if mouse is on rect
 *
 * @param rect sfRectangleShape *
 * @param mouse sfVector2i
 * @return true
 * @return false
 */
bool mouse_over_rect(sfRectangleShape *rect, sfVector2i mouse,
    sfRenderWindow *wd);
#endif /* COLLISION */
