NAME	= cavalinho

DIRS	= obj, include_headers, source

SRC		= $(shell ls source/ | grep .c$)

OBJ_DIR = obj

OBJ 	= $(SRC:%.c=$(OBJ_DIR)/%.o)


CC		= cc

VPATH	= $(DIRS)

all: $(NAME)

%.o:%.c
	$(CC) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ)
		$(CC) -o $@ $(OBJ)

$(OBJ_DIR)/%.o: %.c Makefile | $(OBJ_DIR)
		$(CC) -c $< -o $@

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
