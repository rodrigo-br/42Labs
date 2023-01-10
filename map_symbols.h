#ifndef MAP_SYMBOLS_H
# define MAP_SYMBOLS_H

#include <stdlib.h>

typedef char** t_map;

/**
 * @brief Allocates a new t_map filled with 0s
 * 
 * @param height the height of the tree
 * @return t_map Returns a new t_map allocated with calloc (filled with 0s)
 */
t_map constroy_map(int height);

#endif