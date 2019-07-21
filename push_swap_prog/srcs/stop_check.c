/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 07:30:36 by gedemais          #+#    #+#             */
/*   Updated: 2019/07/21 07:30:38 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static inline int	is_a_sort(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp->next)
	{
		if (tmp->val > tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static inline int	is_b_sort(t_stack *b)
{
	t_stack	*tmp;

	tmp = b;
	while (tmp->next)
	{
		if (tmp->val < tmp->next->val)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}


int			stop_check(t_env *env)
{
	if (is_a_sort(env->a) == 0)
		return (0);
	if (is_b_sort(env->b) == 0)
		return (0);
	return (1);
}
