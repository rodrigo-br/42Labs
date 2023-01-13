#include "../include_headers/header.h"

unsigned char	*decode(t_node *tree, unsigned char *coded_msg)
{
	t_node 			*aux = tree;
	unsigned char	*decoded_msg;
	unsigned char	str_convert[2];
	int i = 0;

	decoded_msg = calloc(strlen((char *)coded_msg), sizeof(unsigned char));
	bzero(str_convert, 2);
	while (coded_msg[i])
	{
		aux = (coded_msg[i] == '0') ? aux->left : aux->right; 
		if (is_leaf(aux))
		{
			str_convert[0] = aux->symbol;
			ft_ustrcat(decoded_msg, str_convert);
			aux = tree;
		}
		i++;	
	}
	return (decoded_msg);
}
