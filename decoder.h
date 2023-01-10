#ifndef DECODER_H
# define DECODER_H


/**
 * @brief Decode function walks through the tree, following the code (0 to left
 * and 1 to right) until it arrives a leaf node. Once in a leaf node, add the
 * symbol to the decoded message and set the aux pointer to the root of the tree
 * to start the process again, but this time, from another point of the coded
 * message.
 * 
 * @param tree the root of the huffman's tree
 * @param coded_msg sequence of 0s and 1s indicating left or right
 * @return unsigned char* returns the decoded message. Same as the original
 * (before encoding).
 */
unsigned char	*decode(t_node *tree, unsigned char *coded_msg);

#endif