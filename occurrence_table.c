#include "occurrence_table.h"

void occurrence_table_init(int (*occurrence_table)[OT_SIZE])
{
	bzero(*occurrence_table, sizeof(*occurrence_table));
}

void count_occurrences(char *message, int (*occurrence_table)[OT_SIZE])
{
	int len_of_message = strlen(message);

	for (int i = 0; i < len_of_message; i++) {
		(*occurrence_table)[message[i]]++;
	}
}

void print_occurrence_table(int *occurrence_table)
{
	for (int i = 0; i < OT_SIZE; i++) {
		if (occurrence_table[i] != 0)
			printf("char = %c  occurences = %d\n", i, occurrence_table[i]);
	}
}

