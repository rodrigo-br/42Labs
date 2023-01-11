#ifndef COMPRESSER_H
# define COMPRESSER_H

# include "header.h"

typedef unsigned char * bits;

typedef struct s_bit_array
{
	bits	bit_array;
	size_t	str_len;
	size_t	byte_len;
}	t_bit_array;

/**
 * @brief Allocates a new bit_array and set all bits accordinaly to the message
 * 
 * @param msg unsigned char *
 * @return unsigned char* Returns a new array of bits compressed
 */
t_bit_array constroy_bit_array(unsigned char *msg);

/**
 * @brief Set the bit of the bit_array at the position to 1
 * 
 * @param bit_array bits
 * @param position size_t
 */
void	set_bit(bits bit_array, size_t position);

/**
 * @brief find the correct bit index
 * 
 * @param position size_t
 * @return size_t
 */
size_t	bit_index(size_t position);

/**
 * @brief find the correct bit mask to aplly
 * 
 * @param position size_t
 * @return size_t
 */
size_t	mask_bit(size_t position);

/**
 * @brief find the correct length of the array of bits
 * compared to the len of an array of chars filled with "bits" values
 * 
 * @param length 
 * @return size_t 
 */
size_t	byte_len(size_t length);

/**
 * @brief Set the bit of the bit_array at the position to 0
 * 
 * @param bit_array bits
 * @param position size_t
 */
void	bit_clear(bits	bit_array, size_t position);

/**
 * @brief Verify if the bit of the bit_array at the position is 1
 * 
 * @param bit_array bits
 * @param position size_t
 * @return short Returns 1 if the bit is 1, 0 otherwise
 */
short	bit_test(bits	bit_array, size_t position);

/**
 * @brief Auxiliar debug function that prints the bits of the bit_array
 * 
 * @param bit_array bits
 * @param str_lenght size_t
 */
void bit_description(t_bit_array bit_array);

#endif