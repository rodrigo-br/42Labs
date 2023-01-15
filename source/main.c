#include "../include_headers/header.h"

int main (int argc, char **argv)
{
	setlocale(LC_ALL, "utf8");


	// First checkers
	if (argc == 1)
		check_for_results();
	if (error(argc))
		return (EXIT_FAILURE);
	if (strcmp(argv[1], "-help") == 0)
		return (help(), EXIT_SUCCESS);


	// Declarations
	delete_memory_blocks();
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


	// Bit Array
	data = constroy_bit_array(encoded_message);


	// Share Memory
	int size_of_daniel = calculate_size(map, n_of_symbols);
	unsigned char *daniel = (unsigned char *)attach_memory_block(FILE, size_of_daniel, 3);
	put_things_in_daniel(&daniel, map, occurrence_table);
	t_data_info *info = (t_data_info *)attach_memory_block(FILE, sizeof(t_data_info), 2);
	info->byte_len = data->byte_len;
	info->str_len = data->str_len;
	unsigned char *compressed = (unsigned char *)attach_memory_block(FILE, (int)data->byte_len, 1);
	memcpy(compressed, data->bit_array, data->byte_len);


	// Detach Memory
	detach_all_from_encode((void *)compressed, (void *)info, (void *)daniel);


	// Free Memory
	destroy_it_all(huffman_tree, map, array_of_nodes, data);
	free(encoded_message);
	free(str);
	printf("Encoded sucessfully!\n");
	return (EXIT_SUCCESS);
}




