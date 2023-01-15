#ifndef HUFF_PARSER_H
# define HUFF_PARSER_H

#include "header.h"

typedef struct s_huff
{
	t_map			map;
	unsigned char	*symbols;
}	t_huff;

/**
 * @brief Parse the shared memory block containing the map and the symbols
 * into relevant data that can be used to recreate the original message
 * 
 * @param huff unsigned char * unparsed data
 * @return t_huff*  parsed data
 */
t_huff	*huffgorithm(unsigned char *huff);

#endif