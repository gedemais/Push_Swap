/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 05:05:29 by gedemais          #+#    #+#             */
/*   Updated: 2019/07/18 06:30:29 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void			print_lst(t_env *env)
{
	t_stack		*tmp;

	ft_putstr("A :");
	if (env->a)
	{
		tmp = env->a;
		while (tmp)
		{
			ft_putnbr(tmp->val);
			ft_putchar(' ');
			tmp = tmp->next;
		}
	}
	else
		ft_putstr("Empty\n");
	ft_putchar('\n');
	ft_putstr("B :");
	if (env->b)
	{
		tmp = env->b;
		while (tmp)
		{
			ft_putnbr(tmp->val);
			ft_putchar(' ');
			tmp = tmp->next;
		}
	}
	else
		ft_putstr("Empty\n");
	ft_putchar('\n');
}

static inline int			check_stack(t_env *env)
{
	t_stack		*tmp;

	if (!env || env->b)
		return (-1);
	tmp = env->a;
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

static inline int	checker(int argc, char **argv)
{
	long long int	*stack;
	t_env		env;
	int		len;

	if (!(stack = parsing(argc, argv, &len)))
		return (-1);
	if (init_stack(&env, stack, len) == -1)
		return (-1);
	free(stack);
	if (run_instructions(&env) == -1)
		return (-1);
	if (check_stack(&env) == -1)
	{
		free_stacks(&env);
		return (1);
	}
	free_stacks(&env);
	return (0);
}

int			main(int argc, char **argv)
{
	int	ret;

	ret = checker(argc, argv);
	if (ret == -1)
		ft_putendl_fd("Error", STDERR_FILENO);
	else if (ret == 1)
		ft_putendl_fd("KO", 2);
	else if (ret == 0)
	{
		ft_putendl("OK");
		return (0);
	}
	return (1);
}
