/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 19:00:42 by gedemais          #+#    #+#             */
/*   Updated: 2019/04/30 11:07:04 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_env	*ft_ra(t_env *env)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (env->a == NULL || env->a->next == NULL)
		return (env);
	tmp = env->a;
	tmp2 = env->a;
	while (tmp2->next)
		tmp2 = tmp2->next;
	env->a = env->a->next;
	tmp->next = NULL;
	tmp2->next = tmp;
	return (env);
}

t_env	*ft_rb(t_env *env)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (env->b == NULL || env->b->next == NULL)
		return (env);
	tmp = env->b;
	tmp2 = env->b;
	while (tmp2->next)
		tmp2 = tmp2->next;
	env->b = env->b->next;
	tmp->next = NULL;
	tmp2->next = tmp;
	return (env);
}

t_env	*ft_rra(t_env *env)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (env->a == NULL || env->a->next == NULL)
		return (env);
	tmp = env->a;
	tmp2 = env->a->next;
	while (tmp2->next)
	{
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	tmp->next = NULL;
	tmp2->next = env->a;
	env->a = tmp2;
	return (env);
}

t_env	*ft_rrb(t_env *env)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (env->b == NULL || env->b->next == NULL)
		return (env);
	tmp = env->b;
	tmp2 = env->b->next;
	while (tmp2->next)
	{
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	tmp->next = NULL;
	tmp2->next = env->b;
	env->b = tmp2;
	return (env);
}

t_env	*ft_rrr(t_env *env)
{
	env = ft_rra(env);
	env = ft_rrb(env);
	return (env);
}
