#include "../includes/push_swap.h"

static inline void	case_two(t_env *env)
{
	moves_buffer("sa\n", 0);
	moves_buffer("ra\n", 0);
	swap_a(env);
	rotate_a(env);
}

static inline void	case_six(t_env *env)
{
	moves_buffer("ra\n", 0);
	moves_buffer("sa\n", 0);
	rotate_a(env);
	swap_a(env);
}

int	three_sort_a(t_env *env)
{
	int	a;
	int	b;
	int	c;

	if (!env->a->next || !env->a->next->next)
		return (-1);
	a = env->a->val;
	b = env->a->next->val;
	c = env->a->next->next->val;
	if (a < b && b < c && a < c)
		return (0);
	else if (a < b && b > c && a < c)
		case_two(env);
	else if (a > b && b < c && a < c)
	{
		moves_buffer("sa\n", 0);
		swap_a(env);
	}
	else if (a < b && b > c && a > c) // rra
	{
		moves_buffer("rra\n", 0);
		reverse_rotate_a(env);
	}
	else if (a > b && b < c && a > c) // ra
	{
		moves_buffer("ra\n", 0);
		rotate_a(env);
	}
	else if (a > b && b > c && a > c) // sa rra
		case_six(env);
	return (0);
}
