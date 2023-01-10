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

void	fill_map(t_map map, t_node *tree, char *path_as_bits, int index);

void	print_map(t_map map);

int		get_code_size(t_map map, char *str);

#endif