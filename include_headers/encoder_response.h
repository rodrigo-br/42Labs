#ifndef ENCODER_RESPONSE_H
# define ENCODER_RESPONSE_H


/**
 * @brief Struct to store the results of the compression, information
 * needed by the encoder to output the results correctly
 */
typedef struct s_result
{
	size_t			compressed_size;
	size_t			uncompressed_size;
	float			time_to_decompress;
	size_t			aditional_data_size;
}	t_result;

/**
 * @brief Get the epoch time now in microseconds (1s / 1000)
 * 
 * @return unsigned long Returns the time now in microseconds
 */
unsigned long	time_now(void);

/**
 * @brief Get the compression ratio
 * 
 * @param comp the new compressed size
 * @param uncomp the size of the uncompressed message
 * @return double Returns the compression ratio represented as a percentage
 */
double	compression_ratio(size_t comp, size_t uncomp);

/**
 * @brief check if theres a result to print
 * 
 */
void	check_for_results(void);

/**
 * @brief print the results of the compression
 * 
 * @param msg unsigned char * the decoded msg
 * @param result t_result * struct with the results of the compression
 */
void print_result(unsigned char *msg, t_result *result);

/**
 * @brief print the help message
 */
void help(void);

#endif