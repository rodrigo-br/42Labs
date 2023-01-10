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

#endif