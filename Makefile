NAME_ENCODER	=	encoder_program

SRC_ENCODER		=	array_utils.c bitwise.c compresser.c encoder.c huffman.c \
					map_symbols.c occurrence_table.c shm_operations.c reader.c

MAIN_ENCODER 	=	main.c

OBJ_ENCODER		=	$(addprefix source/, $(SRC_ENCODER:.c=.o))
OBJ_ENCODER 	+=	$(addprefix source/, $(MAIN_ENCODER:.c=.o))

NAME_DECODER	=	decoder_program

SRC_DECODER		=	main_decoder.c danielgorithm.c decompresser.c decoder.c

OBJ_DECODER		=	$(addprefix decoder/, $(SRC_DECODER:.c=.o))
OBJ_DECODER 	+=	$(addprefix source/, $(SRC_ENCODER:.c=.o))

CCFLAGS			=	-g3 -Wall -Wextra -Werror

RM				=	rm -f

all:	$(NAME_ENCODER)	$(NAME_DECODER) clean

.c.o:
	cc $(CCFLAGS) -c $< -o $(<:.c=.o)	

$(NAME_ENCODER): $(OBJ_ENCODER) $(HEADER)
	cc $(CCFLAGS) -o $(NAME_ENCODER) $(OBJ_ENCODER)

$(NAME_DECODER): $(OBJ_DECODER) $(HEADER)
	cc $(CCFLAGS) -o $(NAME_DECODER) $(OBJ_DECODER)

clean:
	$(RM) $(OBJ_ENCODER)
	$(RM) $(OBJ_DECODER)

fclean: clean
	$(RM) $(NAME_ENCODER)
	$(RM) $(NAME_DECODER)

re: fclean all

push:
		git push
		git push github

.PHONY: all clean fclean re