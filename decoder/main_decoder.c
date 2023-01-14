#include "../include_headers/header.h"

/**
 * @brief Just poking around and trying stuff to figure things out
 */
int main(void)
{
	// read shared memory blocks
	unsigned char *compressed = (unsigned char *)attach_memory_block(FILE, 0, 1);
	t_data_info *info = (t_data_info *)attach_memory_block(FILE, 0, 2);
	unsigned char *daniel = (unsigned char *)attach_memory_block(FILE, 0, 3);


	// parse info shared into relevant data
	t_daniel	*daniel_body;
	daniel_body = danielgorithm(daniel);
	(void)compressed;
}

