NAME = animals

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g

CC = c++

RM = rm -rf

SRCS = main.cpp AAnimal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp

OBJ = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -c $^ -o $@

debug :
	$(CC) $(FLAGS) $(SRCS) -g -o $(NAME)
clean :
		$(RM) $(OBJ)

fclean :
		$(RM) $(OBJ) $(NAME)

re: fclean all