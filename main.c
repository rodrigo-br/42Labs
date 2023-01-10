#include <stdio.h>
#include "occurrence_table.h"
#include "huffman.h"

void construct_occurrence_table(char *str, int (*occurrence_table)[OT_SIZE])
{
	occurrence_table_init(occurrence_table);
	count_occurrences(str, occurrence_table);
	// print_occurrence_table(*occurrence_table);
}

int main (void)
{
	int occurrence_table[OT_SIZE];
	int n_of_symbols;
	char *str = "cavalinho";
	t_node **array_of_nodes;

	construct_occurrence_table(str, &occurrence_table);
	n_of_symbols = get_n_of_symbols(occurrence_table);
	array_of_nodes = (t_node **)malloc(sizeof(t_node *) * (n_of_symbols + 1));
	fill_array(array_of_nodes, occurrence_table);
	// print_array(array_of_nodes, n_of_symbols);
	sort_array(array_of_nodes);
}
