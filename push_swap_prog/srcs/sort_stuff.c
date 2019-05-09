/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 12:27:01 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/09 12:27:36 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_get_index(t_stack *stack, int val)
{
	t_stack	*tmp;
	int		ret;

	ret = 0;
	tmp = stack;
	while (tmp && tmp->val != val)
	{
		ret++;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (-1);
	return (ret);
}

t_env	*ft_push_b(t_env *env, int val)
{
	int		index;
	int		len;

	index = ft_get_index(env->a, val);
	len = ft_ps_lstlen(env->a);
	if (index < len / 2)
		while (env->a->val != val)
		{
			env = ft_ra(env);
			ft_op_buff("ra", 0);
		}
	else
		while (env->a->val != val)
		{
			env = ft_rra(env);
			ft_op_buff("rra", 0);
		}
	env = ft_pb(env);
	ft_op_buff("pb", 0);
	return (env);
}

t_env	*ft_push_a(t_env *env, int val)
{
	int		index;
	int		len;

	index = ft_get_index(env->b, val);
	len = ft_ps_lstlen(env->b);
	if (index < len / 2)
		while (env->b->val != val)
		{
			PUT
			env = ft_rb(env); ft_op_buff("rb", 0);
		}
	else
		while (env->b->val != val)
		{
			env = ft_rrb(env);
			ft_op_buff("rrb", 0);
		}
	env = ft_pa(env);
	ft_op_buff("pa", 0);
	return (env);
}
