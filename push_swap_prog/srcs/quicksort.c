#include "../includes/push_swap.h"

static inline int	find_closest_node(t_stack *stack, int target)
{
	t_stack		*tmp;
	int		best;
	int		diff;

	tmp = stack;
	best = ft_abs(target - tmp->val);
	while (tmp)
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

static inline int	get_median_val(t_stack *stack)
{
	t_stack		*tmp;
	unsigned int	i;
	int		middle;

	i = 0;
	middle = 0;
	tmp = stack;
	while (tmp)
	{
		middle += tmp->val;
		tmp = tmp->next;
		i++;
	}
	return (find_closest_node(stack, middle / (int)i));
}

static inline unsigned int	partition(t_env *env, char stack)
{
	t_stack		*tmp;
	int		median;
	unsigned int	ret;


	median = get_median_val((stack == 'a') ? env->a : env->b);
	printf("median = %u\n", median);
	tmp = (stack == 'a') ? env->a : env->b;
	ret = 0;
	while (tmp)
	{
		if (stack == 'a')
		{
			if (tmp->val < median)
			{
				if ((stack == 'a' ? push_on_b(env, tmp->val) : push_on_a(env, tmp->val)) != 0)
					return (1);
				ret++;
				tmp = (stack == 'a') ? env->a : env->b;
				continue ;
			}
		}
		else if (tmp->val > median)
		{
			if ((stack == 'a' ? push_on_b(env, tmp->val) : push_on_a(env, tmp->val)) != 0)
				return (1);
			ret++;
			tmp = (stack == 'a') ? env->a : env->b;
			continue ;
		}
		
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
		env->size = ps_lstlen(env->stack == 'a' ? env->a : env->b) - nb_push - 1;
		quicksort(env);
	}
	if (env->stack == 'a')
	{
		if (env->size == 3)
			three_sort_a(env);
		else if (env->size == 2 && env->a->val > env->a->next->val)
		{
			moves_buffer("sa\n", 0);
			swap_a(env);
		}
		while (env->size > 0)
		{
			moves_buffer("pa\n", 0);
			push_a(env);
			env->size--;
		}
	}
	else if (env->stack == 'b')
	{
		if (env->size == 3)
			three_sort_b(env);
		else if (env->size == 2 && env->a->val > env->a->next->val)
		{
			moves_buffer("sb\n", 0);
			swap_b(env);
		}
		while (env->size > 0)
		{
			moves_buffer("pb\n", 0);
			push_b(env);
			env->size--;
		}
	}
	return (0);
}
