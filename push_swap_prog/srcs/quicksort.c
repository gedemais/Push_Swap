#include "../includes/push_swap.h"

static inline int	partition(t_env *env, char stack)
{
	t_stack		*tmp;
	unsigned int	median;

	tmp = (stack == 'a') ? env->a : env->b;
	while (tmp)
	{

		tmp = tmp->next;
	}
	return (0);
}

int	quicksort(t_env *env, unsigned int size, char stack)
{
	(void)env;
	if (size > 3)
	{
		partition(env, 'a');
		partition(env, 'b');
	}
	else

	return (0);
}
