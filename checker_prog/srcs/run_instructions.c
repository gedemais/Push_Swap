#include "../includes/checker.h"

static inline int	run_move(t_env *env, char *line)
{
	unsigned int	i;
	static char	*moves[NB_MOVES] = {"sa", "sb", "ss", "pa", "pb", "ra",
					"rb", "rr", "rra", "rrb", "rrr"};
	static void	(*moves_fts[NB_MOVES])(t_env*) = {swap_a, swap_b,
		swap_s, push_a, push_b, rotate_a, rotate_b, rotate_s,
		reverse_rotate_a, reverse_rotate_b, reverse_rotate_s};
	i = 0;
	while (i < NB_MOVES)
	{
		if (ft_strcmp(line, moves[i]) == 0)
		{
			(*moves_fts[i])(env);
			return (0);
		}
		i++;
	}
	return (-1);
}

int		run_instructions(t_env *env)
{
	char		*line;
	int		ret;

	while ((ret = get_next_line(0, &line)))
	{
		if (ret == -1)
			return (-1);
		if (run_move(env, line) == -1)
		{
			free(line);
			free_stacks(env);
			return (-1);
		}
		free(line);
	}
	return (0);
}
