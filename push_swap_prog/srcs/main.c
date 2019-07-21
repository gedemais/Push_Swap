#include "../includes/push_swap.h"

static inline int	choose_sort_algo(int len)
{
	if (len <= 3)
		return (A_THREESORT);
	else if (len <= 20)
		return (A_SELECTION);
	else
		return (A_QUICKSORT);
}

static inline int	push_swap(int argc, char **argv)
{
	long long int	*stack;
	t_env		env;
	int		algo;
	int		len;

	algo = 0;
	if (!(stack = parsing(argc, argv, &len)))
		return (-1);
	if (init_stack(&env, stack, len) == -1)
		return (-1);
	free(stack);
	if ((algo += choose_sort_algo(len)) == -1)
		return (-1);
	if (sort_stacks(&env, algo) == -1)
		return (-1);
	return (0);
}

int			main(int argc, char **argv)
{
	int	ret;

	if (argc < 2)
		return (0);
	if ((ret = push_swap(argc, argv)) == -1)
	{
		ft_putendl_fd("Error", STDERR_FILENO);
		return (1);
	}
	return (0);
}
