/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 11:17:03 by gedemais          #+#    #+#             */
/*   Updated: 2019/05/15 19:45:42 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_find_smallest(t_env *env, char stack)
{
	t_stack	*tmp;
	int		best;

	tmp = (stack == 'a') ? env->a : env->b;
	best = (stack == 'a') ? env->a->val : env->b->val;
	while (tmp)
	{
		if (tmp->val < best)
			best = tmp->val;
		tmp = tmp->next;
	}
	return (best);
}

int		*ft_sort_tab(int *tab, int len)
{
	int		i;
	int		j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - 1)
		{
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
	return (tab);
}

int		*ft_make_tab(t_env *env)
{
	t_stack	*tmp;
	int		*tab;
	int		i;

	i = 0;
	tmp = env->a;
	if (!(tab = (int*)malloc(sizeof(int) * env->alen)))
		return (NULL);
	while (tmp)
	{
		tab[i] = tmp->val;
		tmp = tmp->next;
		i++;
	}
	return (tab);
}

t_env	*ft_sstart(t_env *env)
{
	int		*tab;

	if (!(tab = ft_make_tab(env)))
		return (NULL);
	tab = ft_sort_tab(tab, env->alen);
	while (env->a->next->next->next)
	{
	ft_print_stacks(env);
	usleep(100000);
		if (env->a->val != tab[env->alen - 1] && env->a->val != tab[env->alen - 2] && env->a->val != tab[env->alen - 3])
		{
			env = ft_pb(env);
			ft_op_buff("pb", 0);
		}
		else
		{
			env = ft_ra(env);
			ft_op_buff("ra", 0);
		}
	}
	return (env);
}

t_env	*ft_ssort(t_env *env)
{
	int		i;

	i = 0;
	while (env->alen > 3)
	{
		if (!(env = ft_push_on_b(env, ft_find_smallest(env, 'a'))))
			return (NULL);
	}
	if (!(env = ft_three_sort_a(env, 'a')))
		return (NULL);
	while (env->b)
	{
		if (!(env = ft_pa(env)))
			return (NULL);
		ft_op_buff("pa", 0);
	}
	return (env);
}
