#ifndef MAP_SYMBOLS_H
# define MAP_SYMBOLS_H

#include <stdlib.h>
#include "huffman.h"
#include "string.h"

typedef char** t_map;

/**
 * @brief Allocates a new t_map filled with 0s
 * 
 * @param height the height of the tree
 * @return t_map Returns a new t_map allocated with calloc (filled with 0s)
 */
t_map constroy_map(int height);

/**
 * @brief Fill_map function just add recursively 0s and 1s to the path_as_bits
 * until it finds one leaf, and then, fill the map with the value.
 * 
 * @param map complete map
 * @param tree root tree in the first call, but its decendents until leaf
 * @param path_as_bits starts empty and add 0 to each left and 1 to each right
 * @param index is the height of the tree
 */
void	fill_map(t_map map, t_node *tree, char *path_as_bits, int index);

/**
 * @brief Debugger function just print the map
 * 
 * @param map t_map
 */
void	print_map(t_map map);

/**
 * @brief Get the strlen of the encoded message. This value is
 * used mainly to alloc the correct size of the encoded message. 
 * 
 * @param map t_map
 * @param str message represented as string
 * @return int the size of the encoded message.
 */
int		get_code_size(t_map map, char *str);

#endif