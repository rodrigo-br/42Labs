#include "huffman.h"

t_node	*new_node(char symbol, int occurrence)
{
	t_node *node;

	node = malloc(sizeof(t_node) * 1);
	node->symbol = symbol;
	node->occurrence = occurrence;
	node->left = NULL;
	node->right = NULL;
	return (node);
}