#ifndef SHM_OPERATIONS_H
# define SHM_OPERATIONS_H

typedef struct s_data_info
{
	size_t	str_len;
	size_t	byte_len;
} t_data_info;

char			*attach_str_shm(char *file, int size);
t_data_info		*attach_info_shm(char *file, int size);

#endif