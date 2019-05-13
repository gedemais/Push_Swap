# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gedemais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 13:09:56 by gedemais          #+#    #+#              #
#    Updated: 2019/05/13 11:57:44 by gedemais         ###   ########.fr        #
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

CC = gcc

FLAGS = -Wall -Werror -Wextra

INC = includes/main.h

CHECK = checker
CHECK_PATH = checker_prog/

PS = push_swap
PS_PATH = push_swap_prog/

LIB_PATH = libft/
LIB = libft/libft.a

all : $(LIB) $(CHECK) $(PS)

$(LIB) : $(LIB_PATH)
	@echo "Making $(GRE)Libft$(DEF)..."
	@make -C $(LIB_PATH) re

$(CHECK) : $(CHECK_PATH)
	@make -C $(CHECK_PATH)
	@mv $(CHECK_PATH)$(CHECK) ./
	@echo "$(GRA)Done !$(DEF)"

$(PS) : $(PS_PATH)
	@make -C $(PS_PATH)
	@mv $(PS_PATH)$(PS) ./
	@echo "$(GRA)Done !$(DEF)"

clean :
	@make -C $(CHECK_PATH) clean
	@make -C $(PS_PATH) clean

fclean :
	@make -C $(CHECK_PATH) fclean
	@make -C $(PS_PATH) fclean
	@rm -rf $(CHECK)
	@rm -rf $(PS)

re : fclean all
