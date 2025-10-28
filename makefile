NAME=cub3d
CC=cc
FLAGS= -Wall -Wextra -Werror
SRC= src/file_extension.c src/string_utils.c src/map.c main.c
OBJ=$(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)
run:$(NAME)
	valgrind --track-origins=yes --leak-check=full -s ./$(NAME) $(map)
clean:
	rm -f $(OBJ)
fclean:clean
	rm -f $(NAME)
re:fclean all

.PHONY: all clean fclean re