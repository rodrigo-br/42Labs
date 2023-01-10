NAME = cavalinho

SRC = $(shell ls source/ | grep .c$)

OBJ = $(addprefix source/, $(SRC:.c=.o))

all: $(NAME)

CC	= cc

%.o:%.c
	$(CC) -c $< -o $@

$(NAME): $(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re:		fclean all
