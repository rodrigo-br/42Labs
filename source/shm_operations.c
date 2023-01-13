#include "../include_headers/header.h"

#define ERROR -1

static int get_shared_block(char *file, int size, int segment)
{
	key_t key;

	key = ftok(file, segment);
	if (key == ERROR)
		return (printf("11"), ERROR);
	return (shmget(key, size, 0644 | IPC_CREAT));
}

char *attach_memory_block(char *file, int size, int segment)
{
	int shared_block_id = get_shared_block(file, size, segment);
	char *result;

	if (shared_block_id == ERROR)
		return (printf("21"), NULL);
	result = shmat(shared_block_id, NULL, 0);
	if (result == (char *)ERROR)
		return (printf("24"), NULL);
	return (result);
}

t_data_info *attach_memory_block_daniel(char *file, int size, int segment)
{
	int shared_block_id = get_shared_block(file, size, segment);
	t_data_info *result;

	if (shared_block_id == ERROR)
		return (printf("21"), NULL);
	result = shmat(shared_block_id, NULL, 0);
	return (result);
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

void	put_map_in_daniel(char **daniel, t_map map)
{
	int index = 0;

	while (map[index])
	{
		if (strlen((char *)map[index]))
		{
			strcat(*daniel, (char *)map[index]);
			strcat(*daniel, " ");
		}
		index++;
	}
	strcat(*daniel, " ");
}

void	put_symbols_in_daniel(char **daniel, int (occurrence_table)[OT_SIZE])
{
	int i = 0;
	
	while (i < OT_SIZE)
	{
		if (occurrence_table[i])
		{
			char str_convert[2];
			str_convert[0] = i;
			str_convert[1] = '\0';
			strcat(*daniel, str_convert);
		}
		i++;
	}
}

void	put_things_in_daniel(char **daniel, t_map map, int (occurrence_table)[OT_SIZE])
{
	put_map_in_daniel(daniel, map);
	put_symbols_in_daniel(daniel, occurrence_table);
}
