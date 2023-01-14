#include "../include_headers/header.h"


unsigned char *find_symbol(t_daniel *daniel_body, unsigned char *decompressed, short int *i)
{
	unsigned char symbol[2];
	bzero(symbol, sizeof(symbol));
	short index = 0;
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

unsigned char *decode_msg(t_daniel *daniel_body, unsigned char *decompressed, short len)
{
	unsigned char *decoded;
	unsigned char *symbol;
	short i;

	decoded = (unsigned char *)calloc(len + 1, sizeof(unsigned char));
	while (*decompressed) {
		i = 0;
		while (!(symbol = find_symbol(daniel_body, decompressed, &i)))
			i++;
		ft_ustrcat(decoded, symbol);
		decompressed += i;
		
	}
	return (decoded);
}

int main(void)
{
	// read shared memory blocks
	unsigned char *compressed = (unsigned char *)attach_memory_block(FILE, 0, 1);
	t_data_info *info = (t_data_info *)attach_memory_block(FILE, 0, 2);
	unsigned char *daniel = (unsigned char *)attach_memory_block(FILE, 0, 3);


	// parse info shared into relevant data
	t_daniel	*daniel_body;
	daniel_body = danielgorithm(daniel);
	unsigned char *decompressed = decompress(compressed, info);
	// print_coded(decompressed);
	unsigned char *decoded = decode_msg(daniel_body, decompressed, info->str_len);
	printf("Decoded msg from daniboy algorithm = %s\n", decoded);
	(void)decoded;
}

