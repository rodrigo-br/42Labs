#ifndef DECODER_H
# define DECODER_H

# include "header.h"

void decode_msg(t_huff *huff_body, unsigned char *decompressed, unsigned char **decoded);

#endif