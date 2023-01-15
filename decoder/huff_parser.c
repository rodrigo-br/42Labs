#include "../include_headers/header.h"

static short find_spot(char c1, char c2)
{
	return (c1 == ' ' && c2 == ' ');
}

static void	fill_symbols(unsigned char **symbols, unsigned char *huff, size_t spot)
{
	size_t i = 0;

	*symbols = (unsigned char *)calloc(strlen((char *)&huff[spot + 2]), sizeof(unsigned char));
	spot += 2;
	while (huff[spot])
	{
		(*symbols)[i] = huff[spot];
		i++;
		spot ++;
	}
}

// Very dangerous. Do not touch it.
static void split_code_into_map(unsigned char *code, unsigned char **map, unsigned char *symbols)
{
	unsigned char mapped_code[20];
	size_t code_index = 0;
	size_t mapped_index = 0;
	size_t symbols_index = 0;

	bzero(mapped_code, 20);
	while (code[code_index])
	{
		mapped_code[mapped_index] = code[code_index];
		code_index++;
		mapped_index++;
		if (code[code_index] == ' ' || code[code_index] == '\0')
		{
			ft_ustrcat(map[symbols[symbols_index]], mapped_code);
			symbols_index++;
			bzero(mapped_code, 20);
			if (code[code_index] == '\0')
				return ;
			code_index++;
			mapped_index = 0;
		}
	}
}

static void	fill_map_from_huff(t_map map, unsigned char *huff, size_t spot, unsigned char *symbols)
{
	size_t i = 0; 

	unsigned char code[spot + 1];
	while (i < spot)
	{
		code[i] = huff[i];
		i++;
	}
	code[i] = '\0';
	split_code_into_map(code, map, symbols);
}

t_huff	*huffgorithm(unsigned char *huff)
{
	t_huff	*new_dani;
	size_t i = 0;

	new_dani = (t_huff *)calloc(1, sizeof(t_huff));
	while (huff[i])
	{
		if (find_spot(huff[i], huff[i + 1]))
			break;
		i++;
	}
	t_map	map = constroy_map(20);
	fill_symbols(&new_dani->symbols, huff, i);
	fill_map_from_huff(map, huff, i, new_dani->symbols);
	new_dani->map = map;
	return (new_dani);
}
