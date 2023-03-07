NAME = bureau

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

CC = c++

RM = rm -rf

SRCS = main.cpp Bureaucrat.cpp Form.cpp

OBJ = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CC) $(FLAGS) -c $^ -o $@

debug :
	$(CC) $(FLAGS) $(SRCS) -g -o debug
clean :
		$(RM) $(OBJ)

fclean :
		$(RM) $(OBJ) $(NAME) debug

re: fclean all