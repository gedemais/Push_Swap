/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:51:25 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/15 18:45:09 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_ps_lstlen(t_stack *stack)
{
	t_stack		*tmp;
	int			ret;

	ret = 0;
	tmp = stack;
	while (tmp)
	{
		ret++;
		tmp = tmp->next;
	}
	return (ret);
}

void	ft_print_stacks(t_env *env)
{
	t_stack		*tmp;

	tmp = env->a;
	if (tmp == NULL)
		ft_putstr("A empty\n");
	else
	{
		ft_putstr("A (");
		ft_putnbr(ft_ps_lstlen(env->a));
		ft_putstr(")\n");
	}
	while (tmp)
	{
		ft_putnbr(tmp->val);
		ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putchar('\n');
	tmp = env->b;
	if (tmp == NULL)
		ft_putstr("B empty\n");
	else
	{
		ft_putstr("B (");
		ft_putnbr(ft_ps_lstlen(env->b));
		ft_putstr(")\n");
	}
	while (tmp)
	{
		ft_putnbr(tmp->val);
		ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putchar('\n');
	ft_putchar('\n');
}

int		ft_is_stack_sorted(t_stack *stack)
{
	t_stack		*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int 	ft_is_sorted(t_env *env)
{
	if (env->b != NULL)
		return (0);
	else if (ft_is_stack_sorted(env->a) == 0)
		return (0);
	return (1);
}

void	ft_ps_lstdel(t_stack *stack)
{
	if (stack && stack->next)
		ft_ps_lstdel(stack->next);
	if (stack)
		free(stack);
}
