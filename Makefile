NAME	= cavalinho

DIRS	= obj, include_headers, source

SRC		= $(shell ls source/ | grep .c$)

OBJ_DIR = obj

OBJ 	= $(SRC:%.c=$(OBJ_DIR)/%.o)

CC		= cc

FLAGS	= -g3 -Wall -Wextra -Werror

VPATH	= $(DIRS)

all: $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ)
		$(CC) $(FLAGS) -o $@ $(OBJ)

$(OBJ_DIR)/%.o: %.c Makefile | $(OBJ_DIR)
		$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
			mkdir -p $@

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re:		fclean all

push:
		git push
		git push github

val:	re
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)
