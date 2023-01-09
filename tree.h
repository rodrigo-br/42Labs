#ifndef TREE_H
#define TREE_H

typedef struct s_node {
	char 			symbol;
	int				occurrence;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

#endif