#include "../include_headers/header.h"

static unsigned char	*get_bit_code(t_map map, unsigned char c)
{
	return (map[c]);
}

unsigned char	*encode(t_map map, unsigned char *str)
{
	int		size = get_code_size(map, str);
	unsigned char	*encoded = calloc((size + 1), sizeof(unsigned char));
	int		i = 0;

	encoded[size] = '\0';
	while (str[i])
	{
		ft_ustrcat(encoded, get_bit_code(map, str[i]));
		i++;
	}

	return (encoded);
}