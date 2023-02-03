NAME = zombieHorde

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

CC = c++

RM = rm -rf

SRCS = \
Zombie.cpp\
zombieHorde.cpp\
main.cpp\

OBJ = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean :
	$(RM) $(OBJ)

debug :
	$(CC) $(FLAGS) $(SRCS) -g -o $(NAME)

fclean :
	$(RM) $(OBJ) $(NAME)

re: fclean all