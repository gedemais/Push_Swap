#include "../includes/push_swap.h"

static inline unsigned int	get_index(t_stack *stack, int val)
{
	unsigned int	i;
	t_stack		*tmp;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		if (tmp->val == val)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int			push_on_b(t_env *env, int val)
{
	unsigned int	len;
	unsigned int	index;

	len = ps_lstlen(env->a);
	index = get_index(env->a, val);
	if (index < (len / 2))
		while (index > 0)
		{
			moves_buffer("ra\n", 0);
			rotate_a(env);
	//print_lst(env);
	//usleep(10000);
			index--;
		}
	else
		while (index < len)
		{
			moves_buffer("rra\n", 0);
			reverse_rotate_a(env);
	//print_lst(env);
	//usleep(10000);
			index++;
		}
	moves_buffer("pb\n", 0);
	push_b(env);
	//print_lst(env);
	//usleep(10000);
	
	return (0);
}

int			push_on_a(t_env *env, int val)
{
	unsigned int	len;
	unsigned int	index;

	len = ps_lstlen(env->b);
	index = get_index(env->b, val);
	if (index < (len / 2))
		while (index > 0)
		{
			moves_buffer("rb\n", 0);
			rotate_b(env);
	//print_lst(env);
	//usleep(10000);
			index--;
		}
	else
		while (index < len)
		{
			moves_buffer("rrb\n", 0);
			reverse_rotate_b(env);
	//print_lst(env);
	//usleep(10000);
			index++;
		}
	moves_buffer("pa\n", 0);
	push_a(env);
	//print_lst(env);
	//usleep(10000);
	return (0);
}
