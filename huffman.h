#ifndef HUFFMAN_H
# define HUFFMAN_H

# include <stdlib.h>

/**
 * @brief Node for Huffman's Tree
 * 
 */
typedef struct s_node {
	char			symbol;
	int				occurrence;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;


/**
 * @brief Allocates a new node for Huffman's Tree and initializes it
 * 
 * @param symbol a character from the message to be compressed
 * @param occurrence the occurrence frequency of the character
 * @return Returns a new t_node allocated and initialized
 */
t_node	*new_node(char symbol, int occurrence);

#endif