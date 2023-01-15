#ifndef ENCODER_H
# define ENCODER_H

#include "header.h"

/**
 * @brief Allocates and create the encoded message. Once the map is filled,
 * iterates through the original msg and concatenates the equivalent code to
 * each symbol until the original msg is over.
 * 
 * @param map t_map
 * @param str the original message as u_char*
 * @return unsigned char* 
 */
unsigned char	*encode(t_map map, unsigned char *str);

/**
 * @brief check argc and print usage if necessary
 * 
 * @return short returns 1 if theres an error and 0 otherwise
 */
short error(int argc);

/**
 * @brief Free the memory of all the important structures in the code
 * 
 * @param tree t_node * huffman's tree used to encode and decode the message
 * @param map t_map used to map the code of each symbol
 * @param array t_node ** used to store the nodes of the tree and sort then
 */
void	destroy_it_all(t_node *tree, t_map map, t_node **array, t_bit_array *data);

#endif