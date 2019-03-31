# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gedemais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/27 19:17:23 by gedemais          #+#    #+#              #
#    Updated: 2019/03/28 13:03:00 by gedemais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXE = push_swap

EXE_PATH = p_s/

NAME = checker

NAME_PATH = check/

INC = includes/push_swap.h

all : $(NAME) $(EXE)

$(NAME) : $(NAME_PATH)
	@make -C $(NAME_PATH)
	@mv $(NAME_PATH)$(NAME) ./

$(EXE) : $(EXE_PATH)
	@make -C $(EXE_PATH)
	@mv $(EXE_PATH)$(EXE) ./

clean :
	@make clean -C $(EXE_PATH)
	@make clean -C $(NAME_PATH)

fclean :
	@make fclean -C $(EXE_PATH)
	@make fclean -C $(NAME_PATH)

re : fclean all
