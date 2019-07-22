/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:17:05 by gedemais          #+#    #+#             */
/*   Updated: 2019/07/22 00:30:00 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int				find_closest_node(t_env *env, unsigned int size, char s,
				float target)
{
	t_stack				*tmp;
	unsigned int		i;
	float				diff;
	float				best_diff;
	int					ret;

	i = 0;
	best_diff = UINT_MAX;
	tmp = (s == 'a') ? env->a : env->b;
	ret = tmp->val;
	while (tmp && i < size)
	{
		diff = (float)(target - (float)tmp->val);
		diff *= (diff > 0 ? 1 : -1);
		if (diff < best_diff)
		{
			best_diff = diff;
			ret = tmp->val;
		}
		tmp = tmp->next;
		i++;
	}
	return (ret);
}

int				get_median(t_env *env, unsigned int size, char s)
{
	t_stack		*tmp;
	float		average;
	int			i;

	i = 0;
	average = 0;
	tmp = (s == 'a') ? env->a : env->b;
	while (tmp && i < (int)size)
	{
		average += tmp->val;
		tmp = tmp->next;
		i++;
	}
	average /= i;
	return (find_closest_node(env, size, s, average));
}

unsigned int	check_values(t_stack *stack, int median, char s)
{
	t_stack		*tmp;

	tmp = stack;
	while (tmp)
	{
		if (s == 'a' && tmp->val < median)
			return (1);
		else if (s == 'b' && tmp->val > median)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

unsigned int	partition_a(t_env *env, unsigned int size, unsigned int *nb_rot)
{
	int				median;
	unsigned int	ret;

	ret = 0;
	median = get_median(env, size, 'a');
	while (check_values(env->a, median, 'a'))
		if (env->a->val <= median)
		{
			push_b(env);
			moves_buffer("pb\n", 0);
			ret++;
			continue ;
		}
		else
		{
			rotate_a(env);
			moves_buffer("ra\n", 0);
			(*nb_rot)++;
		}
	return (ret);
}

unsigned int	partition_b(t_env *env, unsigned int size, unsigned int *nb_rot)
{
	int				median;
	unsigned int	ret;

	ret = 0;
	median = get_median(env, size, 'b');
	while (check_values(env->b, median, 'b'))
		if (env->b->val >= median)
		{
			push_a(env);
			moves_buffer("pa\n", 0);
			ret++;
			continue ;
		}
		else
		{
			rotate_b(env);
			moves_buffer("rb\n", 0);
			(*nb_rot)++;
		}
	return (ret);
}
