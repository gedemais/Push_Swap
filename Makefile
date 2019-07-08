CK_PATH = checker_prog/

CK_NAME = checker

PS_PATH = push_swap_prog/

PS_NAME = push_swap

LIB_PATH = libft/

LIB = $(LIB_PATH)libft.a

all : $(CK_NAME) $(PS_NAME) $(CK_PATH) $(PS_PATH)

$(LIB) : $(LIB_PATH)
	@echo "Making Libft..."
	@make -C $(LIB_PATH)

$(CK_NAME) : $(CK_PATH)
	@echo "Making Checker..."
	@make -C $(CK_PATH) re
	@mv $(CK_PATH)$(CK_NAME) ./

$(PS_NAME) : $(PS_PATH)
	@echo "Making Push_swap..."
	@make -C $(PS_PATH) re
	@mv $(PS_PATH)$(PS_NAME) ./

clean :
	@make -C $(CK_PATH) clean
	@make -C $(PS_PATH) clean

fclean : clean
	@make -C $(CK_PATH) fclean
	@make -C $(PS_PATH) fclean
	@rm -rf $(CK_NAME)
	@rm -rf $(PS_NAME)

re : fclean all
