#include "../include_headers/header.h"

bits constroy_bit_array(unsigned char *msg)
{
	bits bit_array;

	bit_array = (bits)calloc(byte_len(strlen((char *)msg)), sizeof(unsigned char));
	for (size_t i = 0; i < strlen((char *)msg); i++) {
		if (msg[i] == '1')
			set_bit(bit_array, i);
		else
			bit_clear(bit_array, i);
	}
	return (bit_array);
}

void	set_bit(bits bit_array, size_t position)
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

size_t	byte_len(size_t length)
{
	return ((length + CHAR_BIT - 1) / CHAR_BIT);
}

void	bit_clear(bits bit_array, size_t position)
{
	bit_array[bit_index(position)] &= ~mask_bit(position);
}

short	bit_test(bits bit_array, size_t position)
{
	return (bit_array[bit_index(position)] & mask_bit(position));
}

void bit_description(bits bit_array, size_t str_lenght)
{
	for (size_t i = 0; i < str_lenght; i++) {
		if (bit_test(bit_array, i))
			printf("1");
		else
			printf("0");
		if (i % 8 == 7)
			printf(" ");
	}
	printf("\n");
}

