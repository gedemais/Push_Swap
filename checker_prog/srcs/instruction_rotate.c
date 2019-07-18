/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 04:47:08 by gedemais          #+#    #+#             */
/*   Updated: 2019/07/18 05:03:45 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	rotate_a(t_env *env)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (env->a == NULL || env->a->next == NULL)
		return ;
	tmp = env->a;
	env->a = env->a->next;
	tmp2 = env->a;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
}

void	rotate_b(t_env *env)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (env->b == NULL || env->b->next == NULL)
		return ;
	tmp = env->b;
	env->b = env->b->next;
	tmp2 = env->b;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
}

void	rotate_s(t_env *env)
{
	rotate_a(env);
	rotate_b(env);
}
