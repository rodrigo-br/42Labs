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
	delete_memory_blocks();
	exit(EXIT_SUCCESS);
}

void print_result(unsigned char *msg, t_result *result)
{
	printf("Original message after compression and decompression:\n%s\n", msg);
	printf("\nInfos:\n");
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


void help(void)
{
	printf(
	"First you have to call the encoder program with at least 1 argument. \
	\nIf the argument its a file that exists, the content of the file will be \
compressed. \
	\nIf the argument doesn't exist or fail to open, the argument will be \
treated as a string and compressed. \
	\nYou can use multiple arguments and mix files and text between them. \
	\nOnce the encoder is done with compression, you can call the decoder \
	\nprogram to decompress it all and create new shared memory blocks. \
	\nWhen the decoder is finish running, You can call the encoder again without \
argumentos to show in the output the message decompressed and the results. \
	\n\nExample of Use: \
	\nmake \
	\n./encoder_program Makefile README.md \"cavalinho ao vento na chuva\" \
	\n./decoder_program \
	\n./encoder_program \
	\n");
}

