/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 13:29:41 by gedemais          #+#    #+#             */
/*   Updated: 2019/04/30 15:14:51 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_env	*ft_free_stacks(t_env *env)
{
	if (env->a)
		ft_ps_lstdel(env->a);
	if (env->b)
		ft_ps_lstdel(env->b);
	return (env);
}

int		ft_checker(t_env *env, int argc, char **argv)
{
	if (!(env = ft_parsing(env, argc, argv)))
		return (-1);
	if (!(env = ft_init_stack(env)))
		return (-1);
	free(env->suit);
	if (ft_apply(env) == -1)
	{
		env = ft_free_stacks(env);
		return (-1);
	}
	if (ft_is_sorted(env) == 1)
	{
		env = ft_free_stacks(env);
		return (0);
	}
	env = ft_free_stacks(env);
	return (1);
}

int		main(int argc, char **argv)
{
	t_env	env;
	int		ret;

	if (argc == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	ret = ft_checker(&env, argc, argv);
	if (ret == 0)
		ft_putstr("OK\n");
	else if (ret == 1)
		ft_putstr("KO\n");
	else
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}
