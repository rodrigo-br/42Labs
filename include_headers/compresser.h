#ifndef COMPRESSER_H
# define COMPRESSER_H

# include "header.h"

/**
 * @brief Set the bit of the bit_array at the position to 1
 * 
 * @param bit_array unsigned char *
 * @param position size_t
 */
void	set_bit(unsigned char *bit_array, size_t position);

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
size_t	bit_len(size_t length);

/**
 * @brief Set the bit of the bit_array at the position to 0
 * 
 * @param bit_array unsigned char *
 * @param position size_t
 */
void	bit_clear(unsigned char *bit_array, size_t position);

/**
 * @brief Verify if the bit of the bit_array at the position is 1
 * 
 * @param bit_array unsigned char *
 * @param position size_t
 * @return short Returns 1 if the bit is 1, 0 otherwise
 */
short	bit_test(unsigned char *bit_array, size_t position);

#endif