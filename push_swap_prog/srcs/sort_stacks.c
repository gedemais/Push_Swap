#include "../includes/push_swap.h"

int	sort_stacks(t_env *env, int algo)
{
	static unsigned int	algos[NB_ALGOS] = {A_SELECTION, A_QUICKSORT, A_THREESORT};
	static int		(*sort_fts[NB_ALGOS])(t_env*) = {selection_sort, quicksort, three_sort_a};
	unsigned int	i = 0;

	env->size_a = ps_lstlen(env->a);
	env->size_b = 0;
	env->stack = 'a';
	while (i < NB_ALGOS)
	{
		if (algo == (int)algos[i])
			(*sort_fts[i])(env);
		i++;
	}
//	moves_buffer(NULL, 1);
//	print_lst(env);
	return (0);
}
