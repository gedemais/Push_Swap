#include "../includes/push_swap.h"

static inline int	find_closest_node(t_stack *stack, int target, int size)
{
	t_stack		*tmp;
	int		best;
	int		diff;
	int		i;

	i = 0;
	tmp = stack;
	best = ft_abs(target - tmp->val);
	while (tmp && i < size)
	{
		if (tmp->val == target)
			return (tmp->val);
		diff = ft_abs(target - tmp->val);
		if (diff < best)
			best = diff;
		tmp = tmp->next;
	}
	return (best);
}

static inline int	get_median_val(t_stack *stack, int size)
{
	t_stack		*tmp;
	unsigned int	i;
	int		middle;

	i = 0;
	middle = 0;
	tmp = stack;
	while (tmp && (int)i < size)
	{
		middle += tmp->val;
		tmp = tmp->next;
		i++;
	}
	return (find_closest_node(stack, middle / (int)i, size));
}

static inline unsigned int	partition(t_env *env, char stack)
{
	t_stack		*tmp;
	int		median;
	unsigned int	ret;
	unsigned int	i;


	median = get_median_val((stack == 'a') ? env->a : env->b, (int)env->size);
	printf("median = %u\n", median);
	tmp = (stack == 'a') ? env->a : env->b;
	ret = 0;
	i = 0;
	while (tmp && i < env->size)
	{
		if (stack == 'a')
		{
			if (tmp->val < median)
			{
				if (push_on_b(env, tmp->val) != 0)
					return (1);
				ret++;
				tmp = (stack == 'a') ? env->a : env->b;
				i = 0;
				continue ;
			}
		}
		else if (stack == 'b')
			if (tmp->val > median)
			{
				if (push_on_a(env, tmp->val) != 0)
					return (1);
				ret++;
				tmp = (stack == 'a') ? env->a : env->b;
				i = 0;
				continue ;
			}
		i++;
		tmp = tmp->next;
	}
	if ((stack == 'a' ? push_on_b(env, median) : push_on_a(env, median)) != 0)
		return (1);
	return (ret);
}

int	quicksort(t_env *env)
{
	unsigned int	nb_push;

	printf("stack = %c\nsize = %d\n\n", env->stack, env->size);
	print_lst(env);
	sleep(1);
	printf("\n");
	nb_push = 0;
	if (env->size > 3)
	{
		nb_push = partition(env, env->stack);
		env->size = ps_lstlen(env->stack == 'a' ? env->a : env->b);
		quicksort(env);
		env->stack = (env->stack == 'a' ? 'b' : 'a');
		env->size = ps_lstlen(env->stack == 'a' ? env->a : env->b) - nb_push;
		quicksort(env);
	}
	if (q_three_sort_a(env) != 0)
		return (-1);
	if (env->a->val > env->a->next->val)
	{
		moves_buffer((env->stack == 'a' ? "sa\n" : "sb\n"), 0);
		if (env->stack == 'a')
			swap_a(env);
		else
			swap_b(env);
	}
	while (env->size > 0)
	{
		moves_buffer((env->stack == 'a' ? "pa\n" : "pb\n"), 0);
		if (env->stack == 'a')
			push_a(env);
		else if (env->stack == 'b')
			push_b(env);
		env->size--;
	}
	return (0);
}
