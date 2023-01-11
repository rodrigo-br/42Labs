#include "../include_headers/header.h"

t_bit_array constroy_bit_array(unsigned char *msg)
{
	t_bit_array	data;

	data.str_len = strlen((char *)msg);
	data.byte_len = byte_len(data.str_len);
	data.bit_array = (bits)calloc(data.byte_len, sizeof(unsigned char));
	for (size_t i = 0; i < data.str_len; i++) {
		if (msg[i] == '1')
			set_bit(data.bit_array, i);
		else
			bit_clear(data.bit_array, i);
	}
	return (data);
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

void bit_description(t_bit_array data)
{
	for (size_t i = 0; i < data.str_len; i++) {
		if (bit_test(data.bit_array, i))
			printf("1");
		else
			printf("0");
		if (i % 8 == 7)
			printf(" ");
	}
	printf("\n");
}

