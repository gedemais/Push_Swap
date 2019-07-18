#include "../includes/push_swap.h"
/*
static inline  int	get_smallest(t_stack *stack, unsigned int size, unsigned int rot)
{
	t_stack		*tmp;
	unsigned int	i;
	unsigned int	len;
	int		smallest;

	i = 0;
	len = ps_lstlen(stack);
	smallest = INT_MAX;
	tmp = stack;
	while (tmp && i < size - rot)
	{
		if (smallest > tmp->val)
			smallest = tmp->val;
		i++;
	}
	while (i < len - rot)
	{
		tmp = tmp->next;
		i++;
	}
	while (tmp)
	{
		if (smallest > tmp->val)
			smallest = tmp->val;
		i++;
	}
	return (smallest);
}

static inline  int	get_biggest(t_stack *stack, unsigned int size, unsigned int rot)
{
	t_stack		*tmp;
	unsigned int	i;
	unsigned int	len;
	int		biggest;

	i = 0;
	len = ps_lstlen(stack);
	biggest = INT_MIN;
	tmp = stack;
	while (tmp && i < size - rot)
	{
		if (biggest < tmp->val)
			biggest = tmp->val;
		i++;
	}
	while (i < len - rot)
	{
		tmp = tmp->next;
		i++;
	}
	while (tmp)
	{
		if (biggest < tmp->val)
			biggest = tmp->val;
		i++;
	}
	return (biggest);
}

static inline void	sort_a_end(t_stack *a, unsigned int size)
{
	unsigned int	rot;
	unsigned int	i;

	rot = 0;
	i = 0;
	while (i < size)
	{
		
		i++;
	}

}

void			sort_ends(t_env *env)
{
	(void)env;
}*/
