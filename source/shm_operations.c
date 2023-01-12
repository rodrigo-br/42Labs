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