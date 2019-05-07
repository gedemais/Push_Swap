# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gedemais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 13:20:21 by gedemais          #+#    #+#              #
#    Updated: 2019/04/29 18:19:26 by gedemais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

CC = gcc

FLAGS = -Wall -Werror -Wextra

INC = includes/checker.h

SRCS_NAME = main.c\
			apply.c\
			tab.c\
			list.c\
			utils.c\
			moves.c\
			moves_bis.c\
			parsing.c

SRCS_PATH = srcs/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = obj/

OBJ = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(SRCS_NAME:.c=.o))

LIB = ../libft/libft.a

all : $(NAME)

$(NAME) : $(LIB) $(OBJS) $(INC)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIB)
	
$(LIB) : ../libft/
	make -C ../libft/ re

$(OBJS) : $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)
	@mkdir -p $(OBJS_PATH)
	@mv $(OBJ) $(OBJS_PATH)

fsanitize :
	$(CC) $(FLAGS) -g3 -fsanitize=address $(SRCS) $(LIB)

clean :
	@rm -rf $(OBJS_PATH)

fclean :
	@rm -rf $(NAME)

re : fclean all
