#include "../includes/push_swap.h"

static inline int		find_closest_node(t_env *env, unsigned int size, char s, float target)
{
	t_stack		*tmp;
	float		diff;
	float		best_diff;
	unsigned int	i;
	int		ret;

	i = 0;
	best_diff = UINT_MAX;
	tmp = (s == 'a') ? env->a : env->b;
	ret = tmp->val;
	while (tmp && i < size)
	{
		diff = (float)(target - (float)tmp->val);
		diff *= (diff > 0 ? 1 : -1);
		if (diff < best_diff)
		{
			best_diff = diff;
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
	float		average;
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
		if (s == 'a' && tmp->val < median)
			return (1);
		else if (s == 'b' && tmp->val > median)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static inline unsigned int	partition_a(t_env *env, unsigned int size, unsigned int *nb_rot)
{
	int		median;
	unsigned int	ret;

	ret = 0;
	median = get_median(env, size, 'a');
	while (check_values(env->a, median, 'a'))
		if (env->a->val <= median)
		{
			push_b(env);
			moves_buffer("pb\n", 0);
			ret++;
			continue ;
		}
		else
		{
			rotate_a(env);
			moves_buffer("ra\n", 0);
			(*nb_rot)++;
		}
	return (ret);
}

static inline unsigned int	partition_b(t_env *env, unsigned int size, unsigned int *nb_rot)
{
	int		median;
	unsigned int	ret;

	ret = 0;
	median = get_median(env, size, 'b');
	while (check_values(env->b, median, 'b'))
		if (env->b->val >= median)
		{
			push_a(env);
			moves_buffer("pa\n", 0);
			ret++;
			continue ;
		}
		else
		{
			rotate_b(env);
			moves_buffer("rb\n", 0);
			(*nb_rot)++;
		}
	return (ret);
}

static inline void	two_sort(t_env *env)
{
	if (env->a->next && env->a->val > env->a->next->val)
	{
		swap_a(env);
		moves_buffer("sa\n", 0);
	}
	if (env->b->next && env->b->val < env->b->next->val)
	{
		swap_b(env);
		moves_buffer("sb\n", 0);
	}
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

static inline void	replace_stack(t_env *env, unsigned int size, char s)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		s == 'a' ? reverse_rotate_a(env) : reverse_rotate_b(env);
		moves_buffer(s == 'a' ? "rra\n" : "rrb\n", 0);
		i++;
	}
}

static inline int			check_stack(t_env *env)
{
	t_stack		*tmp;

	if (!env || env->b)
		return (-1);
	tmp = env->a;
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

static inline int	qsorting(t_env *env, unsigned int size, char s)
{
	unsigned int	nb_push;
	unsigned int	nb_rot;

	nb_rot = 0;
	nb_push = 0;
	if (check_stack(env) == 0)
		return (0);
	if (size > 2)
	{
		nb_push = (s == 'a') ? partition_a(env, size, &nb_rot) : partition_b(env, size, &nb_rot);
		replace_stack(env, nb_rot, s);
		qsorting(env, size - nb_push, s);
		s = (s == 'a') ? 'b' : 'a'; // Changement de stack
		qsorting(env, nb_push, s);
	}
	else if (size == 2)
		two_sort(env);
	rollback(env, nb_push, s);
	return (0);
}

int	quicksort(t_env *env) // Wrapper around the real quicksort function
{
	if (qsorting(env, env->size_a, env->stack) == -1)
		return (-1);
	return (0);
}
