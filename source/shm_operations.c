#include "../include_headers/header.h"

#define ERROR -1

/**
 * @brief Get the key at specified segment and returns the shared memory block
 * of the specified size. If the block doesn't exist, it creates it.
 * 
 * @param file char *
 * @param size int
 * @param segment int
 * @return Returns a shared block id as int
 */
static int get_shared_block(char *file, int size, int segment)
{
	key_t key;

	key = ftok(file, segment);
	if (key == ERROR)
		return (printf("11"), ERROR);
	return (shmget(key, size, 0644 | IPC_CREAT));
}

void 	*attach_memory_block(char *file, int size, int segment)
{
	int 			shared_block_id = get_shared_block(file, size, segment);

	if (shared_block_id == ERROR)
		return (printf("21"), NULL);
	return (shmat(shared_block_id, NULL, 0));
}

short detach_memory_block(void *block)
{
	return (shmdt(block) != ERROR);
}

short destroy_memory_block(char *file, int segment)
{
	int shared_block_id = get_shared_block(file, 0, segment);

	if (shared_block_id == ERROR)
		return (printf("38"), 0);
	return (shmctl(shared_block_id, IPC_RMID, NULL) != ERROR);
}

int calculate_size(t_map map, int n_of_symbols)
{
	int size = 0;

	for (int i = 0; i < OT_SIZE; i++)
	{
		size += strlen((char *)map[i]);
	}
	size += (n_of_symbols) + 1;
	return (size);
}

void	ft_ustrcat(unsigned char *dst, unsigned char *src)
{
	size_t	index;
	size_t	index_aux;

	index = 0;
	index_aux = 0;
	while (dst[index])
		index++;
	while (src[index_aux])
	{
		dst[index] = src[index_aux];
		index++;
		index_aux++;
	}
	dst[index] = '\0';
}

void	put_map_in_daniel(unsigned char **daniel, t_map map)
{
	int index = 0;

	while (map[index])
	{
		if (strlen((char *)map[index]))
		{
			ft_ustrcat(*daniel, map[index]);
			ft_ustrcat(*daniel, (unsigned char *)" ");
		}
		index++;
	}
	ft_ustrcat(*daniel, (unsigned char *)" ");
}

void	put_symbols_in_daniel(unsigned char **daniel, int (occurrence_table)[OT_SIZE])
{
	int i = 0;
	
	while (i < OT_SIZE)
	{
		if (occurrence_table[i])
		{
			unsigned char str_convert[2];
			str_convert[0] = i;
			str_convert[1] = '\0';
			ft_ustrcat(*daniel, str_convert);
		}
		i++;
	}
}

void	put_things_in_daniel(unsigned char **daniel, t_map map, int (occurrence_table)[OT_SIZE])
{
	put_map_in_daniel(daniel, map);
	put_symbols_in_daniel(daniel, occurrence_table);
}

void	ask_for_delete_shm(void)
{
	char c;
	printf("(d) destroy memory\n(other) continue\n");
	scanf(" %c", &c);
	if (c == 'd')
	{
		destroy_memory_block(FILE, 1);
		destroy_memory_block(FILE, 2);
		destroy_memory_block(FILE, 3);
	}
}