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

# define OT_SIZE 255

# include "occurrence_table.h"
# include "array_utils.h"
# include "huffman.h"
# include "map_symbols.h"
# include "encoder.h"
# include "decoder.h"
# include "compresser.h"
# include "shm_operations.h"

#endif