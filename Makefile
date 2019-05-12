# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gedemais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 13:09:56 by gedemais          #+#    #+#              #
#    Updated: 2019/05/12 20:47:13 by gedemais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Werror -Wextra

INC = includes/main.h

CHECK = checker
CHECK_PATH = checker_prog/

PS = push_swap
PS_PATH = push_swap_prog/

all : $(CHECK) $(PS)

$(CHECK) : $(CHECK_PATH)
	@make -C $(CHECK_PATH)
	@mv $(CHECK_PATH)$(CHECK) ./


$(PS) : $(PS_PATH)
	@make -C $(PS_PATH)
	@mv $(PS_PATH)$(PS) ./

clean :
	@make -C $(CHECK_PATH) clean
	@make -C $(PS_PATH) clean

fclean :
	@make -C $(CHECK_PATH) fclean
	@make -C $(PS_PATH) fclean
	@rm -rf checker
	@rm -rf push_swap

re : fclean all
