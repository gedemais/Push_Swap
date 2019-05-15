/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:25:41 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/15 19:48:35 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long long int	ft_guess_pivot(t_stack *stack)
{
	int		*tab;
	int		len;
	int		ret;

	len = 0;
	if (!stack)
		return (LONG_MAX);
	if (!(tab = ft_get_tab(stack, &len)))
		return (stack->val);
	tab = ft_sort_tab(tab, len);
	ret = tab[len / 2];
	free(tab);
	return (ret);
}

t_env			*ft_rollback(t_env *env, char stack)
{
	int		i = 0;

	while (i < env->plen)
	{
		env = (stack == 'a') ? ft_pa(env) : ft_pb(env);
		ft_op_buff((stack == 'a') ? "pa" : "pb", 0);
		i++;
	}
	return (env);
}

t_env			*ft_qsort(t_env *env, char stack, int size)
{
	(void)env;
	(void)stack;
	(void)size;

	return (env);
}
