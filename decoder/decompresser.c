#include "../include_headers/header.h"

unsigned char *decompress(unsigned char *compressed, t_data_info *info)
{
	unsigned char *decompressed;
	
	decompressed = (unsigned char *)calloc(info->str_len + 1, sizeof(unsigned char));
	if (!decompressed)
		return (NULL);
	
	for (short i = 0; i < info->str_len; i++) {
		if (bit_test(compressed, i))
			memset(decompressed + i, '1', 1);
		else
			memset(decompressed + i, '0', 1);
	}
	return (decompressed);
}
