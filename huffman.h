#ifndef HUFFMAN_H
# define HUFFMAN_H

# include <stdlib.h>
# include <stdio.h>

/**
 * @brief Nodes of Huffman's Tree
 * 
 */
typedef struct s_node {
	unsigned char	symbol;
	int				occurrence;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

/**
 * @brief List of nodes, needed to create the Huffman's Tree
 * 
 */
typedef struct s_list {
	t_node			*node;
	struct s_list	*next;
}	t_list;

/**
 * @brief Allocates a new node for Huffman's Tree and initializes it
 * 
 * @param symbol a character from the message to be compressed
 * @param occurrence the occurrence frequency of the character
 * @return Returns a new t_node allocated and initialized
 */
t_node	*create_new_node(char symbol, int occurrence);

/**
 * @brief Creates a new node and initializes it with the sum of the occurrences
 * of the left and right nodes. This new node have no significant symbol.
 * 
 * @param left t_node *
 * @param right t_node *
 * @return t_node* do i need it?
 */
t_node	*merge_nodes(t_node *left, t_node *right);

/**
 * @brief Create the huffman's tree by merging the two first
 * nodes and reordering the array of nodes, until there is only
 * one node left.
 * 
 * @param nodes the entire array of nodes
 * @param size start with the total number of symbols in the message
 * @return Returns the root of the Huffman's Tree
 */
t_node *create_tree(t_node **nodes, int size);

void	print_tree(t_node *tree, int level);





#endif