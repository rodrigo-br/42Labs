#ifndef OCCURRENCE_TABLE_H
# define OCCURRENCE_TABLE_H

# include <string.h>
# include <stdio.h>

# define OT_SIZE 255

/**
 * @brief Initialize the occurrence table with 0 
 *  
 * @param occurrence_table a reference to the occurrence table
 */
void	occurrence_table_init(int (*occurrence_table)[OT_SIZE]);

/**
 * @brief add the number of occurrences of each character in the message
 * by accessing the index of occurrence_table related to the symbol of the
 * message.
 * 
 * @param message some string text. May include non printable characters
 * @param occurrence_table a reference to the occurence table
 */
void count_occurrences(char *message, int (*occurrence_table)[OT_SIZE]);

/**
 * @brief Count the number of symbols in the occurrence table
 * 
 * @param occurrence_table int *
 * @return the number of different symbols in the message, also the same
 * number of initial nodes.
 */
int get_n_of_symbols(int *occurrence_table);

/**
 * @brief A debug function that print out the occurrence table in the
 * standard output
 * 
 * @param occurrence_table int *
 */
void print_occurrence_table(int *occurrence_table);

#endif