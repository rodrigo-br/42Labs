#include "../include_headers/header.h"


static unsigned char	*ustrjoin(unsigned char *s1, unsigned char *s2)
{
	unsigned char	*new_str;
	size_t	len;

	if (!s1 && s2)
		return ((unsigned char *)strdup((char *)s2));
	else if (!s2 && s1)
		return ((unsigned char *)strdup((char *)s1));
	else if (!s1 && !s2)
		return (NULL);
	len = strlen((char *)s1) + strlen((char *)s2);
	new_str = (unsigned char *)calloc(len + 1, sizeof(unsigned char));
	if (!new_str)
		return (NULL);
	ft_ustrcat(new_str, s1);
	ft_ustrcat(new_str, s2);
	free(s1);
	free(s2);
	return (new_str);
}

static unsigned char *read_file(int fd)
{
	unsigned char *full_text = (unsigned char *)strdup("");
	unsigned char aux[2];

	bzero(aux, 2);
	while (read(fd, &aux[0], 1) > 0)
	{
		full_text = ustrjoin(full_text, (unsigned char *)strdup((char *)aux));
	}
	close(fd);
	return (full_text);
}

static unsigned char *text_or_file(char *filename)
{
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		printf("%s is not a file. Decoding as text instead.\n", filename);
		return ((unsigned char *)strdup(filename));
	}
	return (read_file(fd));
}

unsigned char *handle_input(int argc, char **argv)
{
	unsigned char *full_str = (unsigned char *)strdup("");

	int i = 1;// 0 is the name of the program
	while (i < argc)
	{
		full_str = ustrjoin(full_str, text_or_file(argv[i]));
		i++;
	}
	return (full_str);
}