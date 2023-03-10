#ifndef ARRAY_UTILS_H
# define ARRAY_UTILS_H

# include "huffman.h"

/**
 * @brief Allocate a new t_node ** and fill it with the nodes
 * 
 * @param n_of_symbols int
 * @return t_node** 
 */
t_node **create_array(int n_of_symbols, int *occurrence_table);

/**
 * @brief create nodes from the occurrence table and fill the array of
 * nodes with it.
 * 
 * @param array_of_nodes variable to store all initial nodes (not sorted)
 * @param occurrence_table int *
 */
void fill_array(t_node **array_of_nodes, int *occurrence_table);

/**
 * @brief Auxiliar Debug function
 * 
 * @param array_of_nodes t_node**
 * @param n_of_symbols int
 */
void print_array(t_node **array_of_nodes, int n_of_symbols);

/**
 * @brief Sort the array of nodes in crescent order, ordered
 * by the occurrences atribute of each node. Simple the size
 * of the array is pretty small, i opt for bubble sort due to
 * it's simplicity.
 * 
 * @param array_of_nodes t_node **
 */
void sort_array(t_node **array_of_nodes, int n_of_symbols);

/**
 * @brief Create the linked list that will be used to 
 * 
 * @param array_of_nodes 
 * @param n_of_symbols 
 * @return t_list* 
 */
t_list	*array_to_list(t_node **array_of_nodes, int n_of_symbols);

/**
 * @brief After the merged nodes, the array of nodes will have
 * a duplicated node (the second one). To solve that, this function
 * slide all the other nodes after that to the left, overrindg the
 * duplicated value and "deleting" the remaining one;
 * 
 * @param array_of_nodes t_node **
 */
void slide_array_to_left(t_node **array_of_nodes);

#endif