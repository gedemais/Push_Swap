#include "../includes/push_swap.h"

void			print_lst(t_env *env)
{
	t_stack		*tmp;

	ft_putstr("A :");
	if (env->a)
	{
		tmp = env->a;
		while (tmp)
		{
			ft_putnbr(tmp->val);
			ft_putchar(' ');
			tmp = tmp->next;
		}
	}
	else
		ft_putstr("Empty\n");
	ft_putchar('\n');
	ft_putstr("B :");
	if (env->b)
	{
		tmp = env->b;
		while (tmp)
		{
			ft_putnbr(tmp->val);
			ft_putchar(' ');
			tmp = tmp->next;
		}
	}
	else
		ft_putstr("Empty\n");
	ft_putchar('\n');
	ft_putchar('\n');
}

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
