#include "../include_headers/header.h"

static int get_shared_block(char *file, int size, int segment)
{
	key_t key = ftok(file, segment);

	if (key == -1)
	{
		perror("ftok");
		return (-1);
	}
	return (shmget(key, size, 0644 | IPC_CREAT));
}

char attach_shm(char *file, int size, int segment)
{
	int		id = get_shared_block(file, size, segment);
	char	byte_data;

	if (id == -1)
		return ('\0');
	byte_data = *(char *)shmat(id, NULL, segment);
	if (byte_data == -1)
	{
		perror("shmat");
		return ('\0');
	}
	return (byte_data);
}
