#include "../include_headers/header.h"

/**
 * @brief Free the memory of all the important structures in the code
 * 
 * @param tree t_node * huffman's tree used to encode and decode the message
 * @param map t_map used to map the code of each symbol
 * @param array t_node ** used to store the nodes of the tree and sort then
 */
static void	destroy_it_all(t_node *tree, t_map map, t_node **array);

/**
 * @brief	Fill the array of nodes with the symbols and their occurrences,
 * and sort it by the occurrences.
 * 
 * @param array array_of_nodes
 * @param ot occurrence_table
 * @param n n_of_symbols
 * @return short 0 if success and 1 if failure on mallocs
 */
static short populate_and_sort_array(t_node **array, int ot[OT_SIZE], int n);


int main (void)
{
	setlocale(LC_ALL, "utf8");
	ask_for_delete_shm();
	unsigned char	*str = (unsigned char *)strdup("🦙ção paolo é um gajo muito fixe🦙");
	int				occurrence_table[OT_SIZE] = {0};
	t_node			**array_of_nodes;
	int				n_of_symbols;
	t_bit_array		data;
	t_map			map;


	// Ocurrence Table
	count_occurrences(str, &occurrence_table);
	n_of_symbols = get_n_of_symbols(occurrence_table);
	if (n_of_symbols < 2)
		return (printf("[BUG] Issue #1"), EXIT_FAILURE);


	// Array of nodes
	array_of_nodes = (t_node **)malloc(sizeof(t_node *) * (n_of_symbols + 1));
	if (populate_and_sort_array(array_of_nodes, occurrence_table, n_of_symbols))
		return (EXIT_FAILURE);


	// Huffman Tree
	t_node *huffman_tree = create_tree(array_of_nodes, n_of_symbols);


	// Map
	map = constroy_map(get_height(huffman_tree));
	fill_map(map, huffman_tree, (unsigned char *)"", get_height(huffman_tree));


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
	info->byte_len = data.byte_len;
	info->str_len = data.str_len;
	printf("%d %d\n", info->byte_len, info->str_len);

		//already working
	unsigned char *compressed = (unsigned char *)attach_memory_block(FILE, (int)data.byte_len, 1);
	for (size_t i = 0; i < data.byte_len; i++) {
		memset(compressed + i, data.bit_array[i], 1);
	}
	(void)compressed;


	// Detach Memory
	detach_memory_block((void *)compressed);
	detach_memory_block((void *)info);
	detach_memory_block((void *)daniel);


	// Destroy Memory
	ask_for_delete_shm();

	
	// unsigned char decompressed[data.str_len];
	// for (size_t i = 0; i < data.str_len; i++) {
	// 	memset(decompressed + i, (bit_test(data.bit_array, i) ? '1' : '0'), 1);
	// }
	// print_coded(decompressed);


	// Free Memory
	destroy_it_all(huffman_tree, map, array_of_nodes);
	free(data.bit_array);
	free(encoded_message);
	free(str);

	return (EXIT_SUCCESS);
}


static void	destroy_it_all(t_node *tree, t_map map, t_node **array)
{
	destroy_tree(tree);
	destroy_map(map);
	free(array);
}


static short populate_and_sort_array(t_node **array, int ot[OT_SIZE], int n)
{
	if (!array)
		return (EXIT_FAILURE);
	fill_array(array, ot);
	if (!array)
		return (EXIT_FAILURE);
	sort_array(array, n);
	return (EXIT_SUCCESS);
}
