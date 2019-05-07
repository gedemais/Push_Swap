/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 17:51:25 by gedemais          #+#    #+#             */
/*   Updated: 2019/04/30 15:17:06 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_print_stacks(t_env *env)
{
	t_stack		*tmp;

	tmp = env->a;
	if (tmp == NULL)
		ft_putstr("A empty\n");
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
	while (tmp)
	{
		ft_putnbr(tmp->val);
		ft_putchar(' ');
		tmp = tmp->next;
	}
	ft_putchar('\n');
	ft_putchar('\n');
}

int		ft_is_sorted(t_env *env)
{
	t_stack		*tmp;

	tmp = env->a;
	if (env->b != NULL)
		return (0);
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_ps_lstdel(t_stack *stack)
{
	if (stack->next)
		ft_ps_lstdel(stack->next);
	free(stack);
}