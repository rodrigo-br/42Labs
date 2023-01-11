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

void print_coded(unsigned char *str);

int main (void)
{
	unsigned char	*str = (unsigned char *)strdup("cavalinho na chuva ao vento pegando frio");
	int				occurrence_table[OT_SIZE] = {0};
	t_node			**array_of_nodes;
	int				n_of_symbols;
	t_map			map;


	// Ocurrence Table
	count_occurrences(str, &occurrence_table);
	n_of_symbols = get_n_of_symbols(occurrence_table);


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
	print_coded(encoded_message);
	printf("Decoded msg = %s\n", decoded_message);


	// Bit Array (Still testing)
	unsigned char *bit_array = (unsigned char *)calloc(bit_len(strlen((char *)encoded_message)), sizeof(unsigned char));
	for (size_t i = 0; i < strlen((char *)encoded_message); i++) {
		if (encoded_message[i] == '1')
			set_bit(bit_array, i);
		else
			bit_clear(bit_array, i);
	}
	for (size_t i = 0; i < strlen((char *)encoded_message); i++) {
		if (bit_test(bit_array, i))
			printf("1");
		else
			printf("0");
		if (i % 8 == 7)
			printf(" ");
	}
	printf("\n%ld\n", bit_len(strlen((char *)encoded_message)));

	// Free Memory
	free(bit_array);
	destroy_it_all(huffman_tree, map, array_of_nodes);
	free(encoded_message);
	free(decoded_message);
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

void print_coded(unsigned char *str)
{
	int	i = 0;
 
	while (str[i])
	{
		printf("%c", str[i]);
		if (i % 8 == 7)
			printf(" ");
		i++;
	}
	printf("\n");
}