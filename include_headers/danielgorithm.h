#ifndef DANIELGORITHM_H
# define DANIELGORITHM_H

#include "header.h"

typedef struct s_daniel
{
	t_map			map;
	unsigned char	*symbols;
}	t_daniel;

/**
 * @brief Parse the shared memory block containing the map and the symbols
 * into relevant data that can be used to recreate the original message
 * 
 * @param daniel unsigned char * unparsed data
 * @return t_daniel*  parsed data
 */
t_daniel	*danielgorithm(unsigned char *daniel);

#endif