/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 07:28:48 by gedemais          #+#    #+#             */
/*   Updated: 2019/07/21 07:28:49 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static inline void	case_two(t_env *env, char stack)
{
	moves_buffer((stack == 'a' ? "sa\n" : "sb\n"), 0);
	moves_buffer((stack == 'a' ? "ra\n" : "rb\n"), 0);
	if (stack == 'a')
	{
		swap_a(env);
		rotate_a(env);
	}
	else
	{
		swap_b(env);
		rotate_b(env);
	}
}

static inline void	case_six(t_env *env, char stack)
{
	moves_buffer((stack == 'a' ? "ra\n" : "rb\n"), 0);
	moves_buffer((stack == 'a' ? "sa\n" : "sb\n"), 0);
	if (stack == 'a')
	{
		swap_a(env);
		rotate_a(env);
	}
	else
	{
		swap_b(env);
		rotate_b(env);
	}
}

int	three_sort_a(t_env *env)
{
	int	a;
	int	b;
	int	c;

	if (!env->a->next || !env->a->next->next)
		return (-1);
	a = env->a->val;
	b = env->a->next->val;
	c = env->a->next->next->val;
	if (a < b && b < c && a < c)
		return (0);
	else if (a < b && b > c && a < c)
		case_two(env, 'a');
	else if (a > b && b < c && a < c && moves_buffer("sa\n", 0) == 0)
		swap_a(env);
	else if (a < b && b > c && a > c && moves_buffer("rra\n", 0) == 0)
		reverse_rotate_a(env);
	else if (a > b && b < c && a > c && moves_buffer("ra\n", 0) == 0)
		rotate_a(env);
	else if (a > b && b > c && a > c)
		case_six(env, 'a');
	return (0);
}

int	three_sort_b(t_env *env)
{
	int	a;
	int	b;
	int	c;

	if (!env->b->next || !env->b->next->next)
		return (-1);
	a = env->b->val;
	b = env->b->next->val;
	c = env->b->next->next->val;
	if (a < b && b < c && a < c)
		return (0);
	else if (a < b && b > c && a < c)
		case_two(env, 'b');
	else if (a > b && b < c && a < c && moves_buffer("sb\n", 0) == 0)
		swap_b(env);
	else if (a < b && b > c && a > c && moves_buffer("rrb\n", 0) == 0)
		reverse_rotate_b(env);
	else if (a > b && b < c && a > c && moves_buffer("rb\n", 0) == 0)
		rotate_b(env);
	else if (a > b && b > c && a > c)
		case_six(env, 'b');
	return (0);
}
