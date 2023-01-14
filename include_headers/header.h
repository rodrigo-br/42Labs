#ifndef HEADER_H
# define HEADER_H

# include <string.h> // strcat
# include <stdlib.h> // malloc
# include <stdio.h> // printf
# include <wchar.h> // wchar_t
# include <limits.h> // CHAR_BIT
# include <unistd.h> // write
# include <sys/ipc.h> // ftok
# include <sys/shm.h> // shm
# include <locale.h> // setlocale

# define OT_SIZE 256
# define FILE "test_666"

# include "occurrence_table.h"
# include "array_utils.h"
# include "huffman.h"
# include "map_symbols.h"
# include "encoder.h"
# include "decoder.h"
# include "compresser.h"
# include "shm_operations.h"
# include "bitwise.h"
# include "danielgorithm.h"

#endif