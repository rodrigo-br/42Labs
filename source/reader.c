#include "../include_headers/header.h"


unsigned char *ft_ustrjoin(unsigned char *s1, unsigned char *s2)
{
	unsigned char	*new_str;
	size_t	len;

	if (!s1 && s2)
		return (s2);
	else if (!s2 && s1)
		return (s1);
	else if (!s1 && !s2)
		return (NULL);
	len = strlen((char *)s1) + strlen((char *)s2);
	new_str = (unsigned char *)calloc(sizeof(unsigned char), len + 1);
	if (!new_str)
		return (NULL);
	ft_ustrcat(new_str, s1);
	ft_ustrcat(new_str, s2);
	free(s1);
	return (new_str);
}

unsigned char *read_until_eof(int fd)
{
	unsigned char *full_text = (unsigned char *)strdup("");
	unsigned char auxiliar[2];
	bzero(auxiliar, sizeof(auxiliar));

	while (read(fd, &auxiliar, 1) > 0)
	{
		full_text = ft_ustrjoin(full_text, auxiliar);
	}
	return (full_text);
}

unsigned char *read_one_file(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file %s\nEncoding filename as text.", filename);
		return ((unsigned char *)strdup(filename));
	}
	return (read_until_eof(fd));
}

unsigned char *read_files(int argc, char **argv)
{
	unsigned char *str = (unsigned char *)strdup("");
	int i = 1; // 0 is the name of the program

	if (argc == 1) {
		printf("No file to read\n");
		return NULL;
	}
	while (i < argc)
	{
		str = ft_ustrjoin(str, read_one_file(argv[i]));
		i++;
	}
	return (str);
}