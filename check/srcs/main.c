/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 12:56:31 by gedemais          #+#    #+#             */
/*   Updated: 2019/03/30 17:52:33 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_putenv(t_env *env)
{
	if (env->a != NULL)
	{
		ft_putstr("A (");
		ft_putnbr(ft_ps_lstlen(env->a));
		ft_putstr(") :\n");
		ft_putstack(env->a);
		ft_putchar('\n');
	}
	else
		ft_putstr("A is empty\n");
	if (env->b != NULL)
	{
		ft_putstr("B (");
		ft_putnbr(ft_ps_lstlen(env->b));
		ft_putstr(") :\n");
		ft_putstack(env->b);
		ft_putchar('\n');
	}
	else
		ft_putstr("B is empty\n");
	ft_putstr("----------------------\n");
}

int		ft_checker(int argc, char **argv)
{
	t_env	env;
	int		*suit;

	if (!(suit = ft_parsing(argc, argv, &env.a_len)))
		return (-1);
	if (!(env.a = ft_init_a(suit, env.a_len)))
		return (-1);
	if (!(env.b = ft_init_a(suit, env.a_len)))
		return (-1);
	ft_putenv(&env);
//	ft_rb(&env);
	ft_ra(&env);
	ft_putenv(&env);

	if (ft_is_sort(env.a) == 0)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	int		ret;

	if (argc == 1)
	{
		ft_putstr("ERROR\n");
		return (1);
	}
	ret = ft_checker(argc, argv);
	if (ret == 1)
		ft_putstr("OK\n");
	else if (ret == 0)
		ft_putstr("KO\n");
	else
		ft_putstr("ERROR\n");
	return (0);
}
