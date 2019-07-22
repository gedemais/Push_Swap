/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 07:29:57 by gedemais          #+#    #+#             */
/*   Updated: 2019/07/22 00:31:34 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static inline void	two_sort(t_env *env, char s)
{
	if (env->a->next && env->a->val > env->a->next->val && s == 'a')
	{
		swap_a(env);
		moves_buffer("sa\n", 0);
	}
	if (env->b->next && env->b->val < env->b->next->val && s == 'b')
	{
		swap_b(env);
		moves_buffer("sb\n", 0);
	}
}

static inline int	rollback(t_env *env, unsigned int nb_push, char s)
{
	unsigned int	i;

	i = 0;
	while (i < nb_push)
	{
		if (s == 'a')
		{
			push_b(env);
			moves_buffer("pb\n", 0);
		}
		else
		{
			push_a(env);
			moves_buffer("pa\n", 0);
		}
		i++;
	}
	return (0);
}

static inline void	replace_stack(t_env *env, unsigned int size, char s)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		s == 'a' ? reverse_rotate_a(env) : reverse_rotate_b(env);
		moves_buffer(s == 'a' ? "rra\n" : "rrb\n", 0);
		i++;
	}
}

static inline int	qsorting(t_env *env, unsigned int size, char s)
{
	unsigned int	nb_push;
	unsigned int	nb_rot;

	nb_rot = 0;
	nb_push = 0;
	if (size > 2)
	{
		nb_push = (s == 'a') ? partition_a(env, size, &nb_rot)
			: partition_b(env, size, &nb_rot);
		replace_stack(env, nb_rot, s);
		qsorting(env, size - nb_push, s);
		s = (s == 'a') ? 'b' : 'a';
		qsorting(env, nb_push, s);
	}
	if (size == 2)
		two_sort(env, s);
	rollback(env, nb_push, s);
	return (0);
}

int					quicksort(t_env *env)
{
	if (qsorting(env, env->size_a, env->stack) == -1)
		return (-1);
	return (0);
}
