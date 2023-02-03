# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 13:39:50 by dimbrea           #+#    #+#              #
#    Updated: 2023/02/02 11:24:01 by ubuntu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

FLAGS = -Wall -Wextra -Werror -std=c++98

CC = c++

RM = rm -rf

SRCS = megaphone.cpp

OBJ = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean :
	$(RM) $(OBJ) $(NAME)


re: fclean all