# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 09:01:49 by dimbrea           #+#    #+#              #
#    Updated: 2023/02/02 11:07:33 by ubuntu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g

CC = c++

RM = rm -rf

SRCS = \
main.cpp\
PhoneBook.class.cpp\
Contact.class.cpp\

OBJ = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean :
	$(RM) $(OBJ) $(NAME)

debug:
	$(CC) $(SRCS) $(FLAGS) -o $(NAME)

re: fclean all