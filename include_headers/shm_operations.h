#ifndef SHM_OPERATIONS_H
# define SHM_OPERATIONS_H

typedef struct s_data_info
{
	size_t	str_len;
	size_t	byte_len;
} t_data_info;

/**
 * @brief	Complete free and destroy the memory block
 * 
 * @param file char *
 * @param segment int
 * @return returns 1 if successful, 0 otherwise
 */
short	destroy_memory_block(char *file, int segment);

/**
 * @brief detaches the shared memory segment (just calling Mr. Shmdt)
 * 
 * @param block 
 * @return returns 1 if successful, 0 otherwise
 */
short	detach_memory_block(void *block);

/**
 * @brief  Get the key at specified segment and returns the shared memory block
 *  of the specified size. If the block doesn't exist, it creates it.
 * after that, Attach shared memory segment to a variable and return it as void
 * 
 * @param file char *
 * @param size int
 * @param segment int
 * @return returns the shared memory block as void
 */
void	*attach_memory_block(char *file, int size, int segment);

/**
 * @brief	calculate the size needed to store the map and symbols 
 * in the shared memory
 * 
 * @param map t_map
 * @param n_of_symbols int 
 * @return Returns the size in bytes as int
 */
int		calculate_size(t_map map, int n_of_symbols);

/**
 * @brief wrap map and symbols in a single unsigned char * to be stored
 * in the shared memory
 * 
 * @param huff reference of unsigned char *
 * @param map t_map
 * @param occurrence_table int[OT_SIZE]
 */
void	put_things_in_huff(unsigned char **huff, t_map map, int (occurrence_table)[OT_SIZE]);

/**
 * @brief recoding strcat for unsigned char * inputs
 * 
 * @param dst unsigned char *
 * @param src unsigned char *
 */
void	ft_ustrcat(unsigned char *dst, unsigned char *src);

/**
 * @brief Simple function to print the coded message puting space every 8 chars
 * to make it easier to read and count the bytes
 * 
 * @param str unsigned char *
 */
void print_coded(unsigned char *str);


#endif