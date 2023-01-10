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

/**
 * @brief Auxiliar function to the sort_array
 * 
 * @param array t_node **
 * @param n position of the node to be swaped with the next one
 */
static void swap_nodes(t_node **array, int n)
{
	t_node *temp = array[n];
	array[n] = array[n + 1];
	array[n + 1] = temp;
}

void sort_array(t_node **aon, int n_of_symbols)
{
	for (int i = 0; i < n_of_symbols - 1; i++) {
		for (int j = 0; j < n_of_symbols - i - 1; j++) {
				if (aon[j]->occurrence > aon[j + 1]->occurrence)
					swap_nodes(aon, j);
		}
	}
}

void print_array(t_node **array_of_nodes, int n_of_symbols)
{
	int i = 0;
	for (int i = 0; i < n_of_symbols; i++) {
		printf("Node %d  -   char(DEC) = %3d  occurrences = %d\n", i + 1, array_of_nodes[i]->symbol, array_of_nodes[i]->occurrence);
	}
}