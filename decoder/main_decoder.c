#include "../include_headers/header.h"

int main(void)
{
	// read shared memory blocks
	unsigned char *compressed = (unsigned char *)attach_memory_block(FILE, 0, 1);
	t_data_info *info = (t_data_info *)attach_memory_block(FILE, 0, 2);
	unsigned char *daniel = (unsigned char *)attach_memory_block(FILE, 0, 3);


	// parse info shared into relevant data
	t_daniel	*daniel_body = danielgorithm(daniel);


	// decompress
	unsigned char *decompressed = decompress(compressed, info);


	// decode
	unsigned char *decoded = decode_msg(daniel_body, decompressed, info->str_len);
	
	
	// debug
	printf("Decoded msg from daniboy algorithm = %s\n", decoded);
}

