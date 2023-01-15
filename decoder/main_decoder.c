#include "../include_headers/header.h"

void destroy_all_decoder(t_daniel *daniel_body, void *str, unsigned char *decoded, t_result *result);


int main(void)
{
	// Start timer
	size_t start = time_now();


	// Read shared memory blocks
	unsigned char *compressed = (unsigned char *)attach_memory_block(FILE, 0, 1);
	t_data_info *info = (t_data_info *)attach_memory_block(FILE, 0, 2);
	unsigned char *daniel = (unsigned char *)attach_memory_block(FILE, 0, 3);


	// Parse info shared into relevant data
	t_daniel	*daniel_body = danielgorithm(daniel);


	// Decompress
	unsigned char *decompressed = decompress(compressed, info);


	// Decode (Sharing)
	unsigned char *decoded = (unsigned char *)attach_memory_block(FILE, info->str_len + 1, 4);
	decode_msg(daniel_body, decompressed, &decoded);


	// Stop timer
	size_t end = time_now();


	// Share Back to Encode
	t_result *result = attach_memory_block(FILE, sizeof(t_result), 5);


	// Create result struct (SHARE THIS)
	result->compressed_size = strlen((char *)decompressed);
	result->uncompressed_size = strlen((char *)decoded) * 8;
	result->time_to_decompress = (end - start) / 1000.0f;
	result->aditional_data_size = (sizeof(info) * 8) + (strlen((char *)daniel) * 8);


	// Free memory
	destroy_all_decoder(daniel_body, decompressed, decoded, result);
	printf("Decoded sucessfully!\n");
}

void destroy_all_decoder(t_daniel *daniel_body, void *str, unsigned char *decoded, t_result *result)
{
	// Free
	free(str);
	free(daniel_body->symbols);
	destroy_map(daniel_body->map);
	free(daniel_body);

	// Detach
	detach_memory_block(decoded);
	detach_memory_block(result);

	// Destroy
	destroy_memory_block(FILE, 1);
	destroy_memory_block(FILE, 2);
	destroy_memory_block(FILE, 3);
}

