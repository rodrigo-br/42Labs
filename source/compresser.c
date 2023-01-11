#include "../include_headers/header.h"

void	set_bit(unsigned char *bit_array, size_t position)
{
	bit_array[bit_index(position)] |= mask_bit(position);
}

size_t	bit_index(size_t position)
{
	return (position / CHAR_BIT);
}

size_t	mask_bit(size_t position)
{
	return (1 << (position % CHAR_BIT));
}

size_t	bit_len(size_t length)
{
	return ((length + CHAR_BIT - 1) / CHAR_BIT);
}

void	bit_clear(unsigned char *bit_array, size_t position)
{
	bit_array[bit_index(position)] &= ~mask_bit(position);
}

short	bit_test(unsigned char *bit_array, size_t position)
{
	return (bit_array[bit_index(position)] & mask_bit(position));
}

