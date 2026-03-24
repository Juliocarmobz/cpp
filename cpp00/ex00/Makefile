SRC = ./megaphone.cpp

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = ex00

OBJ = $(SRC:.c=.o)

all: ex00

ex00: $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# c++ -Wall -Wextra -Werror -std=c++98 -g megaphone.cpp