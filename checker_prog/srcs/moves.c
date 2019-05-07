/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gedemais <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:00:30 by gedemais          #+#    #+#             */
/*   Updated: 2019/04/30 15:16:57 by gedemais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_env	*ft_ss(t_env *env, char c)
{
	int		tmp;

	if (c == 'a' || c == ' ')
	{
		if (env->a == NULL || env->a->next == NULL)
			return (env);
		tmp = env->a->val;
		env->a->val = env->a->next->val;
		env->a->next->val = tmp;
	}
	if (c == 'b' || c == ' ')
	{
		if (env->b == NULL || env->b->next == NULL)
			return (env);
		tmp = env->b->val;
		env->b->val = env->b->next->val;
		env->b->next->val = tmp;
	}
	return (env);
}

t_env	*ft_pa(t_env *env)
{
	t_stack	*tmp;

	if (env->b == NULL)
		return (env);
	tmp = env->b;
	env->b = env->b->next;
	tmp->next = env->a;
	env->a = tmp;
	return (env);
}

t_env	*ft_pb(t_env *env)
{
	t_stack	*tmp;

	if (env->a == NULL)
		return (env);
	tmp = env->a;
	env->a = env->a->next;
	tmp->next = env->b;
	env->b = tmp;
	return (env);
}

t_env	*ft_rr(t_env *env)
{
	env = ft_ra(env);
	env = ft_rb(env);
	return (env);
}
