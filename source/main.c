#include "../include_headers/header.h"

/**
 * @brief Free the memory of all the important structures in the code
 * 
 * @param tree t_node * huffman's tree used to encode and decode the message
 * @param map t_map used to map the code of each symbol
 * @param array t_node ** used to store the nodes of the tree and sort then
 */
static void	destroy_it_all(t_node *tree, t_map map, t_node **array, t_bit_array *data);

/**
 * @brief check argc and print usage if necessary
 * 
 * @return short returns 1 if theres an error and 0 otherwise
 */
short error(int argc);

int main (int argc, char **argv)
{
	if (error(argc))
		return (EXIT_FAILURE);
	setlocale(LC_ALL, "utf8");
	ask_for_delete_shm();
	unsigned char	*str = handle_input(argc, argv);
	int				occurrence_table[OT_SIZE] = {0};
	t_node			**array_of_nodes;
	t_bit_array		*data;
	t_map			map;


	// Ocurrence Table
	count_occurrences(str, &occurrence_table);
	int n_of_symbols = get_n_of_symbols(occurrence_table);


	// Array of nodes
	array_of_nodes = create_array(n_of_symbols, occurrence_table);


	// Huffman Tree
	t_node *huffman_tree = create_tree(array_of_nodes, n_of_symbols);


	// Map
	map = constroy_map(get_height(huffman_tree));
	fill_map(map, huffman_tree, (unsigned char *)"", get_height(huffman_tree));
	if (n_of_symbols == 1)
		strcpy((char *)map[array_of_nodes[0]->symbol], "0");

	// Encode
	unsigned char *encoded_message = encode(map, str);


	// Debug
	// printf("tamanho da msg original = %ld\n", strlen((char *)str));
	// printf("tamanho da mensagem codificada = %ld\n", strlen((char *)encoded_message));


	// Bit Array
	data = constroy_bit_array(encoded_message);
	// bit_description(data);
	// printf("tamanho da msg comprimida = %ld\n", data.byte_len);


	// Share Memory
		//still testing
	int size_of_daniel = calculate_size(map, n_of_symbols);
	unsigned char *daniel = (unsigned char *)attach_memory_block(FILE, size_of_daniel, 3);
	put_things_in_daniel(&daniel, map, occurrence_table);

		//already working
	t_data_info *info = (t_data_info *)attach_memory_block(FILE, sizeof(t_data_info), 2);
	info->byte_len = data->byte_len;
	info->str_len = data->str_len;
	printf("%ld %ld\n", info->byte_len, info->str_len);

		//already working
	unsigned char *compressed = (unsigned char *)attach_memory_block(FILE, (int)data->byte_len, 1);
	for (size_t i = 0; i < data->byte_len; i++) {
		memset(compressed + i, data->bit_array[i], 1);
	}
	(void)compressed;


	// Detach Memory
	detach_memory_block((void *)compressed);
	detach_memory_block((void *)info);
	detach_memory_block((void *)daniel);


	// Destroy Memory
	ask_for_delete_shm();


	// Free Memory
	destroy_it_all(huffman_tree, map, array_of_nodes, data);
	free(encoded_message);
	free(str);

	return (EXIT_SUCCESS);
}


static void	destroy_it_all(t_node *tree, t_map map, t_node **array, t_bit_array *data)
{
	destroy_bit_array(data);
	destroy_tree(tree);
	destroy_map(map);
	free(array);
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
