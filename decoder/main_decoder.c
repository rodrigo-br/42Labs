#include "../include_headers/header.h"


typedef struct s_daniel
{
	t_map			map;
	unsigned char	*symbols;
}	t_daniel;

// static t_daniel	*danielgorithm(unsigned char *daniel);


/**
 * @brief Just poking around and trying stuff to figure things out
 */
int main(void)
{
	// t_data_info *info = attach_memory_block_daniel(FILE, 0, 2);
	// printf("bythe_len = %d\n", info->byte_len);
	// printf("str_len = %d\n", info->str_len);

	// unsigned char *daniel = attach_memory_block(FILE, 0, 3);
	// t_daniel	*daniel_body;

	// daniel_body = danielgorithm(daniel);
	// unsigned char *compressed = attach_memory_block(FILE, 0, 1);
	// (void)compressed;
	// (void)daniel_body;
}

// short find_spot(char c1, char c2)
// {
// 	return (c1 == ' ' && c2 == ' ');
// }

// static t_daniel	*danielgorithm(unsigned char *daniel)
// {
// 	t_daniel	*new_dani;
// 	int i = 0;

// 	new_dani = (t_daniel *)calloc(1, sizeof(t_daniel));
// 	while (daniel[i])
// 	{
// 		if (find_spot(daniel[i], daniel[i + 1]))
// 			break;
// 	}
// 	new_dani->map = create_map(daniel, i);
// }