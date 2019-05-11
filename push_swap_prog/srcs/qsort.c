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

t_env	*ft_qsort(t_env *env, char stack, int size)
{
	(void)stack;
	(void)size;
	return (env);
}
