/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 07:30:01 by gedemais          #+#    #+#             */
/*   Updated: 2019/07/21 07:30:03 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static inline unsigned int	get_smallest(t_stack *stack)
{
	t_stack		*tmp;
	int		smallest;
	unsigned int	ret;
	unsigned int	i;

	smallest = stack->val;
	tmp = stack;
	ret = 0;
	i = 0;
	while (tmp)
	{
		if (tmp->val < smallest)
		{
			smallest = tmp->val;
			ret = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (ret);
}

static inline int	push_smallest_on_b(t_env *env)
{
	unsigned int	len;
	unsigned int	index;

	len = ps_lstlen(env->a);
	index = get_smallest(env->a);
	if (index < (len / 2))
		while (index > 0)
		{
			moves_buffer("ra\n", 0);
			rotate_a(env);
			index--;
		}
	else
		while (index < len)
		{
			moves_buffer("rra\n", 0);
			reverse_rotate_a(env);
			index++;
		}
	moves_buffer("pb\n", 0);
	push_b(env);
	return (0);
}

int	selection_sort(t_env *env)
{
	while (ps_lstlen(env->a) > 3)
		push_smallest_on_b(env);
	three_sort_a(env);
	while (env->b)
	{
		push_a(env);
		moves_buffer("pa\n", 0);
	}
	return (0);
}
