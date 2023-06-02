/*
** EPITECH PROJECT, 2022
** src
** File description:
** main
*/
#include "src.h"

int main(int ac, char **av)
{
    int x = 0;
    int y = 0;
    maze_data_t *maze_data = NULL;
    stack_t *stack = stack_create();
    if (!stack) return (84);
    maze_data = malloc(sizeof(maze_data_t));
    srand(time(NULL));
    if (check_inputs(ac, av) == FALSE) return (84);
    x = my_getnbr_int(av[1]);
    y = my_getnbr_int(av[2]);
    maze_data->maze = bt_init_maze(x, y);
    maze_data->visit = bt_init_visit(x, y);
    maze_data->m_x = x;
    maze_data->m_y = y;
    maze_data->count = (U_INT)(x * y);
    bt_generate_maze(maze_data, stack, 0, 0);
    bt_print_final_maze(maze_data);
    maze_data_free(maze_data);
    stack_clear(stack);
    return (0);
}
//handle_eller_algo(x, y);
/*manage_coord(&x, &y);
    maze_data = maze_data_init(x ,y);
    if (!maze_data)
        return (84);
    generate_maze(maze_data);
    maze_data_free(maze_data);*/
/*
rbt_setup_maze(x, y);
    rbt_generate_maze(maze_setup, 0, 0, (coord_t){x, y});
    rbt_print_maze(maze_setup, x, y);
    free_array_int2d(maze_setup);
*/
