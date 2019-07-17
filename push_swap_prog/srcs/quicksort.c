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
		//printf("      | %d\n", tmp->val);
		average += tmp->val;
		tmp = tmp->next;
		i++;
	}
	//printf("Sum = %f\n", (double)average);
	average /= i;
	//printf("Average = %f\n", (double)average);
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

static inline unsigned int	partition_a(t_env *env, unsigned int size)
{
	int		median;
	unsigned int	ret;
	unsigned int	i;

	i = 0;
	ret = 0;
	median = get_median(env, size, 'a');
	//printf("mediane = %d\n", median);
	while (check_values(env->a, median, 'a') && i < size)
	{
		if (env->a->val < median)
		{
			push_b(env);
			moves_buffer("pb\n", 0);
			i = 0;
	//print_lst(env);
	//usleep(10000);
			ret++;
			continue ;
		}
		else
		{
			rotate_a(env);
			moves_buffer("ra\n", 0);
	//print_lst(env);
	//usleep(10000);
		}
		i++;
	}
	push_on_b(env, median);
	//print_lst(env);
	//usleep(10000);
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
	//printf("mediane = %d\n", median);
	while (check_values(env->b, median, 'b') && i < size)
	{
		if (env->b->val > median)
		{
			push_a(env);
			moves_buffer("pa\n", 0);
			size++;
			i = 0;
	//print_lst(env);
	//usleep(10000);
			ret++;
			continue ;
		}
		else
		{
			rotate_b(env);
			moves_buffer("rb\n", 0);
	//print_lst(env);
	//usleep(10000);
		}
		i++;
	}
	push_on_a(env, median);
	//print_lst(env);
	//usleep(10000);
	return (ret + 1);
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
	//printf("Rollback : %u\n", nb_push);
	while (i < nb_push)
	{
		if (s == 'a')
		{
			push_b(env);
			moves_buffer("pb\n", 0);
	//print_lst(env);
	//usleep(10000);
		}
		else
		{
			push_a(env);
			moves_buffer("pa\n", 0);
	//print_lst(env);
	//usleep(10000);
		}
		i++;
	}
	return (0);
}

static inline int	qsorting(t_env *env, unsigned int size, char s)
{
	unsigned int	nb_push;

	//printf("quicksort sur %c\nsize = %d\n", s, size);
	//print_lst(env);
	//usleep(10000);
	nb_push = 0;
	if (size > 3)
	{
		//Partitioner la stack actuelle
	//	printf("size > 2 : partition sur %c\n", s);
	//print_lst(env);
	//usleep(10000);
		nb_push = (s == 'a') ? partition_a(env, size) : partition_b(env, size);

	//print_lst(env);
	//usleep(10000);
		// Relancer qsort sur la meme stack
		qsorting(env, size - nb_push, s);
		
	//print_lst(env);
	//usleep(10000);
		// Relancer qsort sur la stack opposee
		s = (s == 'a') ? 'b' : 'a'; // Changement de stack
		qsorting(env, nb_push + 1, s);
	//print_lst(env);
	//usleep(10000);
	}
	else if (size == 2)
	{
		two_sort(env);
	//print_lst(env);
	//usleep(10000);
	}
	rollback(env, nb_push, s);
	//print_lst(env);
	//usleep(10000);
	return (0);
}

int	quicksort(t_env *env) // Wrapper around the real quicksort function
{
	if (qsorting(env, env->size_a, env->stack) == -1)
		return (-1);
	return (0);
}
