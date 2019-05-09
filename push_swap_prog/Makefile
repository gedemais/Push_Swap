# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gedemais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 13:20:21 by gedemais          #+#    #+#              #
#    Updated: 2019/05/09 12:25:16 by gedemais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Werror -Wextra

INC = includes/push_swap.h

SRCS_NAME = main.c\
			apply.c\
			list.c\
			moves.c\
			utils.c\
			selection_sort.c\
			three_sort.c\
			sort_stuff.c\
			tab.c\
			buff.c\
			qsort.c\
			moves_bis.c\
			parsing.c

SRCS_PATH = srcs/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = obj/

OBJ = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(SRCS_NAME:.c=.o))

LIB = ../libft/libft.a

all : $(NAME)

$(NAME) : $(LIB) $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIB)
	
$(LIB) : ../libft/
	make re -C libft/

$(OBJS) : $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)
	@mkdir -p $(OBJS_PATH)
	@mv $(OBJ) $(OBJS_PATH)

fsanitize:
	$(CC) $(FLAGS) -g3 -fsanitize=address $(SRCS) $(LIB)
	@mv a.out ../

clean :
	@rm -rf $(OBJS_PATH)

fclean :
	@rm -rf $(NAME)

re : fclean all
