#include <stdio.h>
#include "occurrence_table.h"

int main (void)
{
	int occurrence_table[OT_SIZE];
	char *str = "cavalinho";

	occurrence_table_init(&occurrence_table);
	count_occurrences(str, &occurrence_table);
	print_occurrence_table(occurrence_table);
}
