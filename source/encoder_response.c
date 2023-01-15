#include "../include_headers/header.h"

unsigned long	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

double	compression_ratio(size_t comp, size_t uncomp)
{
	return ((double)(uncomp - comp) / (double)(uncomp) * (double)100.0);
}

void	check_for_results(void)
{
	unsigned char	*msg = (unsigned char *)attach_memory_block(FILE, 0, 4);
	t_result		*result = (t_result *)attach_memory_block(FILE, 0, 5);
	if (!msg || !result)
	{
		error(EXIT_FAILURE);
		exit(EXIT_FAILURE);
	}
	print_result(msg, result);
	detach_memory_block(msg);
	detach_memory_block(result);
	destroy_memory_block(FILE, 4);
	destroy_memory_block(FILE, 5);
	exit(EXIT_SUCCESS);
}

void print_result(unsigned char *msg, t_result *result)
{
	printf("%s\n", msg);
	printf("compressed file size in bits: %ld\n", result->compressed_size);
	printf("uncompressed file size in bits: %ld\n", result->uncompressed_size);
	printf("Time: %f seconds to decompress\n", result->time_to_decompress);
	printf("Aditional data size: %ld bits\n", result->aditional_data_size);
	if (result->compressed_size + result->aditional_data_size > result->uncompressed_size)
	{
		printf("COMPRESSION NOT WORTH IT. INPUT SIZE TOO SMALL\n");
		return ;
	}
	printf("Compression ratio = %.2f%%\n",
			compression_ratio(result->compressed_size, result->uncompressed_size));
	printf("Compression ratio considering aditional data shared: %.2f%%\n",
			compression_ratio(result->compressed_size + result->aditional_data_size,
								result->uncompressed_size));
}

