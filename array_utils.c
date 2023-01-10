#include "array_utils.h"
#include "occurrence_table.h"

void fill_array(t_node **array_of_nodes, int *occurrence_table)
{
	int position = 0;

	for (int i = 0; i < OT_SIZE; i++) {
		if (occurrence_table[i] != 0) {
			array_of_nodes[position] = new_node(i, occurrence_table[i]);
			position++;
		}
	}
	array_of_nodes[position] = NULL;
}

void sort_array(t_node **array_of_nodes)
{

}

void print_array(t_node **array_of_nodes, int n_of_symbols)
{
	int i = 0;
	for (int i = 0; i < n_of_symbols; i++) {
		printf("Node %d  -   char(DEC) = %3d  occurrences = %d\n", i + 1, array_of_nodes[i]->symbol, array_of_nodes[i]->occurrence);
	}
}