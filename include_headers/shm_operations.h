#ifndef SHM_OPERATIONS_H
# define SHM_OPERATIONS_H

typedef struct s_data_info
{
	unsigned short	str_len;
	unsigned short	byte_len;
} t_data_info;

short		destroy_memory_block(char *file, int segment);
short		detach_memory_block(void *block);
char		*attach_memory_block(char *file, int size, int segment);
t_data_info *attach_memory_block_daniel(char *file, int size, int segment);
int			calculate_size(t_map map, int n_of_symbols);
void		put_things_in_daniel(char **daniel, t_map map, int (occurrence_table)[OT_SIZE]);

#endif