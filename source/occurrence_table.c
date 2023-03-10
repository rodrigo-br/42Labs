#include "../include_headers/header.h"

void count_occurrences(unsigned char *message, int (*occurrence_table)[OT_SIZE])
{
	int len_of_message = strlen((char *)message);

	for (int i = 0; i < len_of_message; i++) {
		(*occurrence_table)[message[i]]++;
	}
}

int get_n_of_symbols(int *occurrence_table)
{
	int symbols = 0;

	for (int i = 0; i < OT_SIZE; i++) {
		if (occurrence_table[i] != 0)
			symbols++;
	}
	return symbols;
}

void print_occurrence_table(int *occurrence_table)
{
	for (unsigned char i = 0; i < (unsigned char)(OT_SIZE - 1); i++) {
		if (occurrence_table[i] != 0)
			printf("char(ASCI) = %c  char(DEC) = %3d  occurences = %d\n", i, i, occurrence_table[i]);
	}
	printf("Total number of symbols: %d\n", get_n_of_symbols(occurrence_table));
}
