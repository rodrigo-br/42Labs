#include "../include_headers/header.h"

static int get_shared_block(char *file, int size)
{
	key_t key = ftok(file, 1);

	if (key == -1)
	{
		perror("ftok");
		return (-1);
	}
	return (shmget(key, size, 0644 | IPC_CREAT));
}

char	*attach_str_shm(char *file, int size)
{
	int		id = get_shared_block(file, size);
	char	*byte_data;

	if (id == -1)
	{
		perror("get_shared_block");
		return (NULL);
	}
	byte_data = (char *)shmat(id, NULL, 0);
	if (byte_data == (char *)-1)
	{
		perror("shmat");
		return (NULL);
	}
	return (byte_data);
}

// t_data_info  *attach_info_shm(char *file, int size)
// {
// 	int		id = get_shared_block(file, size, 60);
// 	t_data_info  *info;

// 	if (id == -1)
// 	{
// 		perror("get_shared_block");
// 		return (NULL);
// 	}
// 	info = (t_data_info *)shmat(id, NULL, 0);
// 	if (!info)
// 	{
// 		perror("shmat");
// 		return (NULL);
// 	}
// 	return (info);
// }
