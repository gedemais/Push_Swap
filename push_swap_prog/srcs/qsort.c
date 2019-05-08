/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:25:41 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/08 18:03:58 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_env	*ft_partition(t_env *env, char stack)
{
	t_stack	*tmp;
	int		pivot;

	tmp = (stack == 'a') ? env->a : env->b;
//	pivot = ft_guess_pivot((stack == 'a') ? env->a : env->b);
	while (tmp)
	{
		if (tmp->val > pivot)
		{
			env = (stack == 'a') ? ft_push_b(env) : ft_push_a(env);
			tmp = (stack == 'a') ? env->a : env->b;
		}
		tmp = tmp->next;
	}
}

t_env	*ft_qsort(t_env *env, char stack, int size)
{
	static int	calls = 0;
	ft_print_stacks(env);

	printf("Call %d : A(%d), B(%d)\n", calls, env->alen, env->blen);
	calls++;
	env = ft_partition(env, stack);
	if (size > 2)
	{
		env = ft_qsort(env, 'a', env->alen);
		env = ft_qsort(env, 'b', env->blen);
	}
	return (env);
}
