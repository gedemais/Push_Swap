/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:40:43 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/07 11:13:30 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_env	*ft_case_two(t_env *env, char stack)
{
	if (stack == 'a')
	{
		env = ft_ss(env, 'a');
		env = ft_ra(env);
		ft_op_buff("sa\nra", 0);
	}
	else
	{
		env = ft_ss(env, 'b');
		env = ft_rb(env);
		ft_op_buff("sb\nrb", 0);
	}
	return (env);
}

t_env	*ft_three_sort(t_env *env, char stack)
{
	int		a;
	int		b;
	int		c;

	a = (stack == 'a') ? env->a->val : env->b->val;
	b = (stack == 'a') ? env->a->next->val : env->b->next->val;
	c = (stack == 'a') ? env->a->next->next->val : env->b->next->next->val;
	if (a < b && b < c && a < c)
		return (env);
	else if (a < b && b > c && a < c) // 2
		env = ft_case_two(env, stack);
	else if (a < b && b > c && a > c) // 3
	{
		env = (stack == 'a') ? ft_rra(env) : ft_rrb(env);
		ft_op_buff((stack == 'a') ? "rra" : "rrb", 0);
	}
	else if (a > b && b < c && a < c)
	{
		env = ft_ss(env, stack);
		ft_op_buff((stack == 'a') ? "sa" : "sb", 0);
	}
	else if (a > b && b > c && a > c)
	{
		env = ft_ss(env, stack);
		env = (stack == 'a') ? ft_rra(env) : ft_rrb(env);
		ft_op_buff((stack == 'a') ? "sa\nrra" : "sb\nrrb", 0);
	}
	else if (a > b && b < c && a > c)
	{
		env = (stack == 'a') ? ft_ra(env) : ft_rb(env);
		ft_op_buff((stack == 'a') ? "ra" : "rb", 0);
	}
	return (env);
}
