#include <stdio.h>
#include "occurrence_table.h"
#include "huffman.h"
#include "array_utils.h"

void construct_occurrence_table(char *str, int (*occurrence_table)[OT_SIZE])
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
	int occurrence_table[OT_SIZE];
	int n_of_symbols;
	char *str = "cavalinho na chuva ao vento";
	t_node **array_of_nodes;

	construct_occurrence_table(str, &occurrence_table);
	n_of_symbols = get_n_of_symbols(occurrence_table);
	array_of_nodes = (t_node **)malloc(sizeof(t_node *) * (n_of_symbols + 1));
	fill_array(array_of_nodes, occurrence_table);
	sort_array(array_of_nodes, n_of_symbols);
	print_array(array_of_nodes, n_of_symbols);
	destroy_array_of_nodes(array_of_nodes);

}
