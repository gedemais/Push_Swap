#include "../includes/push_swap.h"

static inline  int	get_smallest(t_stack *stack, unsigned int size)
{
	t_stack		*tmp;
	unsigned int	i;
	int		smallest;

	i = 0;
	smallest = INT_MAX;
	tmp = stack;
	while (tmp && i < size)
	{
		if (smallest > tmp->val)
			smallest = tmp->val;
		i++;
	}
	return (smallest);
}

static inline  int	get_biggest(t_stack *stack, unsigned int size)
{
	t_stack		*tmp;
	unsigned int	i;
	int		biggest;

	i = 0;
	biggest = INT_MIN;
	tmp = stack;
	while (tmp && i < size)
	{
		if (biggest < tmp->val)
			biggest = tmp->val;
		i++;
	}
	return (biggest);
}

static inline void	sort_a_end(t_stack *a, unsigned int size)
{
	t_stack		*tmp;
	unsigned int	i;

	tmp = a;

}

void			sort_ends(t_env *env)
{

}
