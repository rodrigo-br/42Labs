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

/**
 * @brief Simple function to print the coded message puting space every 8 chars
 * to make it easier to read and count the bytes
 * 
 * @param str unsigned char *
 */
void print_coded(unsigned char *str);

#define FILE "test_666"

int main (void)
{
	char c;
	printf("(Enter) continue\n(d) destroy memory\n");
	scanf("%c", &c);
	if (c == 'd')
	{
		destroy_memory_block(FILE, 1);
		destroy_memory_block(FILE, 2);
		destroy_memory_block(FILE, 3);
	}
	unsigned char	*str = (unsigned char *)strdup("cavalinho");
	int				occurrence_table[OT_SIZE] = {0};
	t_node			**array_of_nodes;
	int				n_of_symbols;
	t_bit_array		data;
	t_map			map;


// c(1)      v(1)       l(1)       i(1)      n(1)      h(1)     o(1)       a(2)
// nó    	 nó      	nó      	 nó       nó      nó    	nó    		nó

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
	print_map(map);


	// Encode
	unsigned char *encoded_message = encode(map, str);


	// Decode
	unsigned char *decoded_message = decode(huffman_tree, encoded_message);

//caval
//11001110 10000000
//c = 8 bits
//ca
	// Debug
	// printf("Original msg = %s\n", str);
	// print_coded(encoded_message);
	// printf("Decoded msg = %s\n", decoded_message);
	// printf("tamanho da msg original = %ld\n", strlen((char *)str));
	// printf("tamanho da mensagem codificada = %ld\n", strlen((char *)encoded_message));


	// Bit Array
	data = constroy_bit_array(encoded_message);
	// bit_description(data);
	// printf("tamanho da msg comprimida = %ld\n", data.byte_len);


	// Share Memory
		//still testing
	int size_of_daniel = calculate_size(map, n_of_symbols);
	char *daniel = attach_memory_block(FILE, size_of_daniel, 3);
	put_things_in_daniel(&daniel, map, occurrence_table);
	printf("%s\n", daniel);

		//already working
	t_data_info *info = attach_memory_block_daniel(FILE, sizeof(t_data_info), 2);
	info->byte_len = data.byte_len;
	info->str_len = data.str_len;
	char *compressed = attach_memory_block(FILE, (int)data.byte_len, 1);
	for (size_t i = 0; i < data.byte_len; i++) {
		memset(compressed + i, data.bit_array[i], 1);
	}
	(void)compressed;


	// Detach Memory
	detach_memory_block((void *)compressed);
	detach_memory_block((void *)info);
	detach_memory_block((void *)daniel);


	// Destroy Memory
	char d;
	printf("(Enter) continue\n(d) destroy memory\n");
	scanf("%c", &d);
	if (d == 'd')
	{
		destroy_memory_block(FILE, 1);
		destroy_memory_block(FILE, 2);
		destroy_memory_block(FILE, 3);
	}
	// unsigned char decompressed[data.str_len];
	// for (size_t i = 0; i < data.str_len; i++) {
	// 	memset(decompressed + i, (bit_test(data.bit_array, i) ? '1' : '0'), 1);
	// }
	// print_coded(decompressed);


	// Free Memory
	destroy_it_all(huffman_tree, map, array_of_nodes);
	free(data.bit_array);
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
 
	// printf("Coded msg = ");
	while (str[i])
	{
		printf("%c", str[i]);
		if (i % 8 == 7)
			printf(" ");
		i++;
	}
	printf("\n");
}