#include "../include_headers/header.h"

short	char_test(char c, size_t position)
{
	return (c & (1 << position));
}

void	char_description(char c)
{
	for (size_t i = 0; i < CHAR_BIT; i++) {
		printf("%d", char_test(c, i) ? 1 : 0);
	}
	printf("\n");
}
