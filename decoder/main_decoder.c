#include "../include_headers/header.h"

void destroy_all_decoder(t_daniel *daniel_body, void *decoded, void *decompressed);

int main(void)
{
	// Read shared memory blocks
	unsigned char *compressed = (unsigned char *)attach_memory_block(FILE, 0, 1);
	t_data_info *info = (t_data_info *)attach_memory_block(FILE, 0, 2);
	unsigned char *daniel = (unsigned char *)attach_memory_block(FILE, 0, 3);


	// Parse info shared into relevant data
	t_daniel	*daniel_body = danielgorithm(daniel);


	// Decompress
	unsigned char *decompressed = decompress(compressed, info);


	// Decode
	unsigned char *decoded = decode_msg(daniel_body, decompressed, info->str_len);
	
	
	// Debug
	printf("%s\n", decoded);


	// Free memory
	destroy_all_decoder(daniel_body, decoded, decompressed);
}

void destroy_all_decoder(t_daniel *daniel_body, void *str1, void *str2)
{
	free(str1);
	free(str2);
	free(daniel_body->symbols);
	destroy_map(daniel_body->map);
	free(daniel_body);
}

