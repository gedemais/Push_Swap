#include "../includes/push_swap.h"

static inline void	two_sort(t_env *env)
{
	if (env->a->val > env->a->next->val)
	{
		swap_a(env);
		moves_buffer("sa\n", 0);
	}
}

int			sort_stacks(t_env *env, int algo)
{
	static unsigned int	algos[NB_ALGOS] = {A_SELECTION, A_QUICKSORT,
					A_THREESORT};
	static int		(*sort_fts[NB_ALGOS])(t_env*) = {selection_sort, quicksort,
					three_sort_a};
	unsigned int		i = 0;

	env->size_a = ps_lstlen(env->a);
	env->size_b = 0;
	env->stack = 'a';
	if (env->size_a == 2)
		two_sort(env);
	else
		while (i < NB_ALGOS)
		{
				if (algo == (int)algos[i])
				(*sort_fts[i])(env);
			i++;
		}
	free_stacks(env);
	moves_buffer(NULL, 1);
	return (0);
}
