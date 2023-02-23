NAME = icepp

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

CC = c++

RM = rm -rf

SRCS = main.cpp \
AMateria.cpp \
Cure.cpp Ice.cpp \
ICharacter.cpp \
IMateriaSource.cpp \
MateriaSource.cpp \
Character.cpp\

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