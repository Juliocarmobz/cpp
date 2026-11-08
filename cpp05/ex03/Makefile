SRC = ./main.cpp ./Bureaucrat.cpp ./AForm.cpp ./ShrubberyCreationForm.cpp ./RobotomyRequestForm.cpp ./PresidentialPardonForm.cpp ./Intern.cpp

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

NAME = aform

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