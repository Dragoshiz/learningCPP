NAME = violence

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

CC = c++

RM = rm -rf

SRCS = main.cpp\
HumanA.cpp\
HumanB.cpp\
Weapon.cpp\

OBJ = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean :
	$(RM) $(OBJ)


fclean :
	$(RM) $(OBJ) $(NAME)

re: fclean all

debug :
	$(CC) $(FLAGS) $(SRCS) -g -o $(NAME)