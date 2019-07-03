CC = gcc
CFLAGS = -Weverything -Wall -Werror -Wextra
DFLAGS = -Weverything -Wall -Werror -Wextra -g3 -fsanitize=address

NAME = checker

SRCS_NAME = main.c
SRCS_PATH = srcs/

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))

OBJS_PATH = objs/
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_NAME))

LIB_PATH = ../libft/

LIB = $(LIB_PATH)libft.a

all : $(NAME) $(LIB)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)

$(OBJS) : $(SRCS)
	@mkdir -p $(OBJS_PATH)
	$(CC) $(CFLAGS) -c $(SRCS)
	@mv $(OBJS_NAME) $(OBJS_PATH)

clean :
	@rm -rf $(OBJS_PATH)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
