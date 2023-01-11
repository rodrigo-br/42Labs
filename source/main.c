#include "../include_headers/header.h"

static int construct_occurrence_table(unsigned char *str, int (*occurrence_table)[OT_SIZE])
{
	occurrence_table_init(occurrence_table);
	count_occurrences(str, occurrence_table);
	return get_n_of_symbols(*occurrence_table);
}

/**
 * @brief Free the memory of all the important structures in the code
 * 
 * @param tree t_node * huffman's tree used to encode and decode the message
 * @param map t_map used to map the code of each symbol
 * @param array t_node ** used to store the nodes of the tree and sort then
 */
static void	destroy_it_all(t_node *tree, t_map map, t_node **array)
{
	destroy_tree(tree);
	destroy_map(map);
	free(array);
}

/**
 * @brief	Fill the array of nodes with the symbols and their occurrences,
 * and sort it by the occurrences.
 * 
 * @param array_of_nodes 
 * @param occurrence_table 
 * @param n_of_symbols 
 * @return short 0 if success and 1 if failure on mallocs
 */
static short populate_and_sort_array(t_node **array_of_nodes, int occurrence_table[OT_SIZE], int n_of_symbols)
{
	if (!array_of_nodes)
		return (EXIT_FAILURE);
	fill_array(array_of_nodes, occurrence_table);
	if (!array_of_nodes)
		return (EXIT_FAILURE);
	sort_array(array_of_nodes, n_of_symbols);
	return (EXIT_SUCCESS);
}

int main (void)
{
	int				occurrence_table[OT_SIZE];
	int				n_of_symbols;
	unsigned char	*str = (unsigned char *)strdup("ção");
	t_node			**array_of_nodes;
	t_map			map;


	// Ocurrence Table
	n_of_symbols = construct_occurrence_table(str, &occurrence_table);


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


	// Decode
	unsigned char *decoded_message = decode(huffman_tree, encoded_message);


	// Debug
	printf("Original msg = %s\n", str);
	printf("Coded msg = %s\n", encoded_message);
	printf("Decoded msg = %s\n", decoded_message);


	// Free Memory
	destroy_it_all(huffman_tree, map, array_of_nodes);
	free(encoded_message);
	free(decoded_message);
	free(str);

	return (EXIT_SUCCESS);
}
