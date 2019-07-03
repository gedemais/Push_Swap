CK_PATH = checker_prog/

CK_NAME = $(CK_PATH)checker

PS_PATH = push_swap_prog/

PS_NAME = $(PS_PATH)push_swap

LIB_PATH = libft/

LIB = $(LIB_PATH)libft.a

all : $(LIB) $(CK_NAME) $(PS_NAME)

$(LIB) : $(LIB_PATH)
	@make -C $(LIB_PATH)

$(CK_NAME) : $(CK_PATH)
	@make -C $(CK_PATH)

$(PS_NAME) : $(PS_PATH)
	@make -C $(PS_PATH)

clean :
	@make -C $(CK_PATH) clean
	@make -C $(PS_PATH) clean

fclean : clean
	@make -C $(CK_PATH) fclean
	@make -C $(PS_PATH) fclean

re : fclean all
