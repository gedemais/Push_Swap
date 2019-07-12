#include "../includes/push_swap.h"

static inline int		find_closest_node(t_env *env, unsigned int size, char s, int target)
{
	t_stack		*tmp;
	unsigned int	diff;
	unsigned int	best_diff;
	unsigned int	i;
	int		ret;

	i = 0;
	best_diff = UINT_MAX;
	tmp = (s == 'a') ? env->a : env->b;
	ret = tmp->val;
	while (tmp && i < size)
	{
		if (target == tmp->val)
			return (tmp->val);
		diff = (unsigned int)ft_abs(target - tmp->val);
		if (diff < best_diff)
		{
			diff = best_diff;
			ret = tmp->val;
		}
		tmp = tmp->next;
		i++;
	}
	return (ret);
}

static inline int		get_median(t_env *env, unsigned int size, char s)
{
	t_stack		*tmp;
	int		average;
	int		i;

	i = 0;
	average = 0;
	tmp = (s == 'a') ? env->a : env->b;
	while (tmp && i < (int)size)
	{
		average += tmp->val;
		tmp = tmp->next;
		i++;
	}
	average /= i;
	return (find_closest_node(env, size, s, average));
}

static inline unsigned int	check_values(t_stack *stack, int median, char s)
{
	t_stack		*tmp;

	tmp = stack;
	while (tmp)
	{
		if (s == 'a' && tmp->val > median)
			return (1);
		else if (s == 'b' && tmp->val < median)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static inline unsigned int	partition_a(t_env *env, unsigned int size)
{
	int		median;
	unsigned int	ret;
	unsigned int	i;

	i = 0;
	ret = 0;
	median = get_median(env, size, 'a');
	printf("mediane = %d\n", median);
	while (check_values(env->a, median, 'a') && i < size)
	{
		if (env->a->val < median)
		{
			print_lst(env);
			usleep(100000);
			push_b(env);
			moves_buffer("pb\n", 0);
			ret++;
		}
		else
		{
			rotate_a(env);
			moves_buffer("ra\n", 0);
		}
		i++;
	}
	push_on_b(env, median);
	return (ret + 1);
}

static inline unsigned int	partition_b(t_env *env, unsigned int size)
{
	int		median;
	unsigned int	ret;
	unsigned int	i;

	i = 0;
	ret = 0;
	median = get_median(env, size, 'b');
	printf("mediane = %d\n", median);
	while (check_values(env->b, median, 'b') && i < size)
	{
		if (env->b->val > median)
		{
			print_lst(env);
			usleep(100000);
			push_a(env);
			moves_buffer("pa\n", 0);
			ret++;
		}
		else
		{
			rotate_b(env);
			moves_buffer("rb\n", 0);
		}
		i++;
	}
	push_on_a(env, median);
	return (ret + 1);
}

static inline int	rollback(t_env *env, unsigned int nb_push, char s)
{
	unsigned int	i;
	
	i = 0;
	while (i < nb_push)
	{
		if (s == 'a')
		{
			push_b(env);
			moves_buffer("pb\n", 0);
		}
		else
		{
			push_a(env);
			moves_buffer("pa\n", 0);
		}
		i++;
	}
	return (0);
}

static inline int	qsorting(t_env *env, unsigned int size, char s)
{
	unsigned int	nb_push;

	printf("quicksort sur %c\nsize = %d\n", s, size);
	print_lst(env);
	usleep(100000);
	nb_push = 0;
	if (size > 2)
	{
		//Partitioner la stack actuelle
		printf("size > 2 : partition sur %c\n", s);
		nb_push = (s == 'a') ? partition_a(env, size) : partition_b(env, size);

		// Relancer qsort sur la meme stack
		qsorting(env, size - nb_push, s);
		
		// Relancer qsort sur la stack opposee
		s = (s == 'a') ? 'b' : 'a'; // Changement de stack
		qsorting(env, nb_push, s);
	}
	else if (size == 2 && ((s == 'a' && env->a->val > env->a->next->val) || (s == 'b' && env->b->val < env->b->next->val)))
	{
		if (s == 'a')
		{
			swap_a(env);
			moves_buffer("sa\n", 0);
		}
		else
		{
			swap_b(env);
			moves_buffer("sb\n", 0);
		}
	}
	rollback(env, nb_push, s);
	return (0);
}

int	quicksort(t_env *env) // Wrapper around the real quicksort function
{
	if (qsorting(env, env->size_a, env->stack) == -1)
		return (-1);
	return (0);
}
