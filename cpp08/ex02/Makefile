NAME = mutant

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

CC = c++

RM = rm -rf

SRCS = main.cpp

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