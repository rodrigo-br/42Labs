#include "header.h"

void construct_occurrence_table(unsigned char *str, int (*occurrence_table)[OT_SIZE])
{
	occurrence_table_init(occurrence_table);
	count_occurrences(str, occurrence_table);
	// print_occurrence_table(*occurrence_table);
}

/**
 * @brief DELETE THIS FUNCTION!
 * The array of nodes only need a free in the head
 * the nodes should be destroyed by the tree destructor
 * 
 * @param n 
 */
void destroy_array_of_nodes(t_node **n)
{
	int i = 0;

	while (n[i])
	{
		free(n[i]);
		i++;
	}
	free(n);
}

int main (void)
{
	setlocale(LC_ALL, "");
	int				occurrence_table[OT_SIZE];
	int				n_of_symbols;
	unsigned char	*str = "sevlaa";
	t_node			**array_of_nodes;
	t_map			map;

	construct_occurrence_table(str, &occurrence_table);
	n_of_symbols = get_n_of_symbols(occurrence_table);
	array_of_nodes = (t_node **)malloc(sizeof(t_node *) * (n_of_symbols + 1));
	if (!array_of_nodes)
		return (EXIT_FAILURE);
	fill_array(array_of_nodes, occurrence_table);
	if (!array_of_nodes)
		return (EXIT_FAILURE);
	sort_array(array_of_nodes, n_of_symbols);
	t_node *huffman_tree = create_tree(array_of_nodes, n_of_symbols);
	map = constroy_map(get_height(huffman_tree));
	fill_map(map, huffman_tree, "", get_height(huffman_tree));
	unsigned char *encoded_message = encode(map, str);
	printf("%s\n", encoded_message);
}
