#include "../include_headers/header.h"

void destroy_all_decoder(t_daniel *daniel_body, void *str);

unsigned long	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

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


	// Decode (SHARE THIS)
	unsigned char *decoded = (unsigned char *)attach_memory_block(FILE, info->str_len + 1, 4);
	decode_msg(daniel_body, decompressed, &decoded);


	// Stop timer
	size_t end = time_now();


	// Share Back to Encode
		//still testing
	t_result *result = attach_memory_block(FILE, sizeof(t_result), 5);


	// Create result struct (SHARE THIS)
	result->compressed_size = strlen((char *)decompressed);
	result->uncompressed_size = strlen((char *)decoded) * 8;
	result->time_to_decompress = (end - start) / 1000.0f;
	result->aditional_data_size = (sizeof(info) * 8) + (strlen((char *)daniel) * 8);


	// Debug
	// printf("%s\n", decoded);
	// printf("compressed file size in bits: %ld\n", result->compressed_size);
	// printf("uncompressed file size in bits: %ld\n", result->uncompressed_size);
	// printf("Time: %f seconds to decompress\n", result->time_to_decompress);
	// printf("Compression ratio = %.2f%%\n",
	// 		compression_ratio(result->compressed_size, result->uncompressed_size));
	// printf("Aditional data size: %ld bits\n", result->aditional_data_size);
	// if (result->compressed_size + result->aditional_data_size > result->uncompressed_size)
	// 	printf("COMPRESSION NOT WORTH IT. INPUT SIZE TOO SMALL\n");
	// printf("Compression ratio considering all data shared: %.2f%%\n",
	// 		compression_ratio(result->compressed_size + result->aditional_data_size,
	// 							result->uncompressed_size));


	// Free memory
	destroy_all_decoder(daniel_body, decompressed);
	detach_memory_block(decoded);
	detach_memory_block(result);
	destroy_memory_block(FILE, 1);
	destroy_memory_block(FILE, 2);
	destroy_memory_block(FILE, 3);
}

void destroy_all_decoder(t_daniel *daniel_body, void *str)
{
	free(str);
	free(daniel_body->symbols);
	destroy_map(daniel_body->map);
	free(daniel_body);
}

