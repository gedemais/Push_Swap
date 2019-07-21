/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_push_swap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 07:28:59 by gedemais          #+#    #+#             */
/*   Updated: 2019/07/21 23:11:20 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_a(t_env *env)
{
	t_stack	*tmp;

	if (env->b == NULL)
		return ;
	tmp = env->b;
	env->b = env->b->next;
	tmp->next = env->a;
	env->a = tmp;
}

void	push_b(t_env *env)
{
	t_stack	*tmp;

	if (env->a == NULL)
		return ;
	tmp = env->a;
	env->a = env->a->next;
	tmp->next = env->b;
	env->b = tmp;
}

void	swap_a(t_env *env)
{
	t_stack	*tmp;

	if (env->a == NULL || env->a->next == NULL)
		return ;
	tmp = env->a;
	env->a = env->a->next;
	tmp->next = env->a->next;
	env->a->next = tmp;
}

void	swap_b(t_env *env)
{
	t_stack	*tmp;

	if (env->b == NULL || env->b->next == NULL)
		return ;
	tmp = env->b;
	env->b = env->b->next;
	tmp->next = env->b->next;
	env->b->next = tmp;
}

void	swap_s(t_env *env)
{
	swap_a(env);
	swap_b(env);
}
