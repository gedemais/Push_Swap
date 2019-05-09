/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:25:41 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/09 12:24:35 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_guess_pivot(t_stack *stack)
{
	int		*tab;
	int		len;
	int		ret;

	len = 0;
	if (!stack)
		return (0);
	if (!(tab = ft_get_tab(stack, &len)))
		return (stack->val);
	tab = ft_sort_tab(tab, len);
	ret = tab[len / 2];
	free(tab);
	return (ret);
}

t_env	*ft_partition(t_env *env, char stack)
{
	t_stack	*tmp;
	int		pivot;

	tmp = (stack == 'a') ? env->a : env->b;
	pivot = ft_guess_pivot((stack == 'a') ? env->a : env->b);
	while (tmp)
	{
		if (tmp->val > pivot)
		{
			env = (stack == 'a') ? ft_push_b(env, tmp->val) : ft_push_a(env, tmp->val);
			tmp = (stack == 'a') ? env->a : env->b;
		}
		tmp = tmp->next;
	}
	return (env);
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
