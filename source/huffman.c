#include "../include_headers/header.h"

t_node	*create_new_node(unsigned char symbol, int occurrence)
{
	t_node *node;

	node = malloc(sizeof(t_node) * 1);
	node->symbol = symbol;
	node->occurrence = occurrence;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_node	*merge_nodes(t_node *n1, t_node *n2)
{
	t_node *new_node = create_new_node(0, n1->occurrence + n2->occurrence);

	new_node->left = n1;
	new_node->right = n2;
	return (new_node);
}

t_node	*create_tree(t_node **nodes, int size)
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

int		get_height(t_node *tree)
{
	int		left_height;
	int		right_height;
	if (!tree)
		return (-1);
	left_height = get_height(tree->left) + 1;
	right_height = get_height(tree->right) + 1;

	if (left_height > right_height)
		return (left_height);
	return (right_height);
}

short	is_leaf(t_node *tree)
{
	return (tree->left == NULL && tree->right == NULL);
}

void	print_tree(t_node *tree, int level)
{
	if (is_leaf(tree))
		printf("Leaf: %c, level: %d\n", tree->symbol, level);
	else {
		print_tree(tree->left, level + 1);
		print_tree(tree->right, level + 1);
	}
}

void	destroy_tree(t_node *tree)
{
	if (tree)
	{
		destroy_tree(tree->left);
		destroy_tree(tree->right);
		free(tree);
	}
}