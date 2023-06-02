/*
** EPITECH PROJECT, 2022
** include
** File description:
** graph.h
*/
/**
 * @file graph.h
 *
 * @brief Has data structure and functions about graph
 *
 * @date 28/03/2024
*/
#ifndef GRAPH_H_
    #define GRAPH_H_


typedef struct weight_info_s {
    bool *marked;
    int *distance;
} weight_info_t;

typedef struct neighbor_info_s {
    u_int next;
    u_int j;
} neighbor_info_t;

/**
 * @brief Store data of two node to add and edge, usefull for edge_add func
 *
 */
typedef struct edge_info_s {
    u_int src;
    u_int dest;
    char *src_str;
    char *dest_str;
} edge_info_t;


/**
 * @brief Node element of the graph structure
 *
*/
typedef struct node_element_s {
    char *name;
    unsigned int value;
    int weight;
    struct node_element_s *next;
    struct node_element_s *prev;
} node_element_t;

/**
 * @brief Adjacency list of the graph structure
 *
*/

typedef struct adjacency_list_s {
    node_element_t *start;
} adjacency_list_t;

/**
 * @brief Graph element of the graph structure
 *
 */
typedef struct graph_element_s {
    adjacency_list_t *neighbours;
    unsigned int nb_vertices;
    char **names;
    int *weight;
    u_int *ants;
    bool *rooms;
    u_int nb_ants_start;
    u_int nb_ants_end;
    u_int ants_max;
} graph_element_t;

/**
 * @brief Create and initialise a graph with a number of vertices given
 *
 * @param nb_vertices The number of vertices desired
 * @return graph_element_t *
 */
graph_element_t *graph_create(unsigned int nb_vertices);

/**
 * @brief Destroy a graph struct
 *
 * @param graph graph_element_t *
 */
void graph_destroy(graph_element_t *graph);

/**
 * @brief Print a graph
 *
 * @param graph graph_element_t *
 */
void graph_print(graph_element_t *graph);

/**
 * @brief Verify if start and end are connected
 *
 * @param graph graph_element_t *
 * @return true If start and end are connected
 * @return false If start and end aren't connected
 */
bool graph_has_solution(graph_element_t *graph);

/**
 * @brief Add a node element to a adjacency list struct
 *
 * @param value The value of element to help the manipulation of the struct
 * @return node_element_t *
 */
node_element_t *node_add(unsigned int value);

/**
 * @brief Add a name to a node of a graph struct
 *
 * @param node node_element_t *
 * @param name char * is the name of the node, room for lemin project
 */
void node_add_name(node_element_t *node, char *name);

/**
 * @brief Remove a node of a graph struct
 *
 * @param node node_element_t *
 */
void node_remove(node_element_t *node);

/**
 * @brief Print a node of a graph struct
 *
 * @param node node_element_t *
 */
void node_print(node_element_t *node);

/**
 * @brief Add two nodes linked in a graph struct
 *
 * @param graph graph_element_t *
 * @param info Info of the two nodes to add (char *, and u_int value)
 */
void edge_add(graph_element_t *graph, u_int src, u_int dest);

/**
 * @brief Initialise all the weight of nodes, from start to end
 *
 * @param graph graph_element_t *
 */
void weight_update(graph_element_t *graph);

/**
 * @brief Add weight to notes with int array that store informations required
 *
 * @param graph graph_element_t *graph
 * @param distance Store distance between vertices
 * @param predecessor Store predecessor
 */
void weight_add(graph_element_t *graph, int *distance, int *predecessor);

/**
 * @brief Get the number of vertice till the last index
 *
 * @param graph graph_element_t *
 * @param node_idx u_int, is the index position of the node
 * @return u_int Number of index till the last case, for Lemin it's end room
 */
u_int weight_vertice_to_end(graph_element_t *graph, u_int node_idx);

/**
 * @brief Set all weight for a graph, link have to be done before using this
 *
 * @param graph graph_element_t * : the graph
 */
void weight_set(graph_element_t *graph);

/**
 * @brief Init graph whith info
 *
 * @param info info_t
 * @return graph_element_t*
 */
graph_element_t *graph_init(info_t *info);

/**
 * @brief opening window for graphique result
 *
 * @param info
 * @param graph
 */
void open_window(info_t *info, graph_element_t *graph);

/**
 * @brief init line for result
 *
 * @param wd
 * @return int
 */
int init_line(window_t *wd);
#endif /* GRAPH_H_ */
