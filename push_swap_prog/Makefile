CC = gcc
CFLAGS = -Weverything -Wall -Werror -Wextra

ifneq (,$(filter debug, $(MAKECMDGOALS)))
CFLAGS+=-g3 -fsanitize=address
endif

NAME = push_swap

SRCS_NAME = 	main.c\
		parsing.c\
		start_check.c\
		selection_sort.c\
		utils.c\
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

SRCS_PATH = srcs/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIB_PATH = ../libft/

LIB = $(LIB_PATH)libft.a

all: $(NAME) $(LIB)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

$(OBJS): $(SRCS) $(LIB)
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CFLAGS) -c $(SRCS)
	@mv $(OBJS_NAME) $(OBJS_PATH)

debug: all

clean:
	@rm -rf $(OBJS_PATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
