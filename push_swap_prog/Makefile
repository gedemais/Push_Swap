# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gedemais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 13:20:21 by gedemais          #+#    #+#              #
#    Updated: 2019/05/13 11:27:31 by gedemais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF = \033[0m
GRA = \033[1m
SOU = \033[4m
BLI = \033[5m
BLA = \033[30m
RED = \033[31m
GRE = \033[32m
YEL = \033[33m
BLU = \033[34m
PUR = \033[35m
CYA = \033[36m
WHI = \033[37m
ORG = \033[1;31m
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
			two_sort.c\
			parsing.c

SRCS_PATH = srcs/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = obj/

OBJ = $(SRCS_NAME:.c=.o)

OBJS = $(addprefix $(OBJS_PATH), $(SRCS_NAME:.c=.o))

LIB = ../libft/libft.a

all : $(NAME)

$(NAME) : $(LIB) $(OBJS)
	@echo "Making $(RED)Push_Swap$(DEF)..."
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIB)
	
$(LIB) : ../libft/
	make re -C libft/

$(OBJS) : $(SRCS)
	@$(CC) $(FLAGS) -c $(SRCS)
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
