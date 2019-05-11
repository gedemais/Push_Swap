/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:25:41 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/11 20:13:03 by gedemais         ###   ########.fr       */
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

t_env	*ft_partition(t_stack *stack, int size)
{
	int		pivot;


}

t_env	*ft_qsort(t_env *env, char size, int stack)
{
	if (!(env = ft_partition((stack == 'a') ? env->a : env->b, size)))
		return (NULL);
	if (size < 2)
	{
		env = ft_qsort(env, env->alen, stack);
		env = ft_qsort(env, env->blen, stack);
	}
	return (env);
}
