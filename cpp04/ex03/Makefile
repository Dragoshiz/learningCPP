NAME = icepp

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

CC = c++

RM = rm -rf

SRCS = main.cpp \
AMateria.cpp \
Cure.cpp \
Ice.cpp \
MateriaSource.cpp \
Character.cpp \

TEST = test.cpp \
AMateria.cpp \
Cure.cpp \
Ice.cpp \
MateriaSource.cpp \
Character.cpp \

OBJ = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

test : $(TEST)
	$(CC) $(FLAGS) $(TEST) -g 
%.o : %.cpp
	$(CC) $(FLAGS) -c $^ -o $@

debug :
	$(CC) $(FLAGS) $(SRCS) -g -o $(NAME)
clean :
		$(RM) $(OBJ) a.out

fclean :
		$(RM) $(OBJ) $(NAME) a.out

re: fclean all