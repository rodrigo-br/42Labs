#ifndef HEADER_H
# define HEADER_H

# include <string.h>	// strcat
# include <stdlib.h>	// malloc
# include <stdio.h>		// printf
# include <wchar.h>		// wchar_t
# include <limits.h>	// CHAR_BIT
# include <unistd.h>	// write
# include <sys/ipc.h>	// ftok
# include <sys/shm.h>	// shm
# include <locale.h>	// setlocale
# include <fcntl.h>		// open
# include <sys/time.h>	// gettimeofday

# define OT_SIZE 256
# define FILE "capybara.svg"

# include "occurrence_table.h"
# include "array_utils.h"
# include "huffman.h"
# include "map_symbols.h"
# include "compresser.h"
# include "encoder.h"
# include "shm_operations.h"
# include "bitwise.h"
# include "huff_parser.h"
# include "decompresser.h"
# include "encoder_response.h"
# include "decoder.h"
# include "reader.h"

#endif