/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:44:42 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/13 15:00:26 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			*speed(void)
{
	static int	val = 0;

	return (&val);
}

void		ft_free_stacks(t_env *env)
{
	ft_ps_lstdel(env->a);
	ft_ps_lstdel(env->b);
}

int		ft_push_swap(t_env *env, int argc, char **argv)
{
	if (!(env = ft_parsing(env, argc, argv)))
		return (-1);
	if (!(env = ft_init_stack(env)))
		return (-1);
	if (ft_is_sorted(env) == 1)
	{
		ft_free_stacks(env);
		return (0);
	}
	if (!(env = ft_qsort(env, 'a', env->alen)))
	{
		ft_free_stacks(env);
		return (-1);
	}
	ft_print_stacks(env);
	ft_free_stacks(env);
	ft_op_buff(NULL, 1);
	return (1);
}

int		main(int argc, char **argv)
{
	t_env	env;
	int 	ret;

	if (argc == 1)
		return (0);
	ret = ft_push_swap(&env, argc, argv);
	if (ret == -1)
	{
		ft_putstr_fd("Error\n", 2);
		free(env.suit);
		return (1);
	}
	free(env.suit);
	return (0);
}
