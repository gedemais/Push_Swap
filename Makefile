# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gedemais <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/21 22:20:41 by gedemais          #+#    #+#              #
#    Updated: 2019/07/21 23:28:07 by gedemais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS+= -Weverything -Wall -Werror -Wextra

LIB_PATH=libft/
LIB=$(LIB_PATH)libft.a

CK_NAME=checker
CK_PATH=checker_prog/
CK_SRCS_PATH=$(CK_PATH)srcs/
CK_SRCS_NAME=	main.c\
		parsing.c\
		start_check.c\
		init_stack.c\
		print_lst.c\
		run_instructions.c\
		instruction_push_swap.c\
		instruction_rotate.c\
		instruction_reverse_rotate.c\
		get_numbers.c

CK_INC=$(CK_PATH)/includes/checker.h

CK_SRCS=$(addprefix $(CK_SRCS_PATH), $(CK_SRCS_NAME))

CK_OBJS_PATH=$(CK_PATH)/obj/
CK_OBJS_NAME=$(CK_SRCS_NAME:.c=.o)
CK_OBJS=$(addprefix $(CK_OBJS_PATH), $(CK_OBJS_NAME))

CK_INC_PATH=checker_prog/includes/

PS_NAME=push_swap
PS_PATH=push_swap_prog/
PS_SRCS_PATH=$(PS_PATH)srcs/
PS_SRCS_NAME=	main.c\
		parsing.c\
		start_check.c\
		selection_sort.c\
		utils.c\
		partition.c\
		get_numbers.c\
		sort_processes.c\
		sort_ends.c\
		init_stack.c\
		threesort.c\
		quicksort.c\
		sort_stacks.c\
		moves_buffer.c\
		optimize_buff.c\
		instruction_push_swap.c\
		instruction_reverse_rotate.c\
		instruction_rotate.c

PS_INC=$(PS_PATH)/includes/push_swap.h

PS_SRCS=$(addprefix $(PS_SRCS_PATH), $(PS_SRCS_NAME))

PS_OBJS_PATH=$(PS_PATH)/obj/
PS_OBJS_NAME=$(PS_SRCS_NAME:.c=.o)
PS_OBJS = $(addprefix $(PS_OBJS_PATH), $(PS_OBJS_NAME))

PS_INC_PATH=push_swap_prog/includes/

INC=$(PS_INC_PATH)checker.h\
    $(CK_INC_PATH)push_swap.h

all : $(CK_NAME) $(PS_NAME)

$(LIB) : $(LIB_PATH)
	@echo "Making Libft..."
	@make -C $(LIB_PATH)

$(CK_NAME) : $(CK_OBJS)
	@$(CC) $(CFLAGS) -o $(CK_NAME) $(CK_OBJS) $(LIB)

$(CK_OBJS_PATH)%.o : $(CK_SRCS_PATH)%.c  $(CK_INC)
	@echo "Making Checker..."
	@mkdir -p $(CK_OBJS_PATH)
	@$(CC) $(CFLAGS) -c $(CK_SRCS)
	@mv $(CK_OBJS_NAME) $(CK_OBJS_PATH)

$(PS_NAME) : $(PS_OBJS)
	@$(CC) $(CFLAGS) -o $(PS_NAME) $(PS_OBJS) $(LIB)

$(PS_OBJS_PATH)%.o : $(PS_SRCS_PATH)%.c $(PS_INC)
	@echo "Making Push_swap..."
	@mkdir -p $(PS_OBJS_PATH)
	@$(CC) $(CFLAGS) -c $(PS_SRCS)
	@mv $(PS_OBJS_NAME) $(PS_OBJS_PATH)

clean :
	@rm -rf $(CK_OBJS_PATH)
	@rm -rf $(PS_OBJS_PATH)

fclean : clean
	@rm -rf push_swap.dSYM
	@rm -rf checker.dSYM
	@rm -rf $(CK_NAME)
	@rm -rf $(PS_NAME)

re : fclean all
