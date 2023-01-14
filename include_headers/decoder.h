#ifndef DECODER_H
# define DECODER_H

# include "header.h"

unsigned char *decode_msg(t_daniel *daniel_body, unsigned char *decompressed, size_t len);

#endif