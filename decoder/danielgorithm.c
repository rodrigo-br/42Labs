#include "../include_headers/header.h"

static short find_spot(char c1, char c2)
{
	return (c1 == ' ' && c2 == ' ');
}

static void	fill_symbols(unsigned char **symbols, unsigned char *daniel, size_t spot)
{
	size_t i = 0;

	*symbols = (unsigned char *)calloc(strlen((char *)&daniel[spot + 2]), sizeof(unsigned char));
	spot += 2;
	while (daniel[spot])
	{
		(*symbols)[i] = daniel[spot];
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

static void	fill_map_from_daniel(t_map map, unsigned char *daniel, size_t spot, unsigned char *symbols)
{
	size_t i = 0; 

	unsigned char code[spot + 1];
	while (i < spot)
	{
		code[i] = daniel[i];
		i++;
	}
	code[i] = '\0';
	split_code_into_map(code, map, symbols);
}

t_daniel	*danielgorithm(unsigned char *daniel)
{
	t_daniel	*new_dani;
	size_t i = 0;

	new_dani = (t_daniel *)calloc(1, sizeof(t_daniel));
	while (daniel[i])
	{
		if (find_spot(daniel[i], daniel[i + 1]))
			break;
		i++;
	}
	t_map	map = constroy_map(20);
	fill_symbols(&new_dani->symbols, daniel, i);
	fill_map_from_daniel(map, daniel, i, new_dani->symbols);
	new_dani->map = map;
	return (new_dani);
}
