# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 11:29:27 by ubuntu            #+#    #+#              #
#    Updated: 2023/02/02 14:01:36 by ubuntu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombie

FLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

RM = rm -rf

SRCS = \
newZombie.cpp\
randomChump.cpp\
Zombie.cpp\
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