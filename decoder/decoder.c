#include "../include_headers/header.h"

static unsigned char *find_symbol(t_daniel *daniel_body, unsigned char *decompressed, size_t *i)
{
	unsigned char symbol[2];
	bzero(symbol, sizeof(symbol));
	size_t index = 0;
	while (daniel_body->symbols[index])
	{
		if (!strncmp((char *)daniel_body->map[daniel_body->symbols[index]], (char *)decompressed, strlen((char *)daniel_body->map[daniel_body->symbols[index]])))
		{
			symbol[0] = daniel_body->symbols[index];
			*i += strlen((char *)daniel_body->map[daniel_body->symbols[index]]);
			return ((unsigned char *)strdup((char *)symbol));
		}
		index++;
	}
	return (NULL);
}

void decode_msg(t_daniel *daniel_body, unsigned char *decompressed, unsigned char **decoded)
{
	unsigned char *symbol;
	size_t i;

	while (*decompressed) {
		i = 0;
		while (!(symbol = find_symbol(daniel_body, decompressed, &i)))
			i++;
		ft_ustrcat(*decoded, symbol);
		free(symbol);
		decompressed += i;
	}
}