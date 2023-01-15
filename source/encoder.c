#include "../include_headers/header.h"

static unsigned char	*get_bit_code(t_map map, unsigned char c)
{
	return (map[c]);
}

unsigned char	*encode(t_map map, unsigned char *str)
{
	int				size = get_code_size(map, str);
	unsigned char	*encoded = calloc((size + 1), sizeof(unsigned char));
	int				i = 0;

	encoded[size] = '\0';
	while (str[i])
	{
		ft_ustrcat(encoded, get_bit_code(map, str[i]));
		i++;
	}

	return (encoded);
}

short error(int argc)
{
	if (argc >= 2)
		return (EXIT_SUCCESS);

	printf("Usage: \n./encoder_program [file] \
			\npress d, enter, any other lether and enter. \
			\n./decoder_program\n");
	return (EXIT_FAILURE);
}

void	destroy_it_all(t_node *tree, t_map map, t_node **array, t_bit_array *data)
{
	destroy_bit_array(data);
	destroy_tree(tree);
	destroy_map(map);
	free(array);
}

void delete_memory_blocks(void)
{
	destroy_memory_block(FILE, 1);
	destroy_memory_block(FILE, 2);
	destroy_memory_block(FILE, 3);
	destroy_memory_block(FILE, 4);
	destroy_memory_block(FILE, 5);
}

void detach_all_from_encode(void *compressed, void *info, void *daniel)
{
	detach_memory_block(compressed);
	detach_memory_block(info);
	detach_memory_block(daniel);
}