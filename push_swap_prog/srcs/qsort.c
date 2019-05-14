/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:25:41 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/14 21:11:13 by gedemais         ###   ########.fr       */
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

t_env			*ft_partition(t_env *env, char stack, int size)
{
	long long int	pivot;
	t_stack			*tmp;
	int				len;

	len = 0;
	env->plen = 0;
	tmp = (stack == 'a') ? env->a : env->b;
	if ((pivot = ft_guess_pivot((stack == 'a') ? env->a : env->b)) == LONG_MAX)
			return (NULL);

	printf("---- Partition on %c ----\n", stack);
	printf("Pivot = %lld\nSize = %d\n", pivot, size);
	ft_print_stacks(env);
	sleep(1);
	while (tmp && len < size)
	{
		if (tmp->val < pivot && stack == 'a')
		{
	ft_print_stacks(env);
	usleep(100000);
			env = ft_push_on_b(env, tmp->val);
			env->plen++;
			tmp = env->a;
			len = 0;
		}
		else if (tmp->val > pivot && stack == 'b')
		{
	ft_print_stacks(env);
	usleep(100000);
			env = ft_push_on_a(env, tmp->val);
			env->plen++;
			tmp = env->b;
			len = 0;
		}
		else
		{
			len++;
			tmp = tmp->next;
		}
	}
	env = (stack == 'a') ? ft_push_on_b(env, pivot) : ft_push_on_a(env, pivot);
	ft_print_stacks(env);
	return (env);
}

t_env			*ft_rollback(t_env *env, char stack)
{
	int		i = 0;

	printf("RollBack\n");
	while (i < env->plen)
	{
	ft_print_stacks(env);
	sleep(1);
		env = (stack == 'a') ? ft_pa(env) : ft_pb(env);
		ft_op_buff((stack == 'a') ? "pa" : "pb", 0);
		i++;
	}
	return (env);
}

t_env			*ft_qsort(t_env *env, char stack, int size)
{
	int		nb;
	printf("---- Quicksort on %c ----\nSize = %d\n", stack, size);
	ft_print_stacks(env);

	if (size < 4)
	{
		printf("End of stack\nSize = %d\n", size);
		if (size == 2)
			env = (stack == 'a') ? ft_two_sort_a(env) : ft_two_sort_b(env);
		else if (size == 3)
			env = (stack == 'a') ? ft_three_sort_a(env, stack) : ft_three_sort_b(env, stack);
		ft_print_stacks(env);
		return (env);
	}
	if (!(env = ft_partition(env, stack, size)))
		return (NULL);
	nb = env->plen;
	if (stack == 'a')
	{
		env = ft_qsort(env, stack, env->alen);
		env = ft_qsort(env, 'b', env->blen - nb);
	}
	else if (stack == 'b')
	{
		env = ft_qsort(env, 'a', env->alen - nb);
		env = ft_qsort(env, stack, env->blen);
	}
//	env = ft_rollback(env, stack);
	return (env);
}
