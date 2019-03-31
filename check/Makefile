# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gedemais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/27 20:07:30 by gedemais          #+#    #+#              #
#    Updated: 2019/03/29 11:21:49 by gedemais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = checker

SRCS_PATH = srcs/

SRCS_NAME = main.c\
			list.c\
			moves.c\
			check.c\
			parsing.c\

LIB = ../libft/libft.a

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = obj/

OBJS_NAME = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

INC = includes/checker.h

all : $(NAME)

$(NAME) : $(OBJS) $(INC)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

$(OBJS) : $(SRCS) $(INC)
		@$(CC) $(CFLAGS) -c $(SRCS)
		@mkdir -p $(OBJS_PATH)
		@mv $(OBJS_NAME) obj/

clean :
		@rm -rf $(OBJS)

fclean : clean
		@rm -rf $(NAME)

re : fclean all
