#include "huffman.h"
#include "array_utils.h"

t_node	*create_new_node(char symbol, int occurrence)
{
	t_node *node;

	node = malloc(sizeof(t_node) * 1);
	node->symbol = symbol;
	node->occurrence = occurrence;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_node *create_tree(t_node **nodes, int size)
{
	while (nodes[1])
	{
		nodes[0] = merge_nodes(nodes[0], nodes[1]);
		slide_array_to_left(nodes);
		size--;
		sort_array(nodes, size);
	}
	return (nodes[0]);
}

void	print_tree(t_node *tree, int level)
{
	if (tree->left == NULL && tree->right == NULL)
		printf("Leaf: %c, level: %d\n", tree->symbol, level);
	else {
		print_tree(tree->left, level + 1);
		print_tree(tree->right, level + 1);
	}
}