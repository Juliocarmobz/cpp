SRC = ./main.cpp ./ClassClapTrap.cpp ./ClassScavTrap.cpp

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = scavtrap

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re