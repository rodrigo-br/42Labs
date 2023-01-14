#include "../include_headers/header.h"

/**
 * @brief Auxiliar function of fill_array, called in case of error in malloc
 * free array_of_nodes and set to NULL
 * 
 * @param array_of_nodes t_node **
 * @param position	the index position to node that failed
 */
static void error_malloc_array_of_nodes(t_node **array_of_nodes, int position)
{
	int index = 0;

	while (index < position)
	{
		free(array_of_nodes[index]);
		index++;
	}
	free(array_of_nodes);
	array_of_nodes = NULL;
}

t_node **create_array(int n_of_symbols, int *occurrence_table)
{
	t_node **array_of_nodes = (t_node **)calloc((n_of_symbols + 1), sizeof(t_node *));

	if (!array_of_nodes)
		return (NULL);
	fill_array(array_of_nodes, occurrence_table);
	if (!array_of_nodes)
		return (NULL);
	return (array_of_nodes);
}

void fill_array(t_node **array_of_nodes, int *occurrence_table)
{
	int position = 0;

	for (int i = 0; i < OT_SIZE; i++) {
		if (occurrence_table[i] != 0) {
			array_of_nodes[position] = create_new_node(i, occurrence_table[i]);
			if (!array_of_nodes[position])
			{
				error_malloc_array_of_nodes(array_of_nodes, position);
				return ;
			}
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
	if (n_of_symbols == 1)
		return;
	int swap = 1;
	for (int i = 0; i < n_of_symbols - 1; i++) {
		if (swap == 0)
			return;
		swap = 0;
		for (int j = 0; j < n_of_symbols - i - 1; j++) {
			if (aon[j]->occurrence > aon[j + 1]->occurrence)
			{
				swap_nodes(aon, j);
				swap = 1;
			}
		}
	}
}

void print_array(t_node **array_of_nodes, int n_of_symbols)
{
	for (int i = 0; i < n_of_symbols; i++) {
		printf("Node %d  -   char(DEC) = %3d  occurrences = %d\n", i + 1, array_of_nodes[i]->symbol, array_of_nodes[i]->occurrence);
	}
}

t_list	*array_to_list(t_node **array_of_nodes, int n_of_symbols)
{
	t_list *new_list;
	t_list *list_to_return;

	for (int i = 0; i < n_of_symbols; i++) {
		new_list = (t_list *)malloc(sizeof(t_list));
		if (i == 0)
			list_to_return = new_list;
		new_list->node = array_of_nodes[i];
		new_list->next = NULL;
		new_list = new_list->next;
	}

	return (list_to_return);
}

void slide_array_to_left(t_node **array_of_nodes)
{
	int i = 1;

	while (array_of_nodes[i + 1])
	{
		array_of_nodes[i] = array_of_nodes[i + 1];
		i++;
	}
	array_of_nodes[i] = NULL;
}
